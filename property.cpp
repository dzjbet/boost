#include<iostream>
#include<boost\property_tree\xml_parser.hpp>

using namespace std;
using namespace boost::property_tree;

int main()
{
	ptree pt,pt1,pt2;
	read_xml("aa.xml", pt);
	cout << pt.get<string>("root.students.name") <<'\t'<<pt.get<int>("root.students.age");  //使用get<T>("")获取孩子
	cout << '\n' << "==========" << endl;

	read_xml("bb.xml", pt1);
	auto pt_child=pt1.get_child("root.students");											//使用get_child获取孩子
	for (auto i : pt_child)																	
		cout << i.second.get_value<string>() << '\t';										//获取具体数值i.second.get_value<string>()
	cout << '\n' << "==========" << endl;

	read_xml("cc.xml", pt2);
	for (auto i : pt2.get_child("root.students"))
	{
		auto student = i.second.get_child("");												//使用get_child("")获取全部孩子属性
		for (auto j : student)
		{
			cout << j.second.get<string>("") << endl;										//get<>
			cout << j.second.get<string>("<xmlattr>.name") << '\t' << j.second.get<string>("<xmlattr>.age") << endl;
		}
	}
	getchar();
	return 0;
}