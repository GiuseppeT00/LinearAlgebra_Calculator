#ifndef MENU_H
#define MENU_H

#include "Includes.h"

inline void displayAll() {

	ifstream menu("Main_Menu2.txt");
	string s;

	while (getline(menu, s)) cout << s << endl;
}

#endif // !MENU_H