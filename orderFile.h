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
	//构造函数
	OrderFile();

	//更新预约记录
	void updateOrder();

	//记录的容器
	map<int, map<string, string>>m_orderData;

	//预约记录条数
	int m_Size;


};