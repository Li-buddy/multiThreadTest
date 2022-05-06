#pragma once

#include <mutex>
#include <iostream>

namespace testFor_ConditionVariable
{
	std::condition_variable CV;
	std::mutex mtx;
	long balance{0};

	void addMoney(int money) {
		std::lock_guard<std::mutex> lockguard(mtx);
		balance += money;
		std::cout << "add money to current balance" << balance << std::endl;
		CV.notify_one(); //notify the wait 
	}

	void withDrawMoney(int money) {
		std::unique_lock<std::mutex> uniLock(mtx);
		CV.wait(uniLock, [] {return (balance != 0) ? true : false; });//wait for notify
		if (balance > money) {
			balance -= money;
			std::cout << "amount dected : " << money << std::endl;
		}
		else {
			std::cout << "amount can't be detected, current balance is less than" << money << std::endl;
		}
		std::cout << "current balance is : " << balance << std::endl;
	}
}