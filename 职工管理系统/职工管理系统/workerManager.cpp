#include "workerManager.h"

WorkerManager::WorkerManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		
		perror("file");
		
		this->m_EmpArr = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = false;
		return;
	}

	ifs.close();
	
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArr)
	{
		delete[] this->m_EmpArr;
		m_EmpArr = NULL;
	}
}

//菜单
void WorkerManager::ShowMenu()
{
	cout << "******************************************" << endl;
	cout << "*********    欢迎来到职工管理系统!   *****  " << endl;
	cout << "***********    0.退出管理系统     ******** " << endl;
	cout << "***********    1.增加职工信息     ******** " << endl;
	cout << "***********    2.显示职工信息     ******** " << endl;
	cout << "***********    3.删除职工信息     ******** " << endl;
	cout << "***********    4.修改职工信息     ******** " << endl;
	cout << "***********    5.查找职工信息     ******** " << endl;
	cout << "***********    6.按照编号排序     ******** " << endl;
	cout << "***********    7.清空所有文档     ******** " << endl;
	cout << "******************************************" << endl;
	cout << endl;
}

//退出
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次光临" << endl << endl;

	exit(0); //直接退出程序
}

//增加
void WorkerManager::AddEmp()
{
	//增加员工的数量
	int addNum = 0;

	do
	{
		
		cout << "你要增加多少个员工 ? " << endl;
		cin >> addNum;

		//检查输入的数据的有效性
		if (addNum > 0 )
		{
			//重新开辟一块新的空间
			Abst_Worker** newSpace = new Abst_Worker * [this->m_EmpNum + addNum];

			//如果原空间用于数据
			if (this->m_EmpArr != NULL)
			{
				//将原有的数据拷贝的新的空间
				for (int i = 0; i < this->m_EmpNum; ++i)
				{
					newSpace[i] = this->m_EmpArr[i];
				}

				//将原来开辟的空间释放
				delete[] this->m_EmpArr;
				this->m_EmpArr = NULL;


				
			}

			//批量输入数据
			for (int i = 0; i < addNum; ++i)
			{
				int id = 0;
				string name = "";
				int deptId = 0;
				//输入提示
				cout << "正在添加第 " << i + 1 << " 个员工 " << endl;

				cout << "请输入所添加员工的id" << endl;
				cin >> id;

				cout << "请输入所添加员工的姓名" << endl;
				cin >> name;

				cout << "请输入所添加员工的部门编号" << endl;

				Abst_Worker* worker = NULL;
				do
				{
					cout << "1.普通员工" << endl;
					cout << "2.经理" << endl;
					cout << "3.老板" << endl;
					cin >> deptId;

					//创建一个抽象父指针来指向子对象

					switch (deptId)
					{
					case 1: //普通员工
						worker = new Employee(id, name, deptId);
						break;
					case 2: //经理
						worker = new Manager(id, name, deptId);
						break;
					case 3: //老板
						worker = new Boss(id, name, deptId);
						break;
					default:
						cout << "输入有误,请重新输入部门编号";
						break;
					}
				} while (!(deptId > 0 && deptId <4));



				newSpace[this->m_EmpNum + i] = worker;
			}

			
			//更新系统数据
			this->m_EmpArr = newSpace;
			this->m_EmpNum = this->m_EmpNum + addNum;

			//释放临时维护指针  : 大错特错,这是释放维护指针所指的空间
			break;
		}
		else
		{
			cout << "输入数据有误,请重新输入" << endl;
		}

	} while (true);

	//保存的文件中
	this->Save();

	//添加成功提示
	cout << "成功添加 " << addNum << " 个人" << endl;

	system("pause");
	system("cls");
}

void WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	if (!ofs.is_open())
	{
		perror("Save:");
		exit(0);
	}

	for (int i = 0; i < this->m_EmpNum; ++i)
	{
		ofs<< "   " << this->m_EmpArr[i]->m_Id ;
		ofs<< "   " << this->m_EmpArr[i]->m_Name;
		ofs<< "   " << this->m_EmpArr[i]->m_DeptId ;

		ofs << endl;
	}

	ofs.close();
}

