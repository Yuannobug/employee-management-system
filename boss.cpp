#include"boss.h"

string boss::getstation()
{
	return string("老板");
}

void boss::showinfo()
{
	cout << "编号：" << m_uid << endl;
	cout << "姓名：" << m_name << endl;
	cout << "部门：" << getstation() << endl;

}