#include <iostream>
using namespace std;


#include "manager.h"




//���캯��
Manager::Manager(int id, string name, int deptId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptId;
}

//չʾְ������Ϣ
void Manager::Showinfo()
{
	cout << "ְ�����: " << this->m_Id
		<< "\t\tְ������: " << this->m_Name
		<< "\t\t��λְ��: " << this->GetPosition()//�ؼ�:��Ա���������໥����
		<< "\t\t��λ����: ����ϰ彻����������"
		<< endl ;
}

//��ȡְ�������
string Manager::GetPosition()
{
	return string("����");
}