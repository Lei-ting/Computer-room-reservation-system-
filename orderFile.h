#pragma once
#include<iostream>
using namespace std;
#include<map>
#include"globalFile.h"
#include<fstream>
#include"student.h"

class OrderFile
{
public:
	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼������
	map<int, map<string, string>>m_orderData;

	//ԤԼ��¼����
	int m_Size;


};