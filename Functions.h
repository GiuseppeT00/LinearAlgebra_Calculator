#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Includes.h"
#include "Class.h"
#include "Utilities.h"

inline void matrixSum(Matrix& m1, Matrix& m2, Matrix& Sum) {//m2 will be summed on m1, so m1 will be m1 + m2 .
	for (int i = 0; i < m1.get_rows(); i++)

		for (int j = 0; j < m1.get_cols(); j++)

			Sum.set_value(i, j, m1.get_value(i, j) + m2.get_value(i, j));
}

inline void withScalar_Product(Matrix& M, Rational_Number scalar) {
	for (int i = 0; i < M.get_rows(); i++)

		for (int j = 0; j < M.get_cols(); j++)

			M.set_value(i, j, scalar * M.get_value(i, j));
}

inline void RowCol_Product(Matrix& M1, Matrix& M2, Matrix& Result) {
	Assert(M1.get_cols() == M2.get_rows(), "Cols of first matrix are different from rows of second matrix...!");
	
	Rational_Number val;
	
	for (int i = 0; i < M1.get_rows(); i++)
		
		for (int j = 0; j < M2.get_cols(); j++)
		{
			for (int n = 0; n < M1.get_cols(); n++) val = val + (M1.get_value(i, n) * M2.get_value(n, j));
			
			Result.set_value(i, j, val);
			
			val.set(0,1);
		}
}

inline void remove_RowCol(Matrix& M, Matrix& Mtemp, int row_to_remove, int col_to_remove) {
	int m = 0, n = 0;
	
	for (int i = 0; i < M.get_rows(); i++)
	{
		for (int j = 0; j < M.get_cols(); j++)
		{
			if (i != row_to_remove - 1 && j != col_to_remove - 1) {
				
				Mtemp.set_value(m, n, M.get_value(i, j));
				
				n++;
			}
		}
		if (n == Mtemp.get_cols()) m++;
		
		n = 0;
	}
}

inline Rational_Number determinant(Matrix& M) {
	Assert(M.get_cols() == M.get_rows(), "Rows nr. isn't equal to cols nr. ...!");
	
	if (M.get_cols() == 1 && M.get_rows() == 1) return M.get_value(0, 0);
	
	Rational_Number det;
	Rational_Number coeff;
	
	for (int k = 0; k < M.get_rows(); k++)
	{
		Matrix Mtemp(M.get_rows() - 1, M.get_cols() - 1);
		
		remove_RowCol(M, Mtemp, k + 1, 1);
		
		if (M.get_value(k, 0) != Rational_Number(0)) {

			coeff.set((int)pow(-1, k + 2));
			
			det = det + (M.get_value(k, 0) * coeff * determinant(Mtemp));
		}
	}
	
	return det;
}

inline void matrixTransposed(Matrix& M, Matrix& Trasp) {
	for (int i = 0; i < M.get_rows(); i++)
		
		for (int j = 0; j < M.get_cols(); j++) 
			
			Trasp.set_value(j, i, M.get_value(i, j));
}

inline void matrixReverse(Matrix& M, Matrix& Rev) {
	Assert(determinant(M) != 0, "Det(A)=0, so it isn't reversable...!");
	
	Matrix RevTemp(Rev.get_rows(), Rev.get_cols());

	Rational_Number k;
	
	for (int i = 0; i < M.get_rows(); i++)
	
		for (int j = 0; j < M.get_cols(); j++)
		{
			Matrix Mtemp(M.get_rows() - 1, M.get_cols() - 1);
		
			remove_RowCol(M, Mtemp, i + 1, j + 1);
			
			k.set((int)pow(-1, i + j + 2));

			RevTemp.set_value(i, j, (k * determinant(Mtemp)));
		}
	
	matrixTransposed(RevTemp, Rev);
	
	Rational_Number det = determinant(M);
	Rational_Number DetRev(det.get_fract(),det.get_int());

	withScalar_Product(Rev, DetRev);
}

inline int firstNotNull_Col(Matrix& M) {
	for (int i = 0; i < M.get_rows(); i++)
		for (int j = 0; i < M.get_cols(); i++)
			if (M.get_value(j, i).get_int() != 0) return i;
	return -1;
}

inline void rowSwap(Matrix& M, int r1, int r2, int start_col) { 
	Rational_Number temp;
	for (int i = start_col; i < M.get_cols(); i++)
	{
		temp = M.get_value(r1, i);
		M.set_value(r1, i, M.get_value(r2, i));
		M.set_value(r2, i, temp);
	}
}

inline void rowSum(Matrix& M, int r1, int r2, int start_col, Rational_Number& lambda) {
	for (int i = start_col; i < M.get_cols(); i++)
		M.set_value(r2, i, M.get_value(r2, i) - (lambda * M.get_value(r1, i)));
}

inline void gaussAlgorithm(Matrix& M, int row, int col) {
	if (row >= M.get_rows() || col >= M.get_cols()) return;

	if (M.get_value(row, col).get_int() == 0) {

		for (int i = row + 1; i < M.get_rows(); i++)

			if (M.get_value(i, col).get_int() != 0) {

				rowSwap(M, row, i, col);
				break;
			}
	}

	if (M.get_value(row, col).get_int() == 0) return;

	for (int i = row + 1; i < M.get_rows(); i++)

		if (M.get_value(i, col).get_int() != 0) {

			Rational_Number coeff = (M.get_value(i, col) / M.get_value(row, col));
			rowSum(M, row, i, col, coeff);
		}

	gaussAlgorithm(M, ++row, ++col);
}

inline int matrixRank(Matrix& M) {
	int c = firstNotNull_Col(M);

	if (c == -1) return 0;

	int pivot = 0;

	gaussAlgorithm(M, 0, c);

	for (int i = 0; i < M.get_rows(); i++)
		for (int j = 0; j < M.get_cols(); j++)
			if (M.get_value(i, j).get_int() != 0) {
				pivot++;
				break;
			}

	return pivot;
}

inline bool linearSystem_Compatibility(Matrix& A, Matrix& b) {
	Matrix A_b(A.get_rows(), A.get_cols() + b.get_cols());

	for (int i = 0; i < A_b.get_rows(); i++)

		for (int j = 0; j < A_b.get_cols(); j++)
		{
			if (j < A_b.get_cols() - 1) A_b.set_value(i, j, A.get_value(i, j));

			else A_b.set_value(i, j, b.get_value(i, 0));
		}

	if (matrixRank(A) == matrixRank(A_b)) return true;
	
	else return false;
}

#endif // !FUNCTIONS_H