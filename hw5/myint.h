#include <iostream>

using namespace std;
// starter file for MyInt class header
class MyInt
{ //input and output stream
	friend ostream& operator<<(ostream& os, const MyInt& x);
	friend istream& operator>>(istream&is, MyInt& x);
   friend MyInt operator+ (const MyInt& x, const MyInt& y);/*operator 
overloads*/
   friend bool operator< (const MyInt& x, const MyInt& y); //tests if x<y
   friend bool operator> (const MyInt& x, const MyInt& y); //tests if x>y
   friend bool operator<= (const MyInt& x, const MyInt& y);//tests if x<=y
   friend bool operator>= (const MyInt& x, const MyInt& y);//tests if x>=y
   friend bool operator== (const MyInt& x, const MyInt& y);//tests if x==y
   friend bool operator!= (const MyInt& x, const MyInt& y); //tests if x!=y
   friend MyInt operator* (const MyInt& x, const MyInt& y); //tests if x*y
public:
   MyInt(int n=0);	//constructor using int
   MyInt(char mystring[]);		// first constructor
   MyInt& operator++ ();	//[pre increment
   MyInt operator++(int);	//post increment
   MyInt (const MyInt& x); //COPY constructor
   MyInt& operator= (const MyInt &); //ASSIGNEMNT constructor
   ~MyInt (); //DESTRUCTOR, deletes array and contents
private:
	int *p; //pointer
	void Resize(); //resize integer array
	int C2I (char); //changes char to an int
	int showsize(); //returns currentsize of array
	int currentsize; //current size of the array
	int maxsize; //maximum size of the array (currentsize+5)
	void Reverse();//reverses all contents of the array,used w/ + operator
	void Clear(); //deletes all of the elements in the array
};

