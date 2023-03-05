#include "WorkerManager.h"


WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化人数
		m_EmpNum = 0;
		//初始化数组指针
		m_EmpArray = NULL;
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		//初始化人数
		m_EmpNum = 0;
		//初始化数组指针
		m_EmpArray = NULL;
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}
	
	//文件存在
	this->m_fileIsEmpty = false;
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new AbstractWorker * [this->m_EmpNum];
	this->init_Emp();
}

WorkerManager::~WorkerManager()
{
	if (m_EmpArray != NULL)
	{
		delete[] m_EmpArray;
		m_EmpArray = NULL;
	}
}

//菜单
void WorkerManager::Show_Menu()
{
	cout<<"************************************************"<<endl;
	cout<<"************** 欢迎使用职工管理系统！***************"<<endl;
	cout<<"**************  0. 退出管理程序   ****************"<<endl;
	cout<<"**************  1. 增加职工信息   ****************"<<endl;
	cout<<"**************  2. 显示职工信息   ****************"<<endl;
	cout<<"**************  3. 删除职工信息   ****************"<<endl;
	cout<<"**************  4. 修改职工信息   ****************"<<endl;
	cout<<"**************  5. 查找职工信息   ****************"<<endl;
	cout<<"**************  6. 按照编号排序   ****************"<<endl;
	cout<<"**************  7. 清空所有文档   ****************"<<endl;
	cout<<"************************************************"<<endl;
	cout<<endl;
}

void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用。" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工的数量：";
	int addNum = 0;     //保存用户的输入数量
	cin >> addNum;
	if (addNum > 0)
	{
		//新空间的长度
		int newSize = this->m_EmpNum + addNum;
		// 开辟新空间，由于
		AbstractWorker** newSpace = new AbstractWorker * [newSize];
		//将原空间内容放到新空间下
		if (m_EmpArray != NULL)
		{
			//此处想写为基于范围的for循环
			//for (auto i: m_EmpArray)
			for (int i = 0; i < m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;


			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			AbstractWorker* worker = NULL;
			switch (dSelect)
			{
			case 1: //普通员工
				worker = new Employee(id, name, 1);
				break;
			case 2: //经理
				worker = new Manager(id, name, 2);
				break;
			case 3:  //老板
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将新worker放入新空间的尾部
			newSpace[this->m_EmpNum + i] = worker;
		}
		//全部到新空间里准备释放老空间
		delete[] this->m_EmpArray;
		this->m_EmpNum = newSize;
		m_EmpArray = newSpace;
		cout << "成功添加" << addNum << "名职工" << endl;
		this->Save_emp();
		system("pause");
		system("cls");
	}
}

void WorkerManager::Save_emp()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		AbstractWorker *worker = NULL;
		if (did == 1)
			worker = new Employee(id, name, did);
		else if (did == 2)
			worker = new Manager(id, name, did);
		else if (did == 3)
			worker = new Boss(id, name, did);
		this->m_EmpArray[index] = worker;
		index++;
	}
}

void WorkerManager::Show_Emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		return;
	}
	if (m_EmpArray != NULL)
	{
		cout << "共有" << m_EmpNum << "个员工" << endl;
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Delete_Emp()
{

	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或记录为空。" << endl;
		return;
	}
	cout << "请输入要删除的员工编号:";
	int id;	
	cin >> id;
	int index = this->IsExist(id);
	if (index != -1)//说明存在ing且要删除掉index员工
	{
		//数据前移
		for (size_t i = index; i < this->m_EmpNum-1; i++)
		{
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		this->m_EmpNum--;
		this->Save_emp();
		cout << "删除成功。" << endl;
	}
	else cout << "删除失败，没有找到该员工！" << endl;
	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (id == this->m_EmpArray[i]->m_Id)
		{
			index = i;
			cout << "找到员工" << endl;
		}
	}
	return index;
}

void WorkerManager::Mod_Emp()
{
	if (this->m_fileIsEmpty)
		cout << "文件为空。" << endl;
	else
	{
		cout << "请输入职工编号：";
		int modid;
		cin >> modid;
		int ret = this->IsExist(modid);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int id;
			string name;
			int dSelect;

			cout << "请输入新职工编号：" << endl;
			cin >> id;

			cout << "请输入新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			AbstractWorker* worker = NULL;
			switch (dSelect)
			{
			case 1: //普通员工
				worker = new Employee(id, name, 1);
				break;
			case 2: //经理
				worker = new Manager(id, name, 2);
				break;
			case 3:  //老板
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			this->Save_emp();			
			cout << "员工修改成功。" << endl;
		}
		else cout << "没有找到该员工。" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp()
{
	if (this->m_fileIsEmpty)
		cout << "文件为空。" << endl;
	else
	{
		cout << "请输入职工编号：";
		int findid;
		cin >> findid;
	}
}
