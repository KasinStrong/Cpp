#pragma once

#include <iostream>
using namespace std;

#include <string>

class Abst_Worker
{
public:
	
	//չʾְ������Ϣ
	virtual void Showinfo() = 0;

	//��ȡְ�������
	virtual string GetPosition() = 0;

	int m_Id; //ְ�����
	string m_Name; //ְ������
	int m_DeptId; //���ű��
};