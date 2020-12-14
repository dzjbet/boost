#include<iostream>
#include<cstring>
#include<boost/smart_ptr.hpp>
using namespace std;
using namespace boost;
int main()
{
	/*
	scoped_ptr：不可拷贝，承载new。
	scoped_array：不可拷贝，承载new []。
	shared_ptr：可拷贝，承载new。
	shared_array：可拷贝，承载new []。
	weak_ptr：弱引用。
	intrusive_ptr：需要自实现计数功能的，引用计数智能指针
*/
	scoped_ptr<int> a(new int);										//scoped_ptr 指针new的时候放进就行了
	*a = 100;
	cout << *a << endl;
	
	scoped_array<int> a2(new int[10]{1,2,3,4,5,6,7,8,9,10});		//scopted_array数组指针
	for (int i = 0; i < 10; i++)
		cout << a2[i];												//也可使用a2.get()[i]
	cout << endl;

	boost::shared_ptr<int> a3(new int(10));							//shared_ptr指针可以指向多个
	boost::shared_ptr<int> a4 = a3;									//也可a4(a3)
	*a3.get() = 20;
	cout << "a4:" << *a4.get() << '\t' << "a3:" << *a3.get() << endl;
	a3.reset();
	cout << a3.unique() << endl;									//uinque比use_count()快  当a3被reset后get得不到地址
	cout << *a4.get() << endl;

	//boost::shared_array<int> a5(new int[5]{1,2,3,4,5});			//shard_array智能指针
	boost::shared_ptr<int> a5(new int(20));
	cout << "a5_count:" << a5.use_count() << endl;
	boost::weak_ptr<int> a6 = a5;									//weak_ptr智能指针
	cout << "a5_count:" << a5.use_count() << endl;
	cout << a6.expired() << endl;

	system("pause");
	return 0;
}
