/* TODO: add file header comments here

 Workshop 5: Operator Overloading
 in_lab
 Name: Priya Khatri */


// TODO: insert header files
#include "Fraction.h"
#include <iostream>

// TODO: continue the namespace
using namespace std;
namespace sict {

	// TODO: implement the default constructor
	Fraction::Fraction() {
		numerator = -1;
		denominator = -1;

	}

	// TODO: implement the two-argument constructor
	Fraction::Fraction(int num, int den) {
		if (num >= 0 && den > 0) {
			numerator = num;
			denominator = den;
			reduce();
		}
		else {
			*this = Fraction();
		}
	}

	// TODO: implement the max query
	int Fraction::max()const {
		int result;
		if (numerator > denominator) result = numerator;
		else result = denominator;
		return result;
	}

	// TODO: implement the min query
	int Fraction::min() const {
		int result;
		if (numerator < denominator) result = numerator;
		else result = denominator;
		return result;
	}

	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;


		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int Ngcd = gcd();
		numerator /= Ngcd;
		denominator /= Ngcd;
	}

	// TODO: implement the display query
	void Fraction::display()const {
		if (denominator == 1) cout << numerator;
		else if (isEmpty()) cout << "no fraction stored";
		else cout << numerator << "/" << denominator;
	}

	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		if (numerator == -1 && denominator == -1) return true;
		else return false;
	}

	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction&rhs) const {
		if (isEmpty() || rhs.isEmpty()) {
			return Fraction();
		}
		else {
			int num = numerator * rhs.denominator + denominator * rhs.numerator;
			int den = denominator * rhs.denominator;
			Fraction result = Fraction(num, den);
			result.reduce();
			return result;
		}
	}
}