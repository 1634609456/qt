#pragma once

#include <cassert>
#include <mutex>
#include <vector>

#include "../shm_data.hpp"

#include "YKCat2.h"
#include "NoSys.h"

template <typename T>
class RingBuffer {
private:
    T* buffer_;  // 指向环形缓冲区
    mutable std::mutex lock_;

public:
    RingBuffer(T* data) : buffer_(data) {
    }

    ~RingBuffer() = default;

    // 设置缓冲区
    void set_buffer(T* data) {
        std::lock_guard<std::mutex> guard(lock_);
        buffer_ = data;
    }

    // 获取可读数据长度
    int readable_length() {
        std::lock_guard<std::mutex> guard(lock_);
        int length = (buffer_->write_index - buffer_->read_index + MAX_COMMANDS) % MAX_COMMANDS;
        return length;
    }

    // 获取可写数据长度
    int writable_length() {
        std::lock_guard<std::mutex> guard(lock_);
        int length = (buffer_->read_index - buffer_->write_index - 1 + MAX_COMMANDS) % MAX_COMMANDS;
        return length;
    }

    // 推送数据到环形缓冲区
    bool push(const typename T::Type& item) {
        std::lock_guard<std::mutex> guard(lock_);
        size_t next_write_index = (buffer_->write_index + 1) % MAX_COMMANDS;
        if (next_write_index != buffer_->read_index) {
            buffer_->data[buffer_->write_index] = item;
            buffer_->write_index = next_write_index;
            return true;
        }
        return false;
    }

    // 从环形缓冲区读取数据
    bool pop(typename T::Type& item) {
        std::lock_guard<std::mutex> guard(lock_);
        if (buffer_->read_index != buffer_->write_index) {
            item = buffer_->data[buffer_->read_index];
            buffer_->read_index = (buffer_->read_index + 1) % MAX_COMMANDS;
            return true;
        }
        return false;
    }

    std::vector<typename T::Type> pop_all() {
        std::lock_guard<std::mutex> guard(lock_);
        std::vector<typename T::Type> items;
        while (buffer_->read_index != buffer_->write_index) {
            items.push_back(buffer_->data[buffer_->read_index]);
            buffer_->read_index = (buffer_->read_index + 1) % MAX_COMMANDS;
        }
        return items;
    }

    // 判断环形缓冲区是否为空
    bool is_empty() {
        std::lock_guard<std::mutex> guard(lock_);
        return (buffer_->read_index == buffer_->write_index);
    }

    // 判断环形缓冲区是否已满
    bool is_full() {
        std::lock_guard<std::mutex> guard(lock_);
        return ((buffer_->write_index + 1) % MAX_COMMANDS == buffer_->read_index);
    }
};
