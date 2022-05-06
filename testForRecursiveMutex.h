#pragma once
#include <iostream>
#include <mutex>

std::recursive_mutex mtx;
int buffer = 0;

namespace testForRecursiveMutex_Recursive 
{	
	void recursion(char c, int loopFor) {
		if (loopFor <= 0) {
			return;
		}
		mtx.lock();
		std::cout << "Locked by thread ID : " << c << " " << loopFor << std::endl;
		recursion(c,--loopFor);
		mtx.unlock();
		std::cout << "Unlocked by thread ID : " << c << std::endl;
	}
}

namespace testForRecursiveMutex_loop
{
	void loop(int times) {
		for (int i = 0; i < times; i++) 
		{
			mtx.lock();
			std::cout << "locked : " << i << std::endl;
			std::cout << "buffer : " << ++buffer << std::endl;
		}

		for (int i = 0; i < times; i++) 
		{
			mtx.unlock();
			std::cout << "Unlocked : " << i << std::endl;
		}
	}
}