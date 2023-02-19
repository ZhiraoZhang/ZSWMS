#pragma once
#include<iostream>
#include<string>
#include<fstream>
#define FILENAME "empFile.txt"


using namespace std;
class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();
	void Show_Menu();
	void ExitSystem();
};

