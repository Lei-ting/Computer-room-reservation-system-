#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<string>
#include"globalFile.h"
#include<fstream>
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"
class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι��� ����Ա����������
	Manager(string name, string pwd)
	{
		this->m_Name = name;
		this->m_Pwd = pwd;

		//��ʼ������
		this->initVector();
	}

	//ѡ��˵�
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initVector();

	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

    //����ظ��Ĳ���
	bool checkRepeat(int id, int type);

	//��������
	vector<ComputerRoom> vCom;

};