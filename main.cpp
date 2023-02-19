#include<iostream>
#include"WorkerManager.h"
#include"AbstractWorker.h"
#include"Boss.h"
#include"Manager.h"
#include"Employee.h"
using namespace std;
void test()
{
	AbstractWorker* worker1 = new Boss(1, "张三", 1);
	AbstractWorker* worker2 = new Manager(2, "李四", 3);
	AbstractWorker* worker3 = new Employee(3, "王五", 3);
	worker1->showInfo();
	worker2->showInfo();
	worker3->showInfo();
	delete worker1, worker2, worker3;
	worker1 = worker2 = worker3 = NULL;
	system("pause");
	system("cls");
}
int main()
{
	WorkerManager wm;
	int choice;
	while (1)
	{
		wm.Show_Menu();
		cout << "请输入您的选择：";
		cin >> choice;
		switch(choice)
		{
		case 0:
			wm.ExitSystem();
			break;
		case 1:
			test();
			break;
		}
	}
	return 0;
}