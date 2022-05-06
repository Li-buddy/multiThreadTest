#pragma once

#include <mutex>
#include <iostream>

namespace testForUniquelock
{
	std::mutex mtx;
	int buffer = 0;

	void task(const char* threadNumber, int loopFor) {
		std::unique_lock<std::mutex> uniquelock(mtx);
		for (int i = 0; i < loopFor; ++i) {
			buffer++;
			std::cout << "Thread number : " << buffer << std::endl;
		}
	}//离开作用域时，unique_lock自动调用unlock，发生在unique_lock析构中
}