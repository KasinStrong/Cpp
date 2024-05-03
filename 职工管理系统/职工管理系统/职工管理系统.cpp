
#include <iostream>
using namespace std;

#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

enum en_Choice
{
	EXIT,
	ADD,
	DISPLAY,
	DELETE,
	MODIFY,
	SEARCH,
	SORT,
	CLEAR
};

int main()
{
	WorkerManager wm;
	
	/*Abst_Worker* worker = new Employee(1, "张三", 101);
	worker->Showinfo();
	delete worker;

	worker = new Manager(2, "李四", 102);
	worker->Showinfo();
	delete worker;

	worker = new Boss(3, "王五", 103);
	worker->Showinfo();
	delete worker;*/


	while (true)
	{
		int choice = 0;

		wm.ShowMenu();

		cout << "请做出你的选择:> ";
		cin >> choice;

		switch (choice)
		{
		case EXIT:
			wm.ExitSystem();
			break;
		case ADD:
			wm.AddEmp();
			break;
		case DISPLAY:
			break;
		case DELETE:
			break;
		case MODIFY:
			break;
		case SEARCH:
			break;
		case SORT:
			break;
		case CLEAR:
			break;
		default:
			cout << "输入值无效,请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}