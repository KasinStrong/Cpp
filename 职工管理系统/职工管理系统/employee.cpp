#include <iostream>
using namespace std;

#include "employee.h"


//���캯��
Employee::Employee(int id, string name, int deptId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptId;
}

void Employee::Showinfo()
{
	cout << "ְ�����: " << this->m_Id
		<< "\t\tְ������: " << this->m_Name
		<< "\t\t��λְ��: " << this->GetPosition()//�ؼ�:��Ա���������໥����
		<< "\t\t��λ����: ��ɾ�������������"
		<< endl;
}


string Employee::GetPosition()
{
	return string("Ա��");
}
