// codeForBlog.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <thread>
#include "testForTimedMutex.h"
#include "testForRecursiveMutex.h"
#include "testForLockguard.h"
#include "testFor_Unique_lock.h"
#include "testForCondition_variable.h"
#include "testFor_Deadlock.h"
#include "testFor_std_lock.h"
#include "testFor_future.h"
#include "testFor_async.h"

int main()
{
    //test for timed mutex
   /* std::thread th1(testForTimedMutex::increment, 1);
    std::thread th2(testForTimedMutex::increment, 2);

    th1.join();
    th2.join();

    std::cout << "myAccount : " << testForTimedMutex::myAccount << std::endl;*/

    //test for recursive_mutex
    /*std::thread th3(testForRecursiveMutex_Recursive::recursion, '1', 5);
    std::thread th4(testForRecursiveMutex_Recursive::recursion, '2', 5);*/

    //th3.join();
    //th4.join();
    ////for loop
    //std::thread th5(testForRecursiveMutex_loop::loop, 3);
    //th5.join();

    //test for lock guard
    /*std::thread th6(testForLock_guard::task, "T1", 5);
    std::thread th7(testForLock_guard::task, "T2", 5);
    th6.join();
    th7.join();*/

    //test for unique_lock
    /*std::thread th8(testForUniquelock::task, "T1", 5);
    std::thread th9(testForUniquelock::task, "T2", 6);
    th8.join();
    th9.join();*/

    //test for condition variable
    /*std::thread th10(testFor_ConditionVariable::withDrawMoney, 500);
    std::thread th11(testFor_ConditionVariable::addMoney, 400);*/

    /*std::thread th10(testFor_ConditionVariable::withDrawMoney, 500);
    std::thread th11(testFor_ConditionVariable::addMoney, 650);

    th10.join();
    th11.join();*/

    //test for dead lock phenomenon
    std::thread th12(testFor_DeadLock::thread6);
    std::thread th13(testFor_DeadLock::thread7);

    th12.join();
    th13.join();

    //test for std lock
    /*std::thread th14(testFor_std_lock::task_a);
    std::thread th15(testFor_std_lock::task_b);
    th14.join();
    th15.join();*/

    //test for future
   /* testFor_Future::ull start = 0;
    testFor_Future::ull end = 1900000000;*/

    /*std::promise<testFor_Future::ull> oddsum{};
    std::future<testFor_Future::ull> oddfuture = oddsum.get_future();

    std::cout << "Thread created" << std::endl;
    std::thread th16(testFor_Future::findodd, std::move(oddsum), start, end);
    std::cout << "wait for result" << std::endl;

    std::cout << "oddsum : " << oddfuture.get() << std::endl;
    th16.join();*/

    //比较两种创建线程的策略，deferred更加推迟，当访问时才创建线程；async策略在最初就创建线程
    //std::future<testFor_async::ull> oddSum = std::async(std::launch::async,testFor_async::findOdd,start,end);
    ////std::future<testFor_async::ull> oddSum = std::async(std::launch::deferred, testFor_async::findOdd, start, end);
    //std::cout << "waiting for result" << std::endl;
    //std::this_thread::sleep_for(std::chrono::seconds(4));
    //std::cout << "oddsum : " << oddSum.get() << std::endl;
    //std::cout << "completed" << std::endl;

    system("pause");
}
