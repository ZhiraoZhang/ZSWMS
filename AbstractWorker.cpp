#include "AbstractWorker.h"

std::string AbstractWorker::getDeptName()
{
    if (m_DeptId == 1)
    {
        return std::string("员工");
    }
    else if (m_DeptId == 2)
    {
        return std::string("经理");
    }
    else if (m_DeptId == 3)
    {
        return std::string("总监");
    }
    else
        return string("无效职位！");
}
