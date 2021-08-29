#include"manager.h"


//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι���
Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;
	//��ʼ������
	 this->initVector();	
	 //��ȡ������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ��" << vCom.size() << endl;

	ifs.close();
}

//ѡ��˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա" << this->m_Name << "��¼��" << endl;
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

//����˺�
void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;
	string fileName;
	string tip;
	string errorTip;//�����ظ���ʾ
	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ��";
		errorTip = "ѧ���ظ�������������";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ�����ظ�������������";
	}
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;

	while (true)
	{
		cin >> id;
		bool ret=checkRepeat(id,select);
		if (ret)//���ظ�
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	cout << tip << endl;
	cin >> id;
	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//��ʼ������
	this->initVector();
}

void printStudent(Student&s)
{
	cout << "ѧ�ţ�" << s.m_Id << "����" << s.m_Name << "����" << s.m_Pwd << endl;
}
void printTeacher(Teacher& s)
{
	cout << "ְ���ţ�" << s.m_EmpId << "����" << s.m_Name << "����" << s.m_Pwd << endl;
}

//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴����" << endl;
	cout << "�鿴����ѧ��" << endl;
	cout << "�鿴������ʦ" << endl;

	int select = 0;//�����û�ѡ��
	cin >> select;
	if (select == 1)
	{
		//�鿴ѧ��
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(),printStudent);
	}
	else
	{
		//�鿴��ʦ
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showComputer()
{

}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");

}

//��ʼ������
void Manager::initVector()
{
	//ȷ���ļ�Ϊ��
	vStu.clear();
	vTea.clear();
	//��ȡ��Ϣ ѧ�� ��ʦ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ��������Ϊ��" << vStu.size() << endl;
	ifs.close();//ѧ����ʼ��

	//��ȡ��ʦ���ļ���Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		//�����ʦ
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end();it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}
