#include<iostream>
#include"WorkerManager.h"
#include"AbstractWorker.h"
#include"Boss.h"
#include"Manager.h"
#include"Employee.h"
using namespace std;

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
			wm.Add_Emp();
			break;
		case 2:
			wm.Show_Emp();
			break;
		case 3:
			wm.Delete_Emp();
			break;
		default :
			cout << "非法输入!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}