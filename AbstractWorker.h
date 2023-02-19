#pragma once
#include<iostream>
#include<string>
using namespace std;

class AbstractWorker
{
public:
	//显示个人信息
	virtual void showInfo() = 0;
	virtual std::string getDeptName() = 0;

	int m_Id;//职工编号
	std::string m_Name;//姓名
	int m_DeptId;//部门编号
};