#include "workerManager.h"

WorkerManager::WorkerManager()
{
	//1.�ļ�������
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

//�˵�
void WorkerManager::ShowMenu()
{
	cout << "******************************************" << endl;
	cout << "*********    ��ӭ����ְ������ϵͳ!   *****  " << endl;
	cout << "***********    0.�˳�����ϵͳ     ******** " << endl;
	cout << "***********    1.����ְ����Ϣ     ******** " << endl;
	cout << "***********    2.��ʾְ����Ϣ     ******** " << endl;
	cout << "***********    3.ɾ��ְ����Ϣ     ******** " << endl;
	cout << "***********    4.�޸�ְ����Ϣ     ******** " << endl;
	cout << "***********    5.����ְ����Ϣ     ******** " << endl;
	cout << "***********    6.���ձ������     ******** " << endl;
	cout << "***********    7.��������ĵ�     ******** " << endl;
	cout << "******************************************" << endl;
	cout << endl;
}

//�˳�
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´ι���" << endl << endl;

	exit(0); //ֱ���˳�����
}

//����
void WorkerManager::AddEmp()
{
	//����Ա��������
	int addNum = 0;

	do
	{
		
		cout << "��Ҫ���Ӷ��ٸ�Ա�� ? " << endl;
		cin >> addNum;

		//�����������ݵ���Ч��
		if (addNum > 0 )
		{
			//���¿���һ���µĿռ�
			Abst_Worker** newSpace = new Abst_Worker * [this->m_EmpNum + addNum];

			//���ԭ�ռ���������
			if (this->m_EmpArr != NULL)
			{
				//��ԭ�е����ݿ������µĿռ�
				for (int i = 0; i < this->m_EmpNum; ++i)
				{
					newSpace[i] = this->m_EmpArr[i];
				}

				//��ԭ�����ٵĿռ��ͷ�
				delete[] this->m_EmpArr;
				this->m_EmpArr = NULL;


				
			}

			//������������
			for (int i = 0; i < addNum; ++i)
			{
				int id = 0;
				string name = "";
				int deptId = 0;
				//������ʾ
				cout << "������ӵ� " << i + 1 << " ��Ա�� " << endl;

				cout << "�����������Ա����id" << endl;
				cin >> id;

				cout << "�����������Ա��������" << endl;
				cin >> name;

				cout << "�����������Ա���Ĳ��ű��" << endl;

				Abst_Worker* worker = NULL;
				do
				{
					cout << "1.��ͨԱ��" << endl;
					cout << "2.����" << endl;
					cout << "3.�ϰ�" << endl;
					cin >> deptId;

					//����һ������ָ����ָ���Ӷ���

					switch (deptId)
					{
					case 1: //��ͨԱ��
						worker = new Employee(id, name, deptId);
						break;
					case 2: //����
						worker = new Manager(id, name, deptId);
						break;
					case 3: //�ϰ�
						worker = new Boss(id, name, deptId);
						break;
					default:
						cout << "��������,���������벿�ű��";
						break;
					}
				} while (!(deptId > 0 && deptId <4));



				newSpace[this->m_EmpNum + i] = worker;
			}

			
			//����ϵͳ����
			this->m_EmpArr = newSpace;
			this->m_EmpNum = this->m_EmpNum + addNum;

			//�ͷ���ʱά��ָ��  : ����ش�,�����ͷ�ά��ָ����ָ�Ŀռ�
			break;
		}
		else
		{
			cout << "������������,����������" << endl;
		}

	} while (true);

	//������ļ���
	this->Save();

	//��ӳɹ���ʾ
	cout << "�ɹ���� " << addNum << " ����" << endl;

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

