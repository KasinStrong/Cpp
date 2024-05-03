#pragma once

#include <iostream>
using namespace std;

#include <string>

class Abst_Worker
{
public:
	
	//展示职工的信息
	virtual void Showinfo() = 0;

	//获取职工的身份
	virtual string GetPosition() = 0;

	int m_Id; //职工编号
	string m_Name; //职工姓名
	int m_DeptId; //部门编号
};