#pragma once
#include <mutex>
#include <iostream>
#include <chrono>

namespace testFor_DeadLock
{
	int buffer = 0;
	std::mutex mtx1;
	std::mutex mtx2;

	//死锁现场
	void thread1() {
		mtx1.lock();
		std::this_thread::sleep_for(std::chrono::seconds(1)); //确保一定会发生死锁
		mtx2.lock();
		std::cout << "critical section of thread 1" << std::endl;
		buffer++;
		mtx1.unlock();
		mtx2.unlock();
	}

	void thread2() {
		mtx2.lock();
		std::this_thread::sleep_for(std::chrono::seconds(1));  //确保一定会发生死锁
		mtx1.lock();
		std::cout << "critical section of thread 2" << std::endl;
		buffer++;
		mtx2.unlock();
		mtx1.unlock();
	}

	//避免死锁的简单做法  保证不同线程中对互斥量的加锁顺序相同
	void thread3() {
		mtx1.lock();
		std::this_thread::sleep_for(std::chrono::seconds(1));  //等待
		mtx2.lock();
		std::cout << "critical section of thread 2" << std::endl;
		buffer++;
		mtx1.unlock();
		mtx2.unlock();
	}

	//或者使用std::lock加锁，这种方式会自动以无死锁的顺序去加锁
	void thread4() {
		std::this_thread::sleep_for(std::chrono::seconds(1));  //等待
		std::lock(mtx1,mtx2);
		std::cout << "critical section of thread 1" << std::endl;
		buffer++;
		mtx1.unlock();
		mtx2.unlock();
	}

	void thread5() {
		std::this_thread::sleep_for(std::chrono::seconds(1));  //等待
		std::lock(mtx1, mtx2);
		std::cout << "critical section of thread 2" << std::endl;
		buffer++;
		mtx2.unlock();
		mtx1.unlock();
	}
	
	//或者尝试使用含有超时检查的加锁操作
	void thread6() {
		mtx1.try_lock();
		std::this_thread::sleep_for(std::chrono::seconds(1)); //确保一定会发生死锁
		mtx2.try_lock();
		std::cout << "critical section of thread 1" << std::endl;
		buffer++;
		mtx1.unlock();
		mtx2.unlock();
	}

	void thread7() {
		bool flag1 = false;
		bool flag2 = false;
		if (mtx2.try_lock())
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));  
			flag1 = true;
			buffer++;
		}
		if (mtx1.try_lock())
		{
			std::cout << "critical section of thread 2" << std::endl;
			flag2 = true;
			buffer++;
		}				
		if (flag2) {
			mtx2.unlock();
		}		
		if (flag1) {
			mtx1.unlock();
		}
	}
}