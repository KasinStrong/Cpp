#include <iostream>
using namespace std;

#include "employee.h"


//构造函数
Employee::Employee(int id, string name, int deptId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptId;
}

void Employee::Showinfo()
{
	cout << "职工编号: " << this->m_Id
		<< "\t\t职工姓名: " << this->m_Name
		<< "\t\t岗位职责: " << this->GetPosition()//关键:成员函数可以相互调用
		<< "\t\t岗位任务: 完成经理交付给的任务"
		<< endl;
}


string Employee::GetPosition()
{
	return string("员工");
}
