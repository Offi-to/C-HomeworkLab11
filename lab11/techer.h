#pragma once
#include<iostream>
#include<vector>
using namespace std;
#include"identity.h"
#include"orderFile.h"
class Teacher :public Identity
{public :
	Teacher();//默认构造
	Teacher(int empId,string name,string pwd); //有参构造
	virtual void openMenu();  //菜单界面
	void showAllOrder();  //查看所有预约
	void validOrder();  //审核预约
	int m_EmpId;   //教师编号
};