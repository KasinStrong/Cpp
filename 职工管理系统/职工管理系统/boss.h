#pragma once
#include <iostream>
using namespace std;

#include "worker.h"
#include <string>

class Boss: public Abst_Worker
{
public:
	Boss(int id, string name, int deptId);

	//展示职工的信息
	virtual void Showinfo();

	//获取职工的身份
	virtual string GetPosition();
};