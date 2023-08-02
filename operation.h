#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include"worker.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"

class operate
{
public:
	operate();
	int presearch(int target);
	int presearch(string target);
	void showmenu();
	void exitsystem();
	void add();
	void show();
	void del();
	void mode();
	void order();
	void search();
	void empty();
	void preserve();
	~operate()
	{
	}
	int m_lenght;
	int m_workernum;
	worker** m_L;
	int uid;
	string name;
	int stationnum;
};
