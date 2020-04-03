#ifndef CHOICE9_H
#define CHOICE_H

#include "Includes.h"
#include "Class.h"
#include "Utilities.h"
#include "Functions.h"

inline void Linear_System_Compatibility() {
	int equations, unknown;

	cout << "\nThe linear system will be in the format AX=b , so you need to insert the:" << endl;
	cout << "-Incomplete matrix A;" << endl;
	cout << "-Known terms vector b;" << endl;
	cout << "The programm will automatically write the unknown terms vector X." << endl;

	cout << "Insert the nr. of equations and unknown variables (format: e v) of the linear system: " << endl;
	cin >> equations >> unknown;

	Matrix A(equations, unknown), b(equations,1);

	cout << "Insert the incomplete matrix A:" << endl;
	matrixFill(A);

	cout << "Insert the known values vector b:" << endl;
	matrixFill(b);
	
	linearSystem_Print(A, b);

	if (linearSystem_Compatibility(A, b))
		cout << "The linear system is compatible, and solutions depends on " << A.get_cols() - matrixRank(A) << " parameters" << endl;
	else
		cout << "The linear system is incompatible, so there isn't any solution." << endl;

}


#endif // !CHOICE9_H

