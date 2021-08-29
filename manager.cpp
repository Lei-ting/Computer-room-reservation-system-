#include"manager.h"


//默认构造
Manager::Manager()
{

}

//有参构造
Manager::Manager(string name, string pwd)
{
	//初始化管理员信息
	this->m_Name = name;
	this->m_Pwd = pwd;
	//初始化容器
	 this->initVector();	
	 //获取机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "当前机房数量为：" << vCom.size() << endl;

	ifs.close();
}

//选择菜单
void Manager::operMenu()
{
	cout << "欢迎管理员" << this->m_Name << "登录！" << endl;
	cout << "\t\t----------------------------------------------\n";
	cout << "\t\t|                                            |\n";
	cout << "\t\t|            1、添加账号                     |\n";
	cout << "\t\t|                                            |\n";
	cout << "\t\t|            2、查看账号                     |\n";
	cout << "\t\t|                                            |\n";
	cout << "\t\t|            3、查看机房                     |\n";
	cout << "\t\t|                                            |\n";
	cout << "\t\t|            4、清空预约                     |\n";
	cout << "\t\t|                                            |\n";
	cout << "\t\t|            0、注销登录                     |\n";
	cout << "\t\t----------------------------------------------\n";
	cout << "请选择您的操作：" << endl;
}

//添加账号
void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;
	string fileName;
	string tip;
	string errorTip;//错误重复提示
	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号";
		errorTip = "学号重复，清重新输入";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工号重复，清重新输入";
	}
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;

	while (true)
	{
		cin >> id;
		bool ret=checkRepeat(id,select);
		if (ret)//有重复
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
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//初始化容器
	this->initVector();
}

void printStudent(Student&s)
{
	cout << "学号：" << s.m_Id << "姓名" << s.m_Name << "密码" << s.m_Pwd << endl;
}
void printTeacher(Teacher& s)
{
	cout << "职工号：" << s.m_EmpId << "姓名" << s.m_Name << "密码" << s.m_Pwd << endl;
}

//查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容" << endl;
	cout << "查看所有学生" << endl;
	cout << "查看所有老师" << endl;

	int select = 0;//接受用户选择
	cin >> select;
	if (select == 1)
	{
		//查看学生
		cout << "所有学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(),printStudent);
	}
	else
	{
		//查看老师
		cout << "所有老师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");
}

//查看机房信息
void Manager::showComputer()
{

}

//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");

}

//初始化容器
void Manager::initVector()
{
	//确保文件为空
	vStu.clear();
	vTea.clear();
	//读取信息 学生 老师
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生的数量为：" << vStu.size() << endl;
	ifs.close();//学生初始化

	//读取老师的文件信息
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前教师数量为：" << vTea.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//检测学生
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
		//监测老师
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
