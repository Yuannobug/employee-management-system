#include"employee.h"

string employee::getstation()
{
	return string("Ա��");
}

void employee::showinfo()
{
	cout << "��ţ�" << m_uid << endl;
	cout << "������" << m_name << endl;
	cout << "���ţ�" << getstation() << endl;

}