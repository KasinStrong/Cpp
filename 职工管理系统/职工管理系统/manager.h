#pragma once

#include <iostream>
using namespace std;

#include "worker.h"
#include <string>

class Manager: public Abst_Worker
{
public:
	//构造函数
	Manager(int id,string name,int deptId);
	
	//展示职工的信息
	virtual void Showinfo();

	//获取职工的身份
	virtual string GetPosition();
};
