#ifndef CHOSE4_H
#define CHOSE4_H

#include "Includes.h"
#include "Class.h"
#include "Utilities.h"
#include "Functions.h"

inline void RowCol_Product_of_Matrix() {
	int rows, cols;

	cout << "\nInsert the nr. of rows and cols (format: r c) of the matrix A: " << endl;
	cin >> rows >> cols;
	Matrix A(rows, cols);

	matrixFill(A);

	cout << "\nInsert the nr. of rows and cols (format: r c) of the matrix B: " << endl;
	cin >> rows >> cols;
	Matrix B(rows, cols);

	matrixFill(B);

	cout << "Matrix A :" << endl;
	matrixPrint(A);

	cout << "Matrix B :" << endl;
	matrixPrint(B);

	if (A.get_cols() != B.get_rows()) {
		cout << "Cols nr. of matrix A isn't equal to rows nr. of matrix B...!" << endl;
	}

	Matrix AB(A.get_rows(), B.get_cols());

	cout << "Matrix AB :" << endl;
	RowCol_Product(A, B, AB);

	matrixPrint(AB);

}


#endif // !CHOSE4_H
