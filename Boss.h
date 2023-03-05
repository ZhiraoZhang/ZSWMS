#pragma once
#include "AbstractWorker.h"
using namespace std;
class Boss :
    public AbstractWorker
{
public:
    Boss(int id, string name, int dId);
    ~Boss();
    //显示个人信息
    virtual void showInfo();
};

