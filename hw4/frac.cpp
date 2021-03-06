//--------------- FRAC.CPP ---------------
// The class definition for fractions.
//
// Bob Myers

#include "frac.h"	// iostream is already included in frac.h

// friend functions (operator overloads)

Fraction operator+(const Fraction& f1, const Fraction& f2)
{
   Fraction r;        // declare a Fraction to hold the result

   // load result Fraction with sum of adjusted numerators
   r.numerator = (f1.numerator*f2.denominator)
                  + (f2.numerator*f1.denominator);

   // load result with the common denominator
   r.denominator = f1.denominator * f2.denominator;

   return r;         // return the result Fraction
}

Fraction operator*(const Fraction& f1, const Fraction &f2)
{
	Fraction r;

	r.numerator= f1.numerator * f2.numerator;
	r.denominator= f1.denominator * f2.denominator;
	return r;
}

bool operator< (const Fraction& f1, const Fraction& f2)
{
   return (f1.numerator*f2.denominator < f2.numerator*f1.denominator);
}

bool operator> (const Fraction& f1, const Fraction& f2)
{
   return (f2 < f1);
}

bool operator== (const Fraction& f1, const Fraction& f2)
{
   return !(f1 < f2 || f2 < f1);
}

ostream& operator<< (ostream& os, const Fraction& f)
{  
  os << f.numerator << '/' << f.denominator;
  return os;
}





// member functions

Fraction::Fraction()
// Default constructor.  Initializes fraction to 0/1
{
   numerator = 0; 
   denominator = 1;
}

Fraction::Fraction(int n, int d)
// initializes fraction to n/d (defaults to 0/1 if invalid data)
{
   if (SetValue(n, d) == false)
	SetValue(0, 1);
}

void Fraction::Input()
// Get a fraction from standard input, in the form "numerator/denominator."
// what kind of error checking should be added?
{
   char divSign;	// used to consume the '/' character during input
   do
   {
      cin >> numerator >> divSign >> denominator;
      if (denominator <= 0)
	cout << "*** Denominator must be positive.  Try again: ";

   } while (denominator <= 0);
}

/* Commented out, because we're using operator<< now
 void Fraction::Show() const
 // Display a fraction, in the form "numerator/denominator."
 {
    cout << numerator << '/' << denominator;
 }
*/

int Fraction::GetNumerator() const
{
   return numerator;
}

int Fraction::GetDenominator() const
{
   return denominator;
}

bool Fraction::SetValue(int n, int d)
// sets fraction to n/d and returns true for success (good data)
// returns false and leaves fraction alone if bad data
{
   if (d <= 0)
	return false;

   numerator = n;
   denominator = d;
   return true;
}


double Fraction::Evaluate() const
// Calculates and returns the decimal value of a fraction
{
   return static_cast<double>(numerator) / denominator;
}


void Fraction::Simplify ()
{
/*	int negatory=0;
	int platypus;
	int start = numerator;
	if (start<0)
	{
	start=start*-1;
	negatory=1;
	}
      for (int i = start; i > 0; i--) 
	{  
                if ((denominator % i == 0) && (numerator % i == 0)) 
		{  
            		platypus=i;	
        	}             
         }
	if (platypus>0)
	{
	         denominator = denominator/ platypus;  
                 numerator = numerator/ platypus; 
	}
	
	if (numerator==0)
	{
		denominator=1;
	}
	if (negatory==1)
	{
	numerator = (numerator*-1);
	}
*/
int platypus = 0;
int start=numerator;
bool nope = false;

if (numerator<0)
        {       
        numerator = (numerator*-1);
        nope= true;
        }
        
for (int i=1; i<=numerator && i<=denominator; i++)
{
        if (numerator%i==0 && denominator%i==0)
                platypus = i;
}
if (platypus >0)
{
        numerator = numerator/platypus;
        denominator = denominator / platypus;

}
      if (numerator ==0)
	denominator = 1;
	if (nope ==true)
	numerator = (numerator *-1);	
}
	
