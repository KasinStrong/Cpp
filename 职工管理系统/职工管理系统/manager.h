#pragma once

#include <iostream>
using namespace std;

#include "worker.h"
#include <string>

class Manager: public Abst_Worker
{
public:
	//���캯��
	Manager(int id,string name,int deptId);
	
	//չʾְ������Ϣ
	virtual void Showinfo();

	//��ȡְ�������
	virtual string GetPosition();
};
