#ifndef CHOSE5_H
#define CHOSE5_H

#include "Includes.h"
#include "Class.h"
#include "Utilities.h"
#include "Functions.h"

inline void Determinant_of_Matrix() {
	int rows, cols;

	cout << "\nInsert the nr. of rows and cols (format: r c) of the matrix A: " << endl;
	cin >> rows >> cols;
	Matrix A(rows, cols);

	matrixFill(A);

	cout << "Matrix A :" << endl;
	matrixPrint(A);

	if (A.get_cols() != A.get_rows()) {
		cout << "Rows nr. isn't equal to cols nr. ...!" << endl;
		return;
	}

	Rational_Number det = determinant(A);

	cout << "det(A) = " << det << endl;
}


#endif // !CHOSE5_H