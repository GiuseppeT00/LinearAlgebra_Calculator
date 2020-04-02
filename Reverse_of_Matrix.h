#ifndef CHOSE6_H
#define CHOSE6_H

#include "Includes.h"
#include "Class.h"
#include "Utilities.h"
#include "Functions.h"

inline void Reverse_of_Matrix() {
	int rows, cols;

	cout << "\nInsert the nr. of rows and cols (format: r c) of the matrix A: " << endl;
	cin >> rows >> cols;
	Matrix A(rows, cols);

	matrixFill(A);

	cout << "Matrix A :" << endl;
	matrixPrint(A);

	if (A.get_rows() != A.get_cols() || determinant(A) == Rational_Number(0)) {
		cout << "Nr. of rows isn't equal to nr. of cols, or det(A)=0, so matrix A isn't reversable...!" << endl;
		return;
	}

	Matrix RevA(A.get_rows(), A.get_cols());

	cout << "Reverse matrix of A :" << endl;
	matrixReverse(A, RevA);

	matrixPrint(RevA);

}


#endif // !CHOSE6_H