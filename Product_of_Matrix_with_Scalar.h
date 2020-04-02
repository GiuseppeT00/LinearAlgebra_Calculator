#ifndef CHOSE2_H
#define CHOSE2_H

#include "Includes.h"
#include "Class.h"
#include "Utilities.h"
#include "Functions.h"

inline void Product_of_Matrix_with_Scalar() {
	Rational_Number lambda;
	int rows, cols;

	cout << "\nInsert the nr. of rows and cols (format: r c) of the matrix A: " << endl;
	cin >> rows >> cols;
	Matrix A(rows, cols);

	matrixFill(A);

	cout << "Insert the value of scalar: ";
	input(lambda);

	cout << "Matrix scalar * A:" << endl;
	withScalar_Product(A, lambda);
	matrixPrint(A);

}


#endif // !CHOSE2_H