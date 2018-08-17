#include <iostream>
#include "temperature.h"
#include <ctype.h>
#include <iomanip>
using namespace std; 

//SetFormat how to get char to int
//weird error for const

Temperature::Temperature (double deg, char sc)
{ //set default temp and scale, as well as format
	degree = 0;
	scale = 'C';
	format = 'D';
	//if (SetScale(sc)==false)
	//	SetScale('C');
	//else
	//{
		degree = deg;
		scale = sc;
	//}
}

Temperature::Temperature ()
{
	degree=0;
	scale= 'C';
	format = 'D';
}

void Temperature::Input()
{ //makes it so user cannot type a temp less than absolute 0 per scale
	if (scale == 'c'||scale=='C')
		{ 
			if (degree<=-273.15)
			cout << "Invalid Temperature. Try again: ";
		}
	else if (scale == 'f' || scale == 'F')
		{
			if (degree<=-459.67)
			cout <<"Invalid Temperature. Try again: ";
		}
	else if (scale == 'k' || scale == 'K')
		{
			if (degree<0)
			cout <<"Invalid Temperature. Try again: ";
		}
	else 
		{
			cout << "Invalid Scale. Try again: ";
		}
}	
void Temperature::Show() const
{ //sets the desired format for each temp and scale
        switch (format)
        { 
         case 'P': //set to 1 decimal value, converts to capital var
               cout << setprecision(2);
                 if (scale == 'c' || scale== 'C')
                        cout << degree << " " << "C" << endl;
                else if (scale == 'f' || scale=='F')
                        cout << degree << " " << "F" <<endl;
                else if (scale == 'k' || scale == 'K')
                        cout << degree << " " << "K"<< endl;
		else
			cout << "error. "<<scale <<endl; 
                break;
        case 'L': //sets to 4 decimal places, also to long name of scale
                std::setprecision(5);
                if (scale == 'c'||scale == 'C')
                        cout << degree << " " << "Celsius"<<endl;
                else if (scale == 'f'||scale == 'F')
                        cout << degree << " " <<"Fahrenheit" << endl;
                else if (scale == 'k' || scale=='K')
                        cout << degree << " " <<"Kelvin" << endl; 
		else
			cout << "error "<<scale << endl;
		break;
        default: //resets to default value, 4 decimal and capital scale
                std::setprecision(5);
                if (scale == 'c' || scale == 'C')
                	cout << degree << " " << "C" << endl;        
                else if (scale == 'f' || scale == 'F')
                        cout << degree << " " << "F" << endl;
                else if (scale == 'k'||scale == 'K')
                      	cout << degree << " " << "K" << endl;
		else	
			cout <<"error " << scale <<endl;
		break;
	}	     
}

bool Temperature::SetScale (char s)
{ //if invalid scale is entered, default back to C
	if (s !='C' && s !='c' && s !='f' && s != 'F' && s
	!= 'K' && s != 'k')
	{	
		scale == 'C';
		return false;
	}
	else //if valid scale is entered, use that scale
	{
		s=scale;
		return true;
	}
}

double Temperature::GetDegrees() const
{ //returns valid degree 
	return degree;
}

char Temperature::GetScale() const
{ //returns valid scale
	return scale;
}

bool Temperature::SetFormat (char f)
{ //checks if used entered a valid format type
	if (f!='D'&& f!='d'&& f!='P' &&  f!='p' && f!='L' && f!='l')
		return false;
	else 
		return true;

}

void Temperature::Convert (char sc)
{ //converts to compare values, uses conversion formulas
	if (scale == 'f' || scale == 'F')
		{
			if (sc== 'c'||sc=='C')
			{
				degree=(degree-32)*(5.0/9.0);
			}
			if (sc=='k'||sc=='K')
			{
				degree=(degree+459.67)*(5.0/9.0);
			}
		}
	if (scale=='c' || scale=='C')
		{	
			if (sc=='f' || sc=='F')
			{
				degree=(degree*(9.0/5.0))+32;
			}
			if (sc=='k'||sc=='K')
			{
				degree=(degree+273.15);
			}
		}
	if (scale=='k' || scale=='K')
		{
			if (sc=='f' || sc=='F')
			{
				degree=(degree*(9.0/5.0))-459.67;
			}
			if (sc=='C' || sc=='c')
			{
				degree=degree-273;
			}
		}		
}

int Temperature::Compare ( Temperature& d)
{ //if first value is larger than second, returns 1, else -1, 0 if equal
	d.Convert(GetScale());
	if (d.degree > degree)
	return 1;
	else if (degree >d.degree)
	return -1;
	else
	return 0;
}

void Temperature::Increment (int deg, char&  sc)
{ //converts the values temporarily to test manipulate the degrees 
	Convert(sc);
	degree+=deg;
	
}
