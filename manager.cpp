#include"manager.h"

string manager::getstation()
{
	return string("����");
}

void manager::showinfo()
{
	cout << "��ţ�" << m_uid<<endl;
	cout << "������" << m_name<<endl;
	cout << "���ţ�" << getstation() << endl;

}