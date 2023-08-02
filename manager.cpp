#include"manager.h"

string manager::getstation()
{
	return string("经理");
}

void manager::showinfo()
{
	cout << "编号：" << m_uid<<endl;
	cout << "姓名：" << m_name<<endl;
	cout << "部门：" << getstation() << endl;

}