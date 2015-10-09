/**
 *start from the very beginning,and to create greatness
 *@author: LinChuangwei 
 *@E-mail：979951191@qq.com
 *@brief：用map实现命令映射的一个小测试
 */

#include <iostream>
#include <map>
#include <string.h>
using namespace std;


class commandsfunc
{
public:
    typedef void (commandsfunc::*cmd_handler)(int arg);//函数指针，带有一个参数
	void do_func();
private:	
	map<const char*,cmd_handler> commandmap;
 	map<const char*,cmd_handler>::iterator it;
 	void do_one(int arg);
	void do_two(int arg);
	void do_three(int arg);
};
/**
 *do_func - 主要的执行函数
 */
void commandsfunc::do_func()
{
   commandmap["one"] = &commandsfunc::do_one;
   commandmap["two"] = &commandsfunc::do_two;
   commandmap["three"] = &commandsfunc::do_three;

    it = commandmap.find("one");//根据key查找value
	if(it != commandmap.end())
	{//存在和命令相对应的函数
		(this->*(it->second))(100);//执行该类自身的成员函数，it->second为函数地址，100为参数
	}
	else
	{
		cout<<"Unknow command."<<endl;
	}
}
/**
 *do_XXX - 几个回调函数的实现
 */
void commandsfunc::do_one(int arg)
{
	std::cout<<"one:"<<arg<<std::endl;		
}

void commandsfunc::do_two(int arg)
{
	std::cout<<"two:"<<arg<<std::endl;	
}

void commandsfunc::do_three(int arg)
{
	std::cout<<"three:"<<arg<<std::endl;	
}
/*
 *main - 主函数
 */
int main(int argc, char const *argv[])
{
	commandsfunc lcw;
	lcw.do_func();
	return 0;
}