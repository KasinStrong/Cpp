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

//չʾְ������Ϣ
void Boss::Showinfo()
{
	cout << "ְ�����: " << this->m_Id
		<< "\t\tְ������: " << this->m_Name
		<< "\t\t��λְ��: " << this->GetPosition()//�ؼ�:��Ա���������໥����
		<< "\t\t��λ����: ����˾��������"
		<< endl;
}

//��ȡְ�������
string Boss::GetPosition()
{
	return string("�ϰ�");
}