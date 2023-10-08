#pragma once
#include <mutex>
#include <chrono>
#include <iostream>

namespace testForTimedMutex{
	int myAccount = 0;
	std::timed_mutex mtx;

	void increment(int i) {
		if (mtx.try_lock_for(std::chrono::seconds(2))) {
			myAccount+=i;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "thread : " << i << std::endl;
			mtx.unlock();       //注意此处释放锁
		}
		else {
			std::cout << "thread : " << i << "couldn't enter" << std::endl;
		}
	}
}

