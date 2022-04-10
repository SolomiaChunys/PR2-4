#include "Matrix.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Matrix::Matrix() 
{
	size = 1;

	a = new Row[size];
	for (int i = 0; i < size; i++)
		a[i] = Row(size);
}

Matrix::Matrix(int r) 
{
	size = (r < 1) ? 1 : r; //перевірка

	a = new Row[size];
	for (int i = 0; i < size; i++)
		a[i] = Row(size);
}

Matrix::Matrix(int s, Row* f) 
{
	size = s;
	a = f;
}

Matrix::~Matrix()
{
	for (int i = 0; i < size; i++)
		if (a[i].column != nullptr)
			delete[] a[i].column;    //для стовпців матриці


	if (a != nullptr)
		delete[] a;    //для рядків матриці
}


Matrix& Matrix::operator =(Matrix& f)
{
	size = f.size;
	a = f.a;
	return *this;
}


Matrix::Row& Matrix::operator [](int n)
{
	return this->a[n];
}


Matrix::operator std::string()
{ 
	std::stringstream sout;

	sout << "size: " << size<< endl;
	sout << "Matrix: " << std::endl;


	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++)
			sout << "   " << (*this)[i][j];
		sout << endl;
	}


	return sout.str();
}


std::ostream& operator << (std::ostream& out, Matrix& s) 
{  
	out << "\nDisplay of matrix elements of size: " << s.size << "x" << s.size << endl;
	for (int i = 0; i < s.size; i++) {
		for (int j = 0; j < s.size; j++)
			out << "   " << s[i][j];
		out << endl;
	}
	return out;
}


std::istream& operator >> (std::istream& in, Matrix& s) 
{
	std::cout << "\nEntering the values of the elements of the matrix" << endl;
	for (int i = 0; i < s.size; i++) {
		for (int j = 0; j < s.size; j++) {
			std::cout << "object " << "[" << i << "]" << "[" << j << "] : ";
			in >> s[i][j];
		}
	}
	return in;
}

Matrix::Row::Row(int n)
{
	column = new int[n];

	for (int i = 0; i < n; i++)
		column[i] = 0;
}


int& Matrix::Row::operator [](int n) 
{ 
	return this->column[n];
}

void operator * (Matrix& A, Matrix& B) 
{ 
	Matrix C(A.size);
	if (A.size == B.size) 
	{
		for (int i = 0; i < A.size; i++) 
		{
			for (int j = 0; j < B.size; j++)
				C[i][j] += A[i][j] * B[i][j];
		}
		std::cout << "Matrix C:" << C << endl;
	}
	else
		std::cout << "Are not equal!";
}


double Matrix::NormMatrix()
{ 
	int norm{ 0 };
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++)
			norm += (int)pow((*this)[i][j], 2);
	}
	return sqrt(norm);
}


bool operator < (Matrix& A, Matrix& B) 
{
	bool f(A.size < B.size);
	return f;
}
bool operator > (Matrix& A, Matrix& B)
{
	bool f(A.size > B.size);
	return f;
}

bool operator == (Matrix& A, Matrix& B) 
{ 
	bool f = (A[0][0] == B[0][0]);
	return f;
}
