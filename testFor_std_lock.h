#pragma once
#include <mutex>
#include <iostream>

namespace testFor_std_lock
{
	std::mutex mtx1;
	std::mutex mtx2;

	void task_a() {
		/*while (1)*/ {
			std::lock(mtx1, mtx2);
			std::cout << "task_a\n" << std::endl;
			mtx1.unlock();
			mtx2.unlock();
		}
	}

	void task_b() {
		/*while (1)*/ {
			std::lock(mtx2, mtx1);
			std::cout << "task_b\n" << std::endl;
			mtx2.unlock();
			mtx1.unlock();
		}
	}

	//Ñ§Ï°ÁË½âstd::scoped_lock
}