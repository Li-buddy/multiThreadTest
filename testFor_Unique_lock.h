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
	}//�뿪������ʱ��unique_lock�Զ�����unlock��������unique_lock������
}