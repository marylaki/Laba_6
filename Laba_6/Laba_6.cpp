// Laba_6.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Matrix.h"
#include <iostream>
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	cout << "*******************��������***************\n\n";
	Matrix M(1, 4);
	M.init_rand(-8, 3);
	M.print();
	Matrix M1;
	M1.init_rand(-10, 10);
	M1.print();
	cout << "���������\n";
	(M + M1)->print();
	Matrix M2;
	M2.init_rand(-10, 20);
	M1.print();
	M2.print();
	cout << "���������\n";
	(M1 + M2)->print();
	cout << "\n*****************************************\n\n";
	_getch();
	cout << "\n*************������ � ������ �� � **********\n\n";
	M2.print();
	int i;
	cout << "� :"; cin >> i;
	M2(i);
	cout << "� :"; cin >> i;
	M2(i);
	cout << "� :"; cin >> i;
	M2(i);
	cout << "\n*****************************************\n\n";
	_getch();
	cout << "\n*************��������� ������� �������**********\n\n";
	M.print();
	cout<<"������������� ����� Det(M) = "<<M.Det()<<endl;
	Matrix M4;
	M4.init_rand(1, 10);
	M4.print();
	cout << "������������� ����� Det(M4) = " << M4.Det() << endl;
	cout.setf(ios::boolalpha);
	cout << "M>M4 :" << (M > M4) << endl;
	Matrix M_1;
	//M_1.init_vvod();
	M_1.init_rand(-10, 10);
	M_1.print();
	cout << "������������� ����� Det(M_1) = " << M_1.Det() << endl;
	Matrix M_4;
	//M_4.init_vvod();
	M_4.init_rand(-20,21);
	M_4.print();
	cout << "������������� ����� Det(M_4) = " << M_4.Det() << endl;
	cout.setf(ios::boolalpha);
	cout << "M_1>M_4 :" << (M_1 > M_4) << endl;
	cout << "\n*****************************************\n\n";
	_getch();
	cout << "\n*************�����������**********\n\n";
	cout << "B M1:\n";
	M_4.print();
	cout << "�� M2:\n";
	M.print();
	M_4 == M;
	cout << "��������� M_1 :\n";
	M_4.print();
	cout << "\n*****************************************\n\n";
	_getch();
	return 0;
}

