#pragma once
#include "AbstractWorker.h"
class Employee :
    public AbstractWorker
{
public:

	//构造函数
	Employee(int id, std::string name, int dId);

	//显示个人信息
	virtual void showInfo();
};

