#pragma once
#include<iostream>
using namespace std;


class worker
{
public:
	virtual void showinfo() = 0;
	virtual string getstation() = 0;

	int m_uid;
	string m_name;
	int m_stationnum;
};
