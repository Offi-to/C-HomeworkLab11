#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include<map>
#include"globalFile.h"
class OrderFile
{
public :
	OrderFile();//构造函数
	void updateOrder();//更新预约记录
	//记录的容量 key---记录的条数 value---具体的记录键值对信息
	map<int ,map<string, string>> m_orderData;
	int m_size;//预约记录条数
};