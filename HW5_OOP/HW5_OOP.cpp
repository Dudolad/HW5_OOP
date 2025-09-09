#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
	Time t1;
	Time t2(23, 59, 50, true);


	cout << "�������� ���: ";
	t1.showTime();

	cout << "��c t2: ";
	t2.showTime();


	cout << "---------------------------------------------------------\n";


	cout << "tickTime 15 ����: \n";
	for (int i = 0; i < 15; i++)
	{
		t2.tickTime();
		t2.showTime();
	}


	cout << "---------------------------------------------------------\n";


	Time t3 = t2 + 120.0f; 
	cout << "t2 + 120 ������ = ";
	t3.showTime();


	Time t4 = t2 + 5; 
	cout << "t2 + 5 ������ = ";
	t4.showTime();


	Time t5 = t2 + 2l;
	cout << "t2 + 2 ������ = ";
	t5.showTime();


	cout << "---------------------------------------------------------\n";


	Time t6(11, 30, 0, false); 
	cout << "12h ������: ";
	t6.showTime();


	return 0;
}

