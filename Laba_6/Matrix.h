#pragma once
class Matrix
{
	int n;//kol-vo strok
	int m;//kol-vo stolbtsov
	int **matrix;
public:
	int* operator()(int i);//i-aya stroka matrix
	int Det();
	Matrix();//matrix 3x3
	Matrix(int N, int M);// matrix NxM
	~Matrix();
	void print();//����� �������
	void init_vvod();//���� ��������� �������
	void init_rand(int min,int max);// ������� ��������� ��������� ������� �� min>=-99 �� max<1000
	friend Matrix* operator+ (const Matrix &m1,const Matrix &m2);//Slojenie matrixs
	friend bool operator>(Matrix &m1,  Matrix &m2);
	friend void operator==(Matrix &m1,const Matrix&m2);
};
