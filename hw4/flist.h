#include "frac.h" 
#include <iostream>
const int MAX = 20;

class FList 
{
public:
	FList ();	//initialize an empty list
	friend std::ostream& operator << (ostream& os, const FList& output);
	bool Insert (const Fraction& f1);	//insert items into a 
	bool Insert (const Fraction & f1, int); //insert item into spec 
	bool Delete (int); 			//deletes specified array element
	int Size () const;			//returns current size of array
	Fraction Sum () const;			//adds all fractions together
	double Average () const;		//avg of all values
	Fraction Product (int, int) const;	//multiplies all fracitons together
	Fraction Largest () const; 	//returns largest fraction value
	int  HowMany (const Fraction& f1); //returns amt of frac that match usr inpt
	void SimplifyAll(); 	//simiplifies ALL elements of array
	void Clear();		//clears array contents
	Fraction Rotate(int);	//allows user to enter value to rotate fractions by

private:
	Fraction array [MAX]; //array that can hold up to 20 elements
	const int maxsize; //number of stored items, max is 20
	int currentsize; //current sie of the array
};
