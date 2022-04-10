#include <iostream>
#include "Matrix.h"

using namespace std;

int main(void) 
{
	int sizeA, sizeB;
	std::cout << "Matrix A:"<< endl;
	std::cout << "Enter the size: "; std::cin >> sizeA;
	std::cout << "Matrix B:"<< endl;
	std::cout << "Enter the size: "; std::cin >> sizeB;


	Matrix A(sizeA);
	Matrix B(sizeB);


	std::cout << "Matrix A:"; std::cin >> A;
	cout << endl;
	std::cout << "Matrix B:";std::cin >> B;
	cout << endl;

	std::cout << "Matrix A :";std::cout << A;
	cout << endl;
	std::cout << "Matrix B :";std::cout << B;
	cout << endl;

	A * B;

	std::cout << "Norm of matrix A: " << endl;
	std::cout << A.NormMatrix();
	cout << endl;

	std::cout << "Norm of matrix B: " << endl;
	std::cout << B.NormMatrix();
	cout << endl;

	std::cout << "Comparisons: " << endl;
	cout << endl;

	std::cout << "A < B: " << (A < B) << endl;
	std::cout << "A > B: " << (A > B) << endl;
	std::cout << "A = B: " << (A == B) << endl;

	return 0;
}
