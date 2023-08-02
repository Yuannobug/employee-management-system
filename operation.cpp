#include"operation.h"


operate::operate()
{
	char ch = 0;
	int i = 0;
	bool excelempty = true;
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	if (!ifs.is_open())//�ж��ļ����Ƿ����
	{
		cout << "ϵͳ������" << endl;
		excelempty = true;
		m_lenght = 0;
		m_L = NULL;
		ifs.close();
		return;
	}
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "ϵͳΪ��" << endl;
		excelempty = true;
		m_lenght = 0;
		m_L = NULL;
		ifs.close();
		return;
	}
	else
	{
		ifs.close();
		ifs.open("text.txt", ios::in);
		while (ifs >> uid && ifs >> name && ifs >> stationnum)
		{
			m_lenght++;
		}
		m_L = new worker * [m_lenght];
		ifs.close();
		ifs.open("text.txt", ios::in);
		for (i = 0; i < m_lenght; i++)
		{
			ifs >> uid;
			ifs >> name;
			ifs >> stationnum;
			if (stationnum == 1)
			{
				m_L[i] = new employee(uid, name, stationnum);
				m_workernum++;
			}
			else if (stationnum == 2)
			{
				m_L[i] = new manager(uid, name, stationnum);
				m_workernum++;
			}
			else if (stationnum == 3)
			{
				m_L[i] = new boss(uid, name, stationnum);
				m_workernum++;
			}
		}
		cout << "ϵͳ��Ϊ��,����Ϊ" << m_lenght<< endl;
	}
}

void operate::showmenu()
{
	cout << "��������������������������������������������" << endl;
	cout << "��������            �˵�            ��������" << endl;
	cout << "��0. �˳���������������������������1. ����" << endl;
	cout << "��2. ��ʾ��������������������������3. ɾ����" << endl;
	cout << "��4. �޸ġ�������������������������5. ����" << endl;
	cout << "��6. ���ҡ�������������������������7. ��ա�" << endl;
	cout << "��������    ����������ѡ��          ��������" << endl;

}

void operate:: preserve()
{
	int i = 0;
	ofstream ofs;
	ofs.open("text.txt", ios::out);
	for (i = 0; i < m_workernum; i++)
	{
		ofs <<this-> m_L[i]->m_uid << "  " << this->m_L[i]->m_name << "  " << this->m_L[i]->m_stationnum << endl;
	}
	ofs.close();
}

void operate::exitsystem()//�˳�
{
	preserve();
	cout << "��ӭ���´�ʹ��" << endl;
	system("pause");

	exit(0);
}

void operate::add()//����
{
	worker** temp = NULL;
	worker* newworker = NULL;
	int workernum = 0;
	int sumnum = 0;
	int i = 0;
	int newuid = 0;
	string newname ;
	int newstationnum = 0;
	cout << "��������Ҫ��ӵ�ְ����Ŀ��" << endl;
	cin >> workernum;
	if (workernum <= 0)
	{
		cout << "���뷽ʽ������������ѡ��" << endl;
	}
	else
	{
		sumnum = workernum + m_workernum;
		if (sumnum > m_lenght)
		{
			temp = new worker * [sumnum];
			for (i = 0; i < m_lenght; i++)
			{
				temp[i] = m_L[i];
			}
			delete this->m_L;
			this->m_L = temp;
			m_lenght = sumnum;
			while (i < sumnum)
			{
				cout << "������ְ�����" << endl;
				cin >> newuid;
				cout << "������ְ������" << endl;
				cin >> newname;
				cout << "������ְ����λ" << endl;
				cout << "1.Ա�� 2.���� 3.�ϰ�" << endl;
				cin >> newstationnum;
				if (newstationnum == 1)
				{
					newworker = new employee(newuid,newname,newstationnum);
					this->m_L[i] = newworker;
					i++;
					m_workernum++;
				}
				else if (newstationnum == 2)
				{
					newworker = new manager(newuid, newname, newstationnum);
					this->m_L[i] = newworker;					i++;
					m_workernum++;
				}
				else if (newstationnum == 3)
				{
					newworker = new boss(newuid, newname, newstationnum);
					this->m_L[i] = newworker;					i++;
					m_workernum++;
				}
				else
				{
					cout << "���������룡����������" << endl;
					continue;
				}

			}
		}
		else
		{
			i = 0;
			while (i < workernum)
			{
				cout << "������ְ�����" << endl;
				cin >> newuid;
				cout << "������ְ�����" << endl;
				cin >> newname;
				cout << "������ְ�����" << endl;
				cout << "1.Ա�� 2.���� 3.�ϰ�" << endl;
				cin >> newstationnum;
				if (newstationnum == 1)
				{
					newworker = new employee(newuid, newname, newstationnum);
					this->m_L[i] = newworker;
					i++;
					m_workernum++;
				}
				else if (newstationnum == 2)
				{
					newworker = new manager(newuid, newname, newstationnum);
					this->m_L[i] = newworker;
					i++;
					m_workernum++;
				}
				else if (newstationnum == 3)
				{
					newworker = new boss(newuid, newname, newstationnum);
					this->m_L[i] = newworker;
					i++;
					m_workernum++;
				}
				else
				{
					cout << "���������룡����������" << endl;
				}

			}

		}
	}
}

void operate::show()//չʾ
{
	int i = 0;
	for (i = 0; i < m_workernum; i++)
	{
		m_L[i]->showinfo();
	}
}

int operate::presearch(int target)
{
	int i = -1;
	for (i = 0; i < m_workernum; i++)
	{
		if (m_L[i]->m_uid == target)
		{
			return i;
		}
	}
	return -1;
}

int operate::presearch(string target)
{
	int i = -1;
	for (i = 0; i < m_workernum; i++)
	{
		if (m_L[i]->m_name == target)
		{
			return i;
		}
	}
	return -1;
}

void operate::del()//ɾ��
{
	int i = 0; int judge = 0; int target = 0;
	if (m_workernum == 0)
	{
		cout << "�б�Ϊ�գ��޷�ɾ����" << endl;
	}
	else
	{
		cout << "����������Ҫɾ���û��ı�ţ�" << endl;
		cin >> target;
		judge = presearch(target);
		if (judge == -1)
		{
			cout << "�����ڴ��û���" << endl;
		}
		else
		{
			delete m_L[judge];
			m_L[judge] = NULL;
			for (i = judge; i < m_workernum-1; i++)
			{
				m_L[i] = m_L[i + 1];
			}
			m_workernum--;
			cout << "ɾ���ɹ���" << endl;
		}
	}
}

void operate::mode()//�޸�
{
	int newuid = 0;
	string newname;
	int newstationnum = 0;
	int i = 0; int judge = 0; int target = 0;
	if (m_workernum == 0)
	{
		cout << "�б�Ϊ�գ��޷��޸ģ�" << endl;
	}
	else
	{
		cout << "����������Ҫ�޸ĵ��û��ı�ţ�" << endl;
		cin >> target;
		judge = presearch(target);
		if (judge == -1)
		{
			cout << "�����ڴ��û���" << endl;
		}
		else
		{
			cout << "�������޸ĺ�ı�ţ�" << endl;
			cin >> newuid;
			cout << "�������޸ĺ��������" << endl; 
			cin >> newname;
			cout << "�������޸ĺ�ĸ�λ��" << endl;
			cout << "1.Ա�� 2.���� 3.�ϰ�" << endl;
			cin >> newstationnum;
			m_L[judge]->m_uid = newuid;
			m_L[judge]->m_name = newname;
			m_L[judge]->m_stationnum = newstationnum;
			cout << "�޸ĳɹ���" << endl;
		}
	}

}

void operate::search()//����
{
	int i = 0; int judge = 0; 
	int target1 = 0; string target2 ; int choice = 0;
	if (m_workernum == 0)
	{
		cout << "�б�Ϊ�գ��޷����ң�" << endl;
	}
	else
	{
		cout << "����������Ҫ���ҵ��û��ķ�ʽ��" << endl;
		cout << "1.����� 2.������" << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "��������" << endl;
			cin >> target1;
			judge = presearch(target1);
			if (judge == -1)
			{
				cout << "�����ڴ��û���" << endl;
			}
			else
			{
				m_L[judge]->showinfo();
			}
		}
		else if(choice==2)
		{
			cout << "����������" << endl;
			cin >> target2;
			judge = presearch(target2);
			if (judge == -1)
			{
				cout << "�����ڴ��û���" << endl;
			}
			else
			{
				m_L[judge]->showinfo();
			}
		}
		else
		{
			cout << "���벻�Ϸ���" << endl;
		}
		
	}
}

void operate::order()//����
{
	int i = 0; int j = 0;
	int tempuid = 0;
	string tempname;
	int tempstationnum = 0;
	int choice = 0;
	int min = 0; int max = 0;
	cout << "����������ʽ" << endl;
	cout << "1.���� 2.����" << endl;
	cin >> choice;
	if (choice == 1)
	{
		for (i = 0; i < m_lenght; i++)
		{
			min = i;
			for (j = i; j < m_lenght; j++)
			{
				if (m_L[j]->m_uid < m_L[min]->m_uid)
				{
					min = j;
				}
			}
			if (min != i)
			{
				tempuid = m_L[min]->m_uid;
				tempname = m_L[min]->m_name;
				tempstationnum = m_L[min]->m_stationnum;
				m_L[min]->m_uid= m_L[i]->m_uid;
				m_L[min]->m_name = m_L[i]->m_name;
				m_L[min]->m_stationnum = m_L[i]->m_stationnum;
				m_L[i]->m_uid = tempuid;
				m_L[i]->m_name = tempname;
				m_L[i]->m_stationnum = tempstationnum;
			}
		}
		cout << "����ɹ�" << endl;
	}
	else if (choice == 2)
	{
		for (i = 0; i < m_lenght; i++)
		{
			max = i;
			for (j = i; j < m_lenght; j++)
			{
				if (m_L[j]->m_uid > m_L[max]->m_uid)
				{
					max = j;
				}
			}
			if (max != i)
			{
				tempuid = m_L[max]->m_uid;
				tempname = m_L[max]->m_name;
				tempstationnum = m_L[max]->m_stationnum;
				m_L[max]->m_uid = m_L[i]->m_uid;
				m_L[max]->m_name = m_L[i]->m_name;
				m_L[max]->m_stationnum = m_L[i]->m_stationnum;
				m_L[i]->m_uid = tempuid;
				m_L[i]->m_name = tempname;
				m_L[i]->m_stationnum = tempstationnum;
			}
		}
		cout << "����ɹ�" << endl;
	}
	else
	{
		cout << "���벻����" << endl;
	}
}



void operate::empty()//���
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	int i = 0; int judge = 0;
	if (!ifs.is_open())//�ж��ļ����Ƿ����
	{
		cout << "�ļ������ڣ��޷����" << endl;
		ifs.close();
		return;
	}
	cout << "��ȷ���Ƿ����" << endl;
	cout << "1.��      0.��" << endl;
	cin >> judge;
	if (judge == 0)
	{
		return;
	}
	ofstream ofs;
	ofs.open("text.txt", ios::trunc);
	ofs.close();
	for (i = 0; i < m_lenght; i++)
	{
		delete m_L[i];
	}
	delete m_L;
	m_L = NULL;
	m_lenght = 0; m_workernum = 0;
	cout << "��ճɹ�" << endl;
}
