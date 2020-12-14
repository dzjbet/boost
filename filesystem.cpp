#include<boost/filesystem.hpp>
#include<iostream>
#include<cstring>
using namespace boost::filesystem;
using namespace std;

int main() {

	path path1("D:/01.cpp");  					//文件路径
	path path2("01");   						//目录路径
	cout << path1.string() << endl;    			//返回标准路径
	cout << path1.stem() << endl;      			//返回文件名不带扩展
	cout << path1.extension() << endl;  		//返回扩展名
	cout << path1.parent_path() << endl;  		//返回父路径
	cout << path2.empty() << endl;  			//判断path类的路径字符串是否为空
	cout << path1.filename() << endl; 			//返回文件名带扩展
	cout << path1.root_name() << endl;  		//返回根目录
	cout << path1.relative_path() << endl;  	//返回相对路径
	cout << path2.has_filename() << endl;  		//判断是否具有文件名
	cout << path2.has_parent_path() << endl;  	//判断是否含有父路径
	
	getchar();
	//system("pause");
	return 0;
}