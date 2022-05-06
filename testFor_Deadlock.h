#pragma once
#include <mutex>
#include <iostream>
#include <chrono>

namespace testFor_DeadLock
{
	int buffer = 0;
	std::mutex mtx1;
	std::mutex mtx2;

	//�����ֳ�
	void thread1() {
		mtx1.lock();
		std::this_thread::sleep_for(std::chrono::seconds(1)); //ȷ��һ���ᷢ������
		mtx2.lock();
		std::cout << "critical section of thread 1" << std::endl;
		buffer++;
		mtx1.unlock();
		mtx2.unlock();
	}

	void thread2() {
		mtx2.lock();
		std::this_thread::sleep_for(std::chrono::seconds(1));  //ȷ��һ���ᷢ������
		mtx1.lock();
		std::cout << "critical section of thread 2" << std::endl;
		buffer++;
		mtx2.unlock();
		mtx1.unlock();
	}

	//���������ļ�����  ��֤��ͬ�߳��жԻ������ļ���˳����ͬ
	void thread3() {
		mtx1.lock();
		std::this_thread::sleep_for(std::chrono::seconds(1));  //�ȴ�
		mtx2.lock();
		std::cout << "critical section of thread 2" << std::endl;
		buffer++;
		mtx1.unlock();
		mtx2.unlock();
	}

	//����ʹ��std::lock���������ַ�ʽ���Զ�����������˳��ȥ����
	void thread4() {
		std::this_thread::sleep_for(std::chrono::seconds(1));  //�ȴ�
		std::lock(mtx1,mtx2);
		std::cout << "critical section of thread 1" << std::endl;
		buffer++;
		mtx1.unlock();
		mtx2.unlock();
	}

	void thread5() {
		std::this_thread::sleep_for(std::chrono::seconds(1));  //�ȴ�
		std::lock(mtx1, mtx2);
		std::cout << "critical section of thread 2" << std::endl;
		buffer++;
		mtx2.unlock();
		mtx1.unlock();
	}
	
	//���߳���ʹ�ú��г�ʱ���ļ�������
	void thread6() {
		mtx1.try_lock();
		std::this_thread::sleep_for(std::chrono::seconds(1)); //ȷ��һ���ᷢ������
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