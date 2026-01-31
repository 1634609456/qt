#pragma once

#include <atomic>
#include <chrono>
#include <thread>
#include <vector>

#include "ormpp/dbng.hpp"
#include "ormpp/sqlite.hpp"
#include "readerwriterqueue.h"
#include "thread_pool.hpp"

inline constexpr int thread_pool_size{8};

inline ThreadPool db_thread_pool{thread_pool_size};

template <typename T>
class DBWriter {
    static constexpr size_t QUEUE_CAPACITY = 4096;
    static constexpr size_t BATCH_SIZE = 512;

public:
    DBWriter(const std::string &db) : data_queue_(QUEUE_CAPACITY), running_(true) {
        sqlite_.connect(db);
        sqlite_.create_datatable<T>(ormpp_auto_key{"data_id"});

        try {
            worker_ = std::thread(&DBWriter::_process_loop, this);

        } catch (const std::exception &e) {
            running_ = false;
            throw std::runtime_error(e.what());
        }
    }

    ~DBWriter() {
        try {
            stop();
        } catch (const std::exception &e) {
        }
    }

    DBWriter(const DBWriter &) = delete;
    DBWriter &operator=(const DBWriter &) = delete;

    DBWriter(DBWriter &&) = delete;
    DBWriter &operator=(DBWriter &&) = delete;

    void push(const T &data) {
        if (!running_) {
            return;
        }

        if (!data_queue_.try_enqueue(data)) {
        }
    }

    void stop() {
        if (!running_.exchange(false)) {
            return;
        }

        try {
            if (worker_.joinable()) {
                worker_.join();
            }

        } catch (const std::exception &e) {
            throw std::runtime_error(e.what());
        }
    }

private:
    void _process_loop() {
        while (running_ || data_queue_.size_approx() > 0) {
            T item;

            std::vector<T> batch;
            batch.reserve(BATCH_SIZE);

            while (batch.size() < BATCH_SIZE) {
                if (data_queue_.try_dequeue(item)) {
                    batch.emplace_back(std::move(item));
                }                
                if (!running_ && data_queue_.size_approx() == 0) {
                    break;
                }
                using namespace std::chrono_literals;
                std::this_thread::sleep_for(1us);
            }

            if (!batch.empty()) {
                db_thread_pool.submit([this, batch = std::move(batch)]() {
                    std::lock_guard<std::mutex> lock(db_mutex_);
                    sqlite_.insert<T>(batch);
                });
            }
        }
    }

    ormpp::dbng<ormpp::sqlite> sqlite_;
    std::mutex db_mutex_;
    moodycamel::BlockingReaderWriterQueue<T> data_queue_;
    std::atomic<bool> running_;
    std::thread worker_;
};
