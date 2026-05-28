#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include"identity.h"
#include"globalFile.h"
#include"student.h"
#include"techer.h"
#include"computerRoom.h"
using namespace std;
class Manager :public Identity
{
public:
	Manager();//默认构造
	Manager(string name, string pwd);//有参构造
	virtual void openMenu(); //操作菜单
	void addPerson();   //添加账号
	void showPerson();  //查看信息
	void showComputer();  //查看机房信息
	void cleanFile();     //清空预约记录
	void initVector();    //初始化容器
	bool checkRepeat(int id, int type);//检测重复 ，true代表有重复，false代表没有重复
	vector<Student> vStu;  //学生容器
	vector<Teacher> vTea;  //教师容器
	vector<ComputerRoom> vCom;  //机房信息
};