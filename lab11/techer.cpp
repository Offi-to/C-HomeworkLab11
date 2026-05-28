#include"techer.h"
using namespace std;
Teacher::Teacher()
{
}
Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}
void Teacher::openMenu()
{
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t------------------------------\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|--------1.�鿴����ԤԼ--------|\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|--------2.����ԤԼ------------|\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|--------0.ע����¼------------|\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t-------------------------------|\n";
	cout << "��ѡ�����Ĳ���" << endl;
}
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "�޼�¼ԤԼ" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
		cout << "  ʱ�Σ�" << ((of.m_orderData[i]["interval"] == "1") ? "����" : "����");
		cout << "  ѧ��: " << of.m_orderData[i]["stuId"];
		cout << "  ����: " << of.m_orderData[i]["stuName"];
		cout << "  �������ţ�" << of.m_orderData[i]["roomId"];
		string status = "  ״̬��";//0��ȡ��ԤԼ 1������,2��ԤԼ,-1ԤԼʧ��
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "������";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ���";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ�ܣ�";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "�����˵�ԤԼ��¼���£�" << endl;
	vector<int> v;
	int index = 0;
	for (int i = 0; i < of.m_size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "��";
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
			cout << "  ʱ�Σ�" << ((of.m_orderData[i]["interval"] == "1") ? "����" : "����");
			cout << "  ������" << of.m_orderData[i]["roomId"];
			string status = "  ״̬��";//0��ȡ��ԤԼ 1������,2��ԤԼ,-1ԤԼʧ��
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "������";
			}
			cout << status << endl;
		}
	}
	cout << "���������˵�ԤԼ��¼��0��������" << endl;
	int select = 0;
	int ret = 0;
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
				cout << "���������˵Ľ���" << endl;
				cout << "1.ͨ��" << endl;
				cout << "2.��ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				cout << "��������!" << endl;
				break;
			}
		}
		cout << "��������,����������" << endl;
	}
	system("pause");
	system("cls");
}
