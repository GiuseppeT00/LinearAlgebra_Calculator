#include "Includes.h"
#include "Menu.h"
#include "Sum_of_Matrix.h"
#include "Product_of_Matrix_with_Scalar.h"
#include "Trasponse_of_Matrix.h"
#include "RowCol_Product_of_Matrix.h"
#include "Determinant_of_Matrix.h"
#include "Reverse_of_Matrix.h"

int main() {
	ifstream header("Main_Menu1.txt");
	int chose;
	string str;

	while (getline(header, str)) cout << str << endl;

	while (true) {

		cout << endl;

		displayAll();

		cin >> chose;

		if (chose == 0) break;

		else if (chose == 1) Sum_of_Matrix();

		else if (chose == 2) Product_of_Matrix_with_Scalar();

		else if (chose == 3) Transpose_of_Matrix();

		else if (chose == 4) RowCol_Product_of_Matrix();

		else if (chose == 5) Determinant_of_Matrix();

		else if (chose == 6) Reverse_of_Matrix();

	}

	system("PAUSE");

	return 0;
}