#ifndef CHOSE7_H
#define CHOSE7_H

#include "Includes.h"
#include "Class.h"
#include "Utilities.h"
#include "Functions.h"

inline void Gauss_algorithm() {
	int rows, cols;

	cout << "\nInsert the nr. of rows and cols (format: r c) of the matrix A: " << endl;
	cin >> rows >> cols;
	Matrix A(rows, cols);

	matrixFill(A);

	cout << "Matrix A :" << endl;
	matrixPrint(A);

	//Matrix At(A.get_cols(), A.get_rows());

	cout << "Matrix A after Gauss :" << endl;
	int c = firstNotNull_Col(A);
	if (c == -1) return;
	gaussAlgorithm(A, 0, c);

	matrixPrint(A);

}


#endif // !CHOSE7_H
