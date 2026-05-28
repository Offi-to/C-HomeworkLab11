#include<iostream>
using namespace std;
#include"student.h"
Student::Student()
{

}
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	ifs.close();
}
void Student::applyOrder()
{
	cout << "请输入预约日期为1-5:" << endl;
	cout << "请输入预约时长:" << endl;
	cout << "1.一小时" << endl;
	cout << "2.两小时" << endl;
	cout << "3.三小时" << endl;
	cout << "4.四小时" << endl;
	cout << "5.五小时" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "请输入预约时长:" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "请选择机房" << endl;
	cout << "1号机房为" << vCom[0].m_MaxNum << endl;
	cout << "2号机房为" << vCom[1].m_MaxNum << endl;
	cout << "3号机房为" << vCom[2].m_MaxNum << endl;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "预约成功，预约号为" << endl;
	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
}
void Student::openMenu()
{
	cout << "欢迎学生" << this->m_Name << "登录" << endl;
	cout << "\t\t------------------------------\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|--------1.申请预约------------|\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|--------2.查看我的预约--------|\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|--------3.查看所有预约--------|\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|--------4.取消预约------------|\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|--------0.注销登录------------|\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t-------------------------------|\n";
	cout << "请输入您的选项" << endl;
}
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "没有预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			cout << "预约日期为：" << of.m_orderData[i]["date"];
			cout << "  时长为" << ((of.m_orderData[i]["interval"] == "1") ? "上午" : "下午");
			cout << "  机房号" << of.m_orderData[i]["roomId"];
			string status = "  状态：";//0取消预约 1预约中,2预约成功,-1预约失败
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "预约中";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "预约失败";
			}
			else
			{
				status += "取消预约";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}
void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "没有预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << "��";
	    cout << "预约日期为：" << of.m_orderData[i]["date"];
	    cout << "  时长为" << ((of.m_orderData[i]["interval"] == "1") ? "上午" : "下午");
		cout << "  学号: " << of.m_orderData[i]["stuId"];
		cout << "  姓名: " << of.m_orderData[i]["stuName"];
		cout << "  机房号：" << of.m_orderData[i]["roomId"];
		string status = "  状态：";//0取消预约 1预约中,2预约成功,-1预约失败
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "预约中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "预约失败";
		}
		else
		{
			status += "取消预约";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "没有预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入取消的预约记录，0代表返回" << endl;
	vector<int> v;
	int index = 1;
	for (int i = 0; i < of.m_size; i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "��";
				cout << "预约日期为：" << of.m_orderData[i]["date"];
				cout << "  时长为" << ((of.m_orderData[i]["interval"] == "1") ? "上午" : "下午");
				cout << "  学号: " << of.m_orderData[i]["stuId"];
				cout << "  姓名: " << of.m_orderData[i]["stuName"];
				cout << "  机房号：" << of.m_orderData[i]["roomId"];
				string status = "  状态：";//0取消预约 1预约中,2预约成功,-1预约失败
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "预约中";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				else if (of.m_orderData[i]["status"] == "-1")
				{
					status += "预约失败";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入取消的预约记录，0代表返回" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= static_cast<int>(v.size()))
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "取消预约" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}