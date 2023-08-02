#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class  boss :public worker
{
public:
	boss(int uid, string name, int stationnum)
	{
		this->m_uid = uid;
		this->m_name = name;
		this->m_stationnum = stationnum;
	}
	virtual void showinfo();
	virtual string getstation();

};
