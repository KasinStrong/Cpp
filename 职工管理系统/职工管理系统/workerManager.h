#pragma once

#include <iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>

#define FILENAME "empFile.txt"


//����һ��������,������ܹ�����ά��
//1.���û����й�ͨ-----�˵�
//2.��ְ����ɾ�Ĳ�
//3.���ļ��Ķ�д����
class WorkerManager
{
public:
	WorkerManager();

	//չʾ�˵�
	void ShowMenu();

	//�˳�ϵͳ
	void ExitSystem();

	//����Ա��
	void AddEmp();

	//�������ݵ��ļ���
	void Save();

	~WorkerManager();



	//��Ա
	Abst_Worker** m_EmpArr; //ά��ְ������
	int m_EmpNum; //��ǰְ������
	bool m_FileIsEmpty;
};