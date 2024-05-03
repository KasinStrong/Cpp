#include <iostream>
using namespace std;


#include "manager.h"




//构造函数
Manager::Manager(int id, string name, int deptId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptId;
}

//展示职工的信息
void Manager::Showinfo()
{
	cout << "职工编号: " << this->m_Id
		<< "\t\t职工姓名: " << this->m_Name
		<< "\t\t岗位职责: " << this->GetPosition()//关键:成员函数可以相互调用
		<< "\t\t岗位任务: 完成老板交付给的任务"
		<< endl ;
}

//获取职工的身份
string Manager::GetPosition()
{
	return string("经理");
}