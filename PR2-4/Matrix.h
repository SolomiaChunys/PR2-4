#pragma once
#include <iostream>
#include <string>
#include <iostream>
class Matrix
{
	class Row;

	int size;
	Row* a;

	class Row   //клас для ініціалізації елементів матриці
	{
	public:
		int* column;

		int* getColumn() const { return column; }
		void setColumn(int* value) { column = value; }

		Row(int n = 1);

		int& operator [](int);//індексація стовпця квадратної матриці
	};
public:
	Matrix();   
	Matrix(int);   
	Matrix(int, Row*); 
	~Matrix(); 

	Row& operator [] (int);
	Matrix& operator = (Matrix&); 

	operator std::string();


	friend std::ostream& operator << (std::ostream&, Matrix&);  
	friend std::istream& operator >> (std::istream&, Matrix&);	

	friend void operator *(Matrix&, Matrix&);
	double NormMatrix();          

	friend bool operator < (Matrix&, Matrix&); 
	friend bool operator > (Matrix&, Matrix&);    
	friend bool operator == (Matrix&, Matrix&);   

};

