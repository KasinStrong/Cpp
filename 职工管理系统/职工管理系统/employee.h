#pragma once
#include <iostream>
using namespace std;

#include "worker.h"

class Employee : public Abst_Worker
{
public:
	//���캯��
	Employee(int id, string name, int deptId);

	//չʾְ������Ϣ
	virtual void Showinfo();

	//��ȡְ�������
	virtual string GetPosition();
};