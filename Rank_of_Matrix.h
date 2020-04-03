#ifndef CHOICE8_H
#define CHOICE8_H

#include "Includes.h"
#include "Class.h"
#include "Utilities.h"
#include "Functions.h"

inline void Rank_of_Matrix() {
	int rows, cols;

	cout << "\nInsert the nr. of rows and cols (format: r c) of the matrix A: " << endl;
	cin >> rows >> cols;
	Matrix A(rows, cols);

	matrixFill(A);

	cout << "Matrix A:" << endl;
	matrixPrint(A);

	cout << "The rank of matrix A, rg(A) = " << matrixRank(A) << endl;

}








#endif // !CHOICE8_H