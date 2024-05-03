#pragma once

#include <iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>

#define FILENAME "empFile.txt"


//创建一个管理类,对整体架构进行维护
//1.与用户进行沟通-----菜单
//2.对职工增删改查
//3.与文件的读写交互
class WorkerManager
{
public:
	WorkerManager();

	//展示菜单
	void ShowMenu();

	//退出系统
	void ExitSystem();

	//增加员工
	void AddEmp();

	//保存数据到文件中
	void Save();

	~WorkerManager();



	//成员
	Abst_Worker** m_EmpArr; //维护职工数据
	int m_EmpNum; //当前职工数量
	bool m_FileIsEmpty;
};