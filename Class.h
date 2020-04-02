#ifndef CLASS_H
#define CLASS_H

#include "Includes.h"
#include "Rational_Numbers.h"

class Matrix {
private:
	Rational_Number** m;
	int rows;
	int cols;

public:
	Matrix(int r = 0, int c = 0) { 
		rows = r;
		cols = c;
		m = new Rational_Number * [rows];
		for (int i = 0; i < rows; i++) m[i] = new Rational_Number[cols]();
	}

	~Matrix() { 
		for (int i = 0; i < rows; i++) delete[] m[i];
		delete[] m;
	}

	int get_rows() const { return rows; }

	int get_cols() const { return cols; }

	Rational_Number get_value(int r, int c) {
		Assert(r < rows && c < cols, "Parameters out of range...!");
		return m[r][c];
	}

	void set_value(int r, int c, Rational_Number val) {
		Assert(r < rows && c < cols, "Parameters out of range...!");
		m[r][c].set(val.get_int(),val.get_fract());
	}
};





#endif // !CLASS_H
