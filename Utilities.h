#ifndef UTILITIES_H
#define UTILITIES_H

#include "Includes.h"

inline void input(Rational_Number& val) {
	string value;
	string n = "", d = "";
	int int_p, fract_p;
	bool sep = false;

	cin >> value;
	
	for (char c : value)
	{
		if (!sep && c != '/') n += c;
		else if (c == '/') sep = true;
		else if (sep && c != '/') d += c;
	}

	istringstream pi(n);
	pi >> int_p;

	if (d != "" && d != "0") {
		istringstream pf(d);
		pf >> fract_p;
	}
	else fract_p = 1;

	val.set(int_p, fract_p);
}

inline void matrixFill(Matrix& M) {
	Rational_Number val;
	
	for (int i = 0; i < M.get_rows(); i++)
	{
		cout << "Insert the row n."<<i+1<<" (" << M.get_cols() << " values separated by space):" << endl;
		
		for (int j = 0; j < M.get_cols(); j++) {
			
			input(val);
			M.set_value(i, j, val);
		}
	}
}

inline int mcd(int a, int b) {
	int r = a % b;
	
	if (r == 0) return b;
	
	return mcd(b, r);
}

inline int mcm(int a, int b) {
	if (a == 0 || b == 0) return 0;
	
	return (a * b) / mcd(a, b);
}

inline void matrixPrint(Matrix& M) {
	for (int i = 0; i < M.get_rows(); i++)
	{
		for (int j = 0; j < M.get_cols(); j++) cout << "[" << M.get_value(i, j) << "] ";

		cout << endl;
	}
}


#endif // !UTILITIES_H