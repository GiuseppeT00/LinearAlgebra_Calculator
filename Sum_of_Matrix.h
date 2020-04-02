#ifndef CHOSE1_H
#define CHOSE1_H

#include "Includes.h"
#include "Class.h"
#include "Utilities.h"
#include "Functions.h"

inline void Sum_of_Matrix() {
	int rows, cols;

	cout << "\nInsert the nr. of rows and cols (format: r c) of the matrix A: " << endl;
	cin >> rows >> cols;
	Matrix A(rows, cols);

	matrixFill(A);

	cout << "Matrix A:" << endl;
	matrixPrint(A);

	cout << "\nInsert the nr. of rows and cols (format: r c) of the matrix B: " << endl;
	cin >> rows >> cols;
	Matrix B(rows, cols);

	matrixFill(B);

	cout << "Matrix B:" << endl;
	matrixPrint(B);

	if (A.get_cols() != B.get_cols() || A.get_rows() != B.get_rows()) {
		cout << "Error. Number of rows or cols isn't the same for two matrixs." << endl;
		return;
	}

	Matrix S(A.get_rows(), A.get_cols());

	cout << "\nSum Matrix A + B :" << endl;
	matrixSum(A, B, S);

	matrixPrint(S);

}


#endif // !CHOSE1_H