#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"identity.h"
#include<string>
#include<fstream>
#include<vector>
#include"computerRoom.h"
#include"globalFile.h"
#include"orderFile.h"

class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι��죨ְ����š����������룩
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//������ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	int m_EmpId;//��ʦ���

};