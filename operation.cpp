#include"operation.h"


operate::operate()
{
	char ch = 0;
	int i = 0;
	bool excelempty = true;
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	if (!ifs.is_open())//判断文件夹是否存在
	{
		cout << "系统不存在" << endl;
		excelempty = true;
		m_lenght = 0;
		m_L = NULL;
		ifs.close();
		return;
	}
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "系统为空" << endl;
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
		cout << "系统不为空,长度为" << m_lenght<< endl;
	}
}

void operate::showmenu()
{
	cout << "——————————————————————" << endl;
	cout << "————            菜单            ————" << endl;
	cout << "—0. 退出—————————————1. 增添—" << endl;
	cout << "—2. 显示—————————————3. 删除—" << endl;
	cout << "—4. 修改—————————————5. 排序—" << endl;
	cout << "—6. 查找—————————————7. 清空—" << endl;
	cout << "————    请输入您的选择          ————" << endl;

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

void operate::exitsystem()//退出
{
	preserve();
	cout << "欢迎您下次使用" << endl;
	system("pause");

	exit(0);
}

void operate::add()//增加
{
	worker** temp = NULL;
	worker* newworker = NULL;
	int workernum = 0;
	int sumnum = 0;
	int i = 0;
	int newuid = 0;
	string newname ;
	int newstationnum = 0;
	cout << "请输入想要添加的职工数目：" << endl;
	cin >> workernum;
	if (workernum <= 0)
	{
		cout << "输入方式不合理，请重新选择" << endl;
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
				cout << "请输入职工编号" << endl;
				cin >> newuid;
				cout << "请输入职工姓名" << endl;
				cin >> newname;
				cout << "请输入职工岗位" << endl;
				cout << "1.员工 2.经理 3.老板" << endl;
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
					cout << "不合理输入！请重新输入" << endl;
					continue;
				}

			}
		}
		else
		{
			i = 0;
			while (i < workernum)
			{
				cout << "请输入职工编号" << endl;
				cin >> newuid;
				cout << "请输入职工编号" << endl;
				cin >> newname;
				cout << "请输入职工编号" << endl;
				cout << "1.员工 2.经理 3.老板" << endl;
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
					cout << "不合理输入！请重新输入" << endl;
				}

			}

		}
	}
}

void operate::show()//展示
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

void operate::del()//删除
{
	int i = 0; int judge = 0; int target = 0;
	if (m_workernum == 0)
	{
		cout << "列表为空，无法删除！" << endl;
	}
	else
	{
		cout << "请输入您想要删除用户的编号：" << endl;
		cin >> target;
		judge = presearch(target);
		if (judge == -1)
		{
			cout << "不存在此用户！" << endl;
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
			cout << "删除成功！" << endl;
		}
	}
}

void operate::mode()//修改
{
	int newuid = 0;
	string newname;
	int newstationnum = 0;
	int i = 0; int judge = 0; int target = 0;
	if (m_workernum == 0)
	{
		cout << "列表为空，无法修改！" << endl;
	}
	else
	{
		cout << "请输入您想要修改的用户的编号：" << endl;
		cin >> target;
		judge = presearch(target);
		if (judge == -1)
		{
			cout << "不存在此用户！" << endl;
		}
		else
		{
			cout << "请输入修改后的编号：" << endl;
			cin >> newuid;
			cout << "请输入修改后的姓名：" << endl; 
			cin >> newname;
			cout << "请输入修改后的岗位：" << endl;
			cout << "1.员工 2.经理 3.老板" << endl;
			cin >> newstationnum;
			m_L[judge]->m_uid = newuid;
			m_L[judge]->m_name = newname;
			m_L[judge]->m_stationnum = newstationnum;
			cout << "修改成功！" << endl;
		}
	}

}

void operate::search()//查找
{
	int i = 0; int judge = 0; 
	int target1 = 0; string target2 ; int choice = 0;
	if (m_workernum == 0)
	{
		cout << "列表为空，无法查找！" << endl;
	}
	else
	{
		cout << "请输入您想要查找的用户的方式：" << endl;
		cout << "1.按编号 2.按姓名" << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "请输入编号" << endl;
			cin >> target1;
			judge = presearch(target1);
			if (judge == -1)
			{
				cout << "不存在此用户！" << endl;
			}
			else
			{
				m_L[judge]->showinfo();
			}
		}
		else if(choice==2)
		{
			cout << "请输入姓名" << endl;
			cin >> target2;
			judge = presearch(target2);
			if (judge == -1)
			{
				cout << "不存在此用户！" << endl;
			}
			else
			{
				m_L[judge]->showinfo();
			}
		}
		else
		{
			cout << "输入不合法！" << endl;
		}
		
	}
}

void operate::order()//排序
{
	int i = 0; int j = 0;
	int tempuid = 0;
	string tempname;
	int tempstationnum = 0;
	int choice = 0;
	int min = 0; int max = 0;
	cout << "请输入排序方式" << endl;
	cout << "1.正序 2.倒序" << endl;
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
		cout << "排序成功" << endl;
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
		cout << "排序成功" << endl;
	}
	else
	{
		cout << "输入不合理！" << endl;
	}
}



void operate::empty()//清空
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	int i = 0; int judge = 0;
	if (!ifs.is_open())//判断文件夹是否存在
	{
		cout << "文件不存在，无法清空" << endl;
		ifs.close();
		return;
	}
	cout << "请确认是否清空" << endl;
	cout << "1.是      0.否" << endl;
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
	cout << "清空成功" << endl;
}
