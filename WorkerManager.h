#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"AbstractWorker.h"
#include"Boss.h"
#include"Manager.h"
#include"Employee.h"
#define FILENAME "empFile.txt"


using namespace std;
class WorkerManager
{
public:
	//记录文件中的人数
	int m_EmpNum;

	//员工数组的指针,第一个*指向员工数组(地址),第二个*指向具体员工
	AbstractWorker** m_EmpArray;
	// 判断文件是否为空
	bool m_fileIsEmpty;

	WorkerManager();
	~WorkerManager();
	void Show_Menu();
	void ExitSystem();
	//增加员工
	void Add_Emp();
	//保存员工
	void Save_emp();
	//读文件记录的人数
	int get_EmpNum();
	//初始化员工
	void init_Emp();
	//显示员工
	void Show_Emp();
	//删除员工
	void Delete_Emp();
	int IsExist(int id);

};

