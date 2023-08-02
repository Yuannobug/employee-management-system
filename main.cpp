#include<iostream>
using namespace std;

#include"operation.h"

int main()
{
	operate adjust;
	int choice = 0;
	while (1)
	{
		adjust.showmenu();
		cin >> choice ;
		switch (choice)
		{
		case 0:adjust.exitsystem(); break;
		case 1:adjust.add(); break;
		case 2:adjust.show(); break;
		case 3:adjust.del(); break;
		case 4:adjust.mode(); break;
		case 5:adjust.order(); break;
		case 6:adjust.search(); break;
		case 7:adjust.empty(); break;
		default:system("cls"); break;
		}
	}
	system("pause");
	return 0;
}