#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>
#include<fstream>
#include<vector>
#include"computerRoom.h"
#include"globalFile.h"
#include"orderFile.h"

//ѧ����
class Student :public Identity
{
public:
	//Ĭ�Ϲ���
	Student();

	//�вι��죨ѧ�š����������룩
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//������ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void canelOrder();

	//ѧ��ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom> vCom;
};
	
