#pragma once

#include <atomic>
#include <cassert>
#include <functional>
#include <future>
#include <thread>
#include <vector>

#include "moodycamel/blockingconcurrentqueue.h"

class ThreadPool {
public:
	using Task = std::function<void()>;

	explicit ThreadPool(int thread_count = std::thread::hardware_concurrency())
		: unfinished_tasks_(0) {
		assert(thread_count > 0);
		for (int i = 0; i < thread_count; ++i) {
			workers.emplace_back([this]() {
				Task task;
				for (;;) {
					queue.wait_dequeue(task);
					if (!task) {
						break;
					}

					task();
					unfinished_tasks_.fetch_sub(1, std::memory_order_release);
				}
			});
		}
	}

	~ThreadPool() {
		wait_for_all();

		for (int i = 0; i < workers.size(); ++i) {
			queue.enqueue(nullptr);
		}
		for (auto &t : workers) {
			if (t.joinable()) {
				t.join();
			}
		}
	}

	ThreadPool(const ThreadPool &) = delete;
	ThreadPool &operator=(const ThreadPool &) = delete;

	ThreadPool(ThreadPool &&) = delete;
	ThreadPool &operator=(ThreadPool &&) = delete;

	template <typename F, typename... Args>
	auto submit(F &&f, Args &&...args) -> std::future<std::invoke_result_t<F, Args...>> {
		using ReturnType = std::invoke_result_t<F, Args...>;
		auto taskPtr = std::make_shared<std::packaged_task<ReturnType()>>(
			std::bind(std::forward<F>(f), std::forward<Args>(args)...));

		unfinished_tasks_.fetch_add(1, std::memory_order_acquire);

		queue.enqueue([taskPtr]() { (*taskPtr)(); });

		return taskPtr->get_future();
	}

	void wait_for_all() {
		while (unfinished_tasks_.load(std::memory_order_acquire) != 0) {
			std::this_thread::yield();
		}
	}

private:
	std::vector<std::thread> workers;
	moodycamel::BlockingConcurrentQueue<Task> queue;
	std::atomic<int> unfinished_tasks_;
};
