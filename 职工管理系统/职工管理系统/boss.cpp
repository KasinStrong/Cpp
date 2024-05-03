#include <iostream>
using namespace std;

#include <string>
#include "boss.h"

Boss::Boss(int id, string name, int deptId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptId;
}

//展示职工的信息
void Boss::Showinfo()
{
	cout << "职工编号: " << this->m_Id
		<< "\t\t职工姓名: " << this->m_Name
		<< "\t\t岗位职责: " << this->GetPosition()//关键:成员函数可以相互调用
		<< "\t\t岗位任务: 管理公司各项事务"
		<< endl;
}

//获取职工的身份
string Boss::GetPosition()
{
	return string("老板");
}