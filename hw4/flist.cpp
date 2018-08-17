#include <iostream>
#include "flist.h"
using namespace std;

FList::FList ():maxsize(20) 
{
	currentsize=0;	//default constructor, sets array size to 0
}

ostream& operator <<(ostream& os, const FList& f1)
{					//output operator overloader
	if (f1.currentsize==0)		//tells user if array is empty
		os << "List is empty.";
	else
	{
		os << f1.array[0];
		for (int i=1 ;i<f1.currentsize ; i++)
		{
		 os << ", " << f1.array [i];
		} 	
		//if array is not empty, prints fractions
	}
os <<"\n";
return os;
}

bool FList::Insert (const Fraction &f1)
{
	  if (currentsize<maxsize)
		{
		array[currentsize] = f1;
		currentsize++;
		return true;		//if the array is not full, allows user to 	
		}			//insert values at end of the array
	else
		return false;
}

bool FList::Insert (const Fraction& f1, int n)
{
	if (n>currentsize ||n<=0)
	{	cout << "**Invalid list position" << endl;
		return false;
	}
	else 			 //if the array is not full, allows 
	{					//user to input at specified 
						//location of array
		for (int i = currentsize; i>=n; i--)
		{
		if (i+1<20)
			array[i]=array[i-1];
		}
	currentsize++;
	array[n-1]=f1;
	return true;
	}
}

bool FList::Delete (int n)
{
	if (n>0 && n<currentsize )		//deletes specified fraction value 
						//in array
		{
		for(int i=n-1;i<currentsize; i++)
			{
				array [i] = array [i+1];
			}
		//	array[currentsize-1];
			currentsize--;
			return true;
		}
	else
		return false;
}

int FList::Size () const
{
	return currentsize; 	//returns current size of the array
}

Fraction FList::Sum () const	
{
	Fraction f1=0;		//adds all of the fractions in the array
	
	for (int i=0; i<currentsize;i++)
	{
	f1=f1+array[i];
	}
	f1.Simplify();
	return f1;	
}

double FList::Average () const
{
	Fraction fun = Sum();
	double avg = fun.Evaluate()/currentsize;
	return avg;
}

Fraction FList::Product (int min, int max) const
{	
	Fraction product(1);		//returnsproduct within a range of values in list 
	if (max<=currentsize && min>=0)	//between max and min
	{
	for (int i=min-1; i<max;i++)
		{
		product=product*array[i];
		}
	}
	product.Simplify();
	return product;
}

Fraction FList::Largest () const
{
	Fraction max = array[0];
	for (int i=0; i<currentsize; i++)	//returns largest fraction value in array
		{
		if (array[i]>max)
		{
		max=array[i];
		}
		}
	return max;
}

int FList::HowMany(const Fraction& f1)
{
	int counter = 0;		//user enters fraction value & returns
	SimplifyAll();			//# of fractions that mach in arry
	for (int i=0; i<currentsize; i++)
	{
		if (array[i] == f1)
			{
			counter=counter+1;
			}
	}
return counter;
}

void FList::SimplifyAll()
{
	for (int i=0; i<currentsize; i++)	//simplifies all values in array
	{
		array[i].Simplify();
	}
}

void FList::Clear()
{
	currentsize=0;		//clears all fractions in the array
}

Fraction FList::Rotate(int shift)
{
	if (shift>currentsize)
	shift=shift-currentsize;	//uses a temp to move around fractions
	else				//by amount that user enters
	{
		Fraction temp;
		for (int i=0; i<currentsize-shift; i++)
			{
			temp=array[i];
			array[i] = array [i+shift];
			array[i+shift]=temp;
			}
	}
}
