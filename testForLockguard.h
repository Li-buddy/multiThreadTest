#pragma once

#include <mutex>
#include <iostream>

namespace testForLock_guard {
	std::mutex mtx;
	int buffer = 0;

	void task(const char* threadNumber, int loopFor) {
		std::lock_guard<std::mutex> lockguard(mtx);
		for (int i = 0; i < loopFor; i++) {
			buffer++;
			std::cout << "Thread number : " << buffer << std::endl;
		}
	}
}



