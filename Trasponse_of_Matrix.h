#ifndef CHOSE3_H
#define CHOSE3_H

#include "Includes.h"
#include "Class.h"
#include "Utilities.h"
#include "Functions.h"

inline void Transpose_of_Matrix() {
	int rows, cols;

	cout << "\nInsert the nr. of rows and cols (format: r c) of the matrix A: " << endl;
	cin >> rows >> cols;
	Matrix A(rows, cols);

	matrixFill(A);

	cout << "Matrix A :" << endl;
	matrixPrint(A);

	Matrix At(A.get_cols(), A.get_rows());

	cout << "Transpose matrix of A :" << endl;
	matrixTransposed(A, At);

	matrixPrint(At);

}


#endif // !CHOSE6_H