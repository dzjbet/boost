#include<iostream>
#include<boost/thread/thread.hpp>
#include<boost\thread\mutex.hpp>
using namespace std;

boost::mutex mu;
int a = 100;
void ad1(int a)
{
	mu.lock();
	a++;
	cout << a << endl;
	mu.unlock();
}

void ad2(int a)
{
	mu.lock();
	a += 10;
	cout << a << endl;
	mu.unlock();
}
void fun();
int main()
{
	//boost::thread th(fun);
	//th.join();								//将th加入到线程队列中
	//cout << "I am main" << endl;
	
	boost::thread th1(&ad1, a);
	boost::thread th2(&ad2, a);
	th1.join();
	th2.join();
	cout << a << endl;

	getchar();
	return 0;
}

void fun()
{
	cout << "I am fun" << endl;
}