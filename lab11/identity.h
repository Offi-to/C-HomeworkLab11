#pragma once
#include<iostream>
using namespace std;
//身份抽象类
class Identity
{
public :
	virtual void openMenu() = 0;   //纯虚菜单
	virtual ~Identity() {}  //虚析构函数，确保通过基类指针删除派生类对象时正确调用派生类析构函数
	string m_Name;  //用户名
	string m_Pwd;  //密码
};