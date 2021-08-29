#include"student.h"

//Ĭ�Ϲ���
Student::Student()
{

}
//�вι��죨ѧ�š����������룩
Student::Student(int id, string name, string pwd)
{
	//��ʼ������
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs>>com.m_ComId&&com.m_MaxNum)
	{
		//����ȡ����Ϣ�ŵ�������
		vCom.push_back(com);
	}
	ifs.close();
}

//�˵�����
void Student::operMenu()
{
	
		cout << "��ӭѧ������" << this->m_Name << "��¼��" << endl;
		cout << "\t\t----------------------------------------------\n";
		cout << "\t\t|                                            |\n";
		cout << "\t\t|            1������˺�                     |\n";
		cout << "\t\t|                                            |\n";
		cout << "\t\t|            2���鿴�˺�                     |\n";
		cout << "\t\t|                                            |\n";
		cout << "\t\t|            3���鿴����                     |\n";
		cout << "\t\t|                                            |\n";
		cout << "\t\t|            4�����ԤԼ                     |\n";
		cout << "\t\t|                                            |\n";
		cout << "\t\t|            0��ע����¼                     |\n";
		cout << "\t\t----------------------------------------------\n";
		cout << "��ѡ�����Ĳ�����" << endl;
	
}

//����ԤԼ
void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ������" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	int data = 0;
	int interval = 0;
	int room = 0;

	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		cout << "������������������" << endl;

	}
	cout << "����������ԤԼ��ʱ���" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������" << endl;

	}
	cout << "��ѡ�����" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[0].m_ComId << "�Ż�������Ϊ��" << vCom[0].m_MaxNum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;

	}
	cout << "ԤԼ�ɹ��������" << endl;
	ofstream ofs;
	ofs.open(ORDER_FILE,ios::app);

	ofs << "data:" << data << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 <<endl;

	ofs.close();
	system("pause");
	system("cls");

}

//�鿴�ҵ�ԤԼ
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
			cout << "ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "������" << of.m_orderData[i]["roomId"];
			string status = "״̬��";//0ȡ��ԤԼ   1�����  2��ԤԼ   -1ԤԼʧ��
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if(of.m_orderData[i]["status"] == "-1")
			{
				status += "���δͨ����ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
		
	}
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "�� ";
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
		cout << "ѧ��" << of.m_orderData[i]["stuId"];
		cout << "����" << of.m_orderData[i]["stuName"];
		cout << "ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << "������" << of.m_orderData[i]["roomId"];
		string status = "״̬��";//0ȡ��ԤԼ   1�����  2��ԤԼ   -1ԤԼʧ��
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
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

//ȡ��ԤԼ
void Student::canelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ��¼����ȡ�����鰡����ȡ���ļ�¼" << endl;

		vector<int>v;
	int index = 1;
	for(int i=0;i<of.m_Size;i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "�� ";
				cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
				cout << "ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << "������" << of.m_orderData[i]["roomId"];
				string status = "״̬��";//0ȡ��ԤԼ   1�����  2��ԤԼ   -1ԤԼʧ��
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				
				cout << status << endl;
			}
		}
	}
	cout << "������ȡ���ļ�¼��0������" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if(select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}

