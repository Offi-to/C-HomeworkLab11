#pragma once
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
#include"identity.h"
#include"computerRoom.h"
#include"globalFile.h"
#include"orderFile.h"
class Student :public Identity
{
public :
	Student();  //默认构造函数
	Student(int id, string name, string pwd);  //有参构造
	virtual void openMenu();   //菜单界面
	void applyOrder();   //申请预约
	void showMyOrder();  //查看我的预约
	void showAllOrder();  //查看所有预约
	void cancelOrder();   //取消预约
	int m_Id;        //学生学号
	vector<ComputerRoom> vCom;//机房信息
};