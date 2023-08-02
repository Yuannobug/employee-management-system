#include"employee.h"

string employee::getstation()
{
	return string("员工");
}

void employee::showinfo()
{
	cout << "编号：" << m_uid << endl;
	cout << "姓名：" << m_name << endl;
	cout << "部门：" << getstation() << endl;

}