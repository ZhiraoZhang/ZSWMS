#pragma once
#include<iostream>
using namespace std;
#include "AbstractWorker.h"

//经理类
class Manager :
	public AbstractWorker
{
public:

	Manager(int id, string name, int dId);

	//显示个人信息
	virtual void showInfo();
};