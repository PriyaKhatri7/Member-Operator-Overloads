/* TODO: add file header comments here

 Workshop 5: Operator Overloading
 in_lab
 Name: Priya Khatri */


// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

// TODO: create namespace
namespace sict {

	// TODO: define the Fraction class
	class Fraction {

		// TODO: declare instance variables 
		int numerator; //valid and denomiator is unit_valued
		int denominator;//if its not unit-valued

		// TODO: declare private member functions
		int max() const; //returns greater of the num and den
		int min() const; //returns lesser of the num and den
		void reduce(); //reduces by diving the greatest common den
		int gcd() const; //GCD of num and den

	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int num, int den);
		bool isEmpty() const; //returns ture if object is in safe empty state
		void display() const;

		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;

	};
}

#endif //!SICT_FRACTION_H