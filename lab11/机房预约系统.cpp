#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"techer.h"
#include"manager.h"
#ifdef _WIN32
#include <windows.h>
#endif
//教师菜单
void TeacherMenu(Identity* &teacher)
{
	while (true)
	{
		teacher->openMenu();
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//查看预约
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//审核预约
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//学生菜单
void studentMenu(Identity*& student)
{
	while (true)
	{
		student->openMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			stu->applyOrder();//申请预约
		}
		else if (select == 2)
		{
			stu->showMyOrder();//查看我的预约
		}
		else if (select == 3)
		{
			stu->showAllOrder();//查看所有预约
		}
		else if (select == 4)
		{
			stu->cancelOrder();//取消预约
		}
		else {
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//管理员菜单
void managerMenu(Identity*& manager)
{
	
	while (true)
	{
		int select = 0;
		Manager* man = (Manager*)manager;
		manager->openMenu();
		cin >> select;
		if (select == 1)
		{
			//cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			//cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			//cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			//cout << "清空预约" << endl;
			man->cleanFile();
		}
		else 
		{
			delete manager;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//登录函数  1.文件名  2.身份
void LoginIn(string fileName, int type)
{
	//身份指针，指向具体身份
	Identity* person = NULL;
	//打开文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	//判断文件是否打开
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//正确输入用户信息
	int id = 0;
	string name;
	string pwd;
	if (type == 1)//学生身份
	{
		cout << "请输入学生学号:" << endl;
		cin >> id;
	}
	if (type == 2)//教师身份
	{
		cout << "请输入教师编号:" << endl;
		cin >> id;
	}
	cout << "请输入用户名" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	if (type == 1)
	{
		//学生身份验证
		int fId;//从文件中读取的id号
		string fName;//从文件中读取的姓名
		string fPwd;  //从文件中获取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生数据的二级菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师身份验证
		int fId;//从文件中读取的id号
		string fName;//从文件中读取的姓名
		string fPwd;  //从文件中获取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师数据的二级菜单
				TeacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员身份验证
		string fName;//从文件中读取的姓名
		string fPwd;  //从文件中获取的密码
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员数据的二级菜单
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证登录失败" << endl;
	system("pause");
	system("cls");
	return;
}
int main()
{
	// 设置控制台编码为 UTF-8，解决中文乱码问题
	#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
	system("chcp 65001 > nul");  // 静默执行 chcp 命令
	#endif
	
	int select = 0;
	while (true)
	{
		cout << "======================欢迎使用预约系统======================" << endl;
		cout <<endl<< "请选择身份登录" << endl;
		cout << "\t\t----------------------------------\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           1.学生登录            |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           2.教师登录            |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           3.管理员登录          |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           0.退出系统            |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t----------------------------------\n";
		cout << "请输入您的选择：";
		cin >> select;
		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "请输入正确的选择" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}