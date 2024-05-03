
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
	
	/*Abst_Worker* worker = new Employee(1, "����", 101);
	worker->Showinfo();
	delete worker;

	worker = new Manager(2, "����", 102);
	worker->Showinfo();
	delete worker;

	worker = new Boss(3, "����", 103);
	worker->Showinfo();
	delete worker;*/


	while (true)
	{
		int choice = 0;

		wm.ShowMenu();

		cout << "���������ѡ��:> ";
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
			cout << "����ֵ��Ч,����������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}