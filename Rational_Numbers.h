#ifndef RATIONAL_NUMBERS_H
#define RATIONAL_NUMBERS_H

#include "Includes.h"

inline int mcd(int a, int b);

inline int mcm(int a, int b);

inline void Assert(bool exp, string s) {
	if (!exp) {
		cout << "Assertion failed...! " << s << endl;
		exit(-1);
	}
}

class Rational_Number {
private:
	int int_p;
	int fract_p;

public:
	Rational_Number(int i = 0, int f = 1) {
		Assert(f != 0, "Fraction part can't be equal to 0...!");
		int_p = i;
		fract_p = f;
	}

	void set(int i, int f = 1) {
		Assert(f != 0, "Fraction part can't be equal to 0...!");
		int max = mcd(i, f);
		while (max != 1) {
			i /= max;
			f /= max;
			max = mcd(i, f);
		}
		int_p = i;
		fract_p = f;
	}

	int get_int() const { return int_p; }

	int get_fract() const { return fract_p; }

	float get_real() const { return int_p / (float)fract_p; }

	inline void operator=(const Rational_Number& other) {
		int_p = other.get_int();
		fract_p = other.get_fract();
	}

};

ostream& operator<<(ostream& os, const Rational_Number& N) {
	if (N.get_int() % N.get_fract() == 0) return os << N.get_int()/N.get_fract();

	else if (N.get_int() < 0 && N.get_fract() < 0) return os << abs(N.get_int()) << "/" << abs(N.get_fract());

	else return os << N.get_int() << "/" << N.get_fract();
}

inline Rational_Number operator*(const Rational_Number& N1, const Rational_Number& N2) {
	Rational_Number prod(N1.get_int() * N2.get_int(), N1.get_fract() * N2.get_fract());

	return prod;
}

inline Rational_Number operator/(const Rational_Number& N1, const Rational_Number& N2) {
	Rational_Number rapp(N1.get_int() * N2.get_fract(), N1.get_fract() * N2.get_int());
	
	return rapp;
}

inline Rational_Number operator+(const Rational_Number& N1, const Rational_Number& N2) {
	int pf = mcm(N1.get_fract(), N2.get_fract());
	
	int pi = ((pf / N1.get_fract()) * N1.get_int()) + ((pf / N2.get_fract()) * N2.get_int());
	
	Rational_Number sum(pi, pf);
	
	return sum;
}

inline Rational_Number operator-(const Rational_Number& N1, const Rational_Number& N2) {
	int pf = mcm(N1.get_fract(), N2.get_fract());

	int pi = ((pf / N1.get_fract()) * N1.get_int()) - ((pf / N2.get_fract()) * N2.get_int());

	Rational_Number diff(pi, pf);

	return diff;
}

inline bool operator==(const Rational_Number& N1, const Rational_Number& N2) {
	if (N1.get_int() == N2.get_int() && N1.get_fract() == N2.get_fract()) return true;
	else return false;
}

inline bool operator!=(const Rational_Number& N1, const Rational_Number& N2) {
	if (N1.get_int() != N2.get_int() || N1.get_fract() != N2.get_fract()) return true;
	else return false;
}


#endif // !RATIONAL_NUMBERS_H