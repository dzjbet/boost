#include<iostream>
#include<boost/algorithm/string.hpp>
#include<boost/format.hpp>
#include<vector>
#define print boost::format
using namespace std;
using namespace boost::algorithm;   //所有字符函数加_copy返回字符串不加则无返回值 i表示忽略大小写 if判断
int main()
{
	string s1 = "hellow";
	cout << s1 << endl;
	to_upper(s1);												    //一、转大写
	cout << "to_upper:" << s1 << endl;
	string s2 = to_upper_copy(s1);									//转大写返回字符串
	to_lower(s1);													//转小写
	cout << "to_lower:"<<s1 << endl;

	cout << erase_all_copy(s1, "lo") <<endl;						//二、删除字符
	cout << erase_first_copy(string("ababab"), "b")<< endl;		    //删除字符第一次出现的地方
	cout << erase_head_copy(string("aaaabbbb"), 2) << endl;         //在字符串前删除指定个数字符
	cout << erase_tail_copy(string("aaaabbbb"), 2) << endl;         //在字符串后删除指定个数字符
	
	cout << trim_left_copy(string("  hellow  ")) << endl;           //在前面删除空格
	cout << trim_right_copy(string("  hellow  ")) << endl;			//在后面删除空格
	cout << trim_copy(string(" hell  ")) << "a" << endl;			//去除所有空格
	
	string s3 = "abcdefdefghidejk";
	cout << find_first(s3, "de") << endl;							//三、找到输出 返回值是迭代器
	cout << ifind_first(s3, "DE") << endl;							//加i忽略大小写
	cout << find_nth(s3, "de", 3) << endl;							//查找在字符第n次出现的位置
	cout << (find_first(s3, "de") == find_nth(s3, "de", 1) )<< endl;
	cout << find_head(s3, 5) << endl;								//查找字符串前几个字符
	cout << find_tail(s3, 5) << endl;								//查找字符串最后几个字符

	cout << replace_all_copy(s3, "de", "xixi") << endl;				//四、替换所有"abc"为"abcd"
	cout << replace_first_copy(s3, "de", "hehe") << endl;			//替换第一次出现"de"  最后一次出现_tail

	cout << starts_with("abcd", "ab") << endl;						//五、判断ab是否为"acbd"的前缀
	cout << ends_with("abcd", "cd") << endl;						//是否为后缀
	cout << contains("abcd", "bc") << endl;							//是否包含关系
	cout << iequals("abcd", "ABCD") << endl;						//判断是否相等 （==）

	cout << all(s3, is_lower()) << endl;							//六、判定式 是否小写全部
	cout << all(" ",is_space()) << endl;                            //判断是否为空格（==" "） 
	cout << all("1a23", is_alnum()) << endl;						//判断是否为字母和数字
	cout << all("av1", is_alpha()) << endl;							//是否为字母
	cout << all("7F", is_cntrl()) << endl;							//是否控制字符
	cout << all("123", is_digit()) << endl;							//是否数字

	vector<string> str_a;
	split(str_a, "abc def  ghi",is_any_of(" "));					//七、字符串分割
	for (auto i : str_a)
		cout << i << '\t';

	vector<string> ve1 = { "hellow","word" };						//八、字符串连接
	cout << join(ve1, "+")<<endl;

	int a = 10, b = 20;
	string c = "hellow";
	cout << print("%d\t%d\t%s\n") % a%b%c;							//九、格式化输出


	system("pause");
	return 0;
}

