#include "stdafx.h"
#include "Matrix.h"
#include <iostream>
#include "time.h"
using namespace std;

Matrix::Matrix() : Matrix(3, 3)
{

}
Matrix::Matrix(int N, int M)
{
	n = N;
	m = M;
	matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
	}
}
Matrix::~Matrix()
{
	for (int i = 0; i < n; i++)
	{
		delete [] matrix[i];
	}
	delete[] matrix;
}
void Matrix::print()
{
	cout << "Матрица " << n << "x" << m << endl << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] < 10 && matrix[i][j] >= 0)
				cout << "  " << matrix[i][j]<<" " ;
			else
			if (matrix[i][j] < 100 && matrix[i][j] >0)
				cout <<" " <<matrix[i][j]<<" ";
			else
			if(matrix[i][j] < 0 && matrix[i][j]>-10)
				cout << " "<< matrix[i][j]<<" " ;
			else
				cout << matrix[i][j]<<" ";
		}
		cout << endl << endl;
	}
}
void Matrix::init_vvod()
{
	cout << "Введите элементы матрицы "<<n<<"x"<<m<<endl<<endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "M[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> matrix[i][j];
		}
	}
}

void Matrix::init_rand(int min, int max)
{
	if (min < -99) min = -99;
	if (max>999) max = 999;
	srand(unsigned(time(NULL)));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] =min + rand() % (max-min+1);
		}
	}
}


Matrix* operator+ (const Matrix &m1, const Matrix &m2)
{
	if (m1.n == m2.n && m2.m == m1.m)
	{
		Matrix*m = new Matrix(m1.n, m1.m);
		for (int i = 0; i < m1.n; i++)
		{
			for (int j = 0; j < m1.m; j++)
				m->matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
		}
		return m;
	}
	else
	{
		cout << "\nCЛОЖЕНИЕ НЕ ВОЗМОЖНО!\nРазмерности матриц не совпадают\n\n";
		Matrix*m = new Matrix(1, 1);
		m->matrix[0][0] = 0;
		return m;
	}

}

int* Matrix::operator()(int i)
{
	i--;
	if (i >= 0 && i < this->n)
	{
		cout << i+1<< "-ая сторка матрицы:\n";
		for (int v=0; v < this->m; v++)
			cout << this->matrix[i][v] << " ";
		cout << endl;
			return this->matrix[i];
	}
	else
	{
		cout << "Нет такой строки\nВозвращена первая\n";
		for (int v=0; v < this->m; v++)
			cout << this->matrix[0][v] << " ";
		cout << endl;
		return this->matrix[0];
	}
}

int Matrix::Det()
{
	int det=0,tj=0;
	if (n != m)
	{
		cout << "Матрица не является квадратной!\nОПРЕДЕЛИТЕЛЬ НЕ СУЩЕСТВУЕТ\n";
		return NULL;
	}
	if (n == 1 && m == 1)
		det = matrix[0][0];
	else
	if (n == 2 && m == 2)
	{
		det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	else
	{
		for (int j = 0; j < m; j++)
		{
			Matrix* temp = new Matrix(n - 1, m - 1);
			for (int i = 1; i < n; i++)
			{
				for (int v = 0, tj=0; v < m; v++)
				if (v != j)
				{
					temp->matrix[i-1][tj] = matrix[i][v];
					tj++;
				}
			}
			//cout << 1 << " Строка " << j + 1 << " Cтолбец Вычеркнуты из матрицы \n"<<matrix[0][j]<<endl;
			//this->print();
			//cout << "Результат\n";
			//temp->print();
			det += matrix[0][j]*pow(-1,(j + 1 + 1))*temp->Det();
		}
	}
	//cout << "DET(M) = " << det << endl;
	return det;
}

bool operator>( Matrix &m1,  Matrix &m2)
{
	return m1.Det() > m2.Det();
}
void operator== (Matrix &m1,const Matrix&m2)
{
	for (int i = 0; i < m1.n; i++)
	{
		delete[] m1.matrix[i];
	}
	delete[] m1.matrix;
	m1.n = m2.n;
	m1.m = m2.m;
	m1.matrix = new int*[m1.n];
	for (int i = 0; i < m2.n; i++)
	{
		m1.matrix[i] = new int[m1.m];
	}
	for (int i = 0; i < m1.n;i++)
	for (int j = 0; j < m1.m; j++)
		m1.matrix[i][j] = m2.matrix[i][j];
}