#pragma once
#include <iostream>
using namespace std;

#include "worker.h"
#include <string>

class Boss: public Abst_Worker
{
public:
	Boss(int id, string name, int deptId);

	//չʾְ������Ϣ
	virtual void Showinfo();

	//��ȡְ�������
	virtual string GetPosition();
};