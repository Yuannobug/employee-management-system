#include"boss.h"

string boss::getstation()
{
	return string("�ϰ�");
}

void boss::showinfo()
{
	cout << "��ţ�" << m_uid << endl;
	cout << "������" << m_name << endl;
	cout << "���ţ�" << getstation() << endl;

}