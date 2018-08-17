#include <iostream>
#include "triangle.h"
#include <cmath>
using namespace std;

Triangle::Triangle(int s, char bord, char filler)
{
	if(s < 1)
		size = 1;
	else if (s > 39)
		size=39;
	else
        	size=s;

	
	if (SetBorder(bord)==false)
	{
		SetBorder('#');
	}

	if (SetFill(filler)==false)
		SetFill('*');
	
}

int Triangle::GetSize()
{
	return size;
}

int Triangle::Perimeter()
{
	int perimeter=size*3;
	return perimeter;	
}

double Triangle::Area()
{
 	double area = ((sqrt(3)/4)*(size*size));
	return area;	
}

void Triangle::Grow()
{
	if (size<39)
	size+=1;
}

void Triangle::Shrink()
{
	if (size>1)
	size-=1;
}

bool Triangle::SetBorder(char x)
{
	if (x < 33||x > 126)
	{
		border='#';
		return false;
	}
	else	
	{
		border=x;
		return true;	
	}
}

bool Triangle::SetFill(char y)
{
	if (y < 33||y > 126)
	{
		fill= '*';
		return false;
	}
	else 
	{
		fill= y;
		return true;

	}
}
void Triangle::Draw()
{
	for (int i=0; i<size;i++)
	{
     		if (i==0)
        	{
               	 for (int a=0; a<size-1;a++)
               	 cout <<" ";
               	 cout << border;
               	 cout << endl;
       	 	}
        	else if (i==1)
        	{
                	for (int b=0;b<size-2;b++)
                	cout << " ";
                	cout << border << " " << border <<endl;
        	}
        	else if (i>1 && i<size-1)
        	{
                	for (int c=i; c<size-1;c++)
                	{
                      	  cout << " ";    
                	}
                	cout << border;

			for (int d=0;d < i-1;d++)
				cout << " " << fill;

			cout << " " << border << endl;
	
		}
		else if(i == size - 1)
		{
			for(int e = 0; e < size - 1; e++)
				cout << border << " ";
				cout << border << endl;
		}
        }

}

void Triangle::Summary()
{
cout <<"Size of triangle's side = " << size << " units" << endl;
cout <<"Perimeter of triangle = " << Perimeter() <<" units" << endl;
cout <<"Area of triangle = "<< Area() << " units" << endl;
cout <<"Triangle looks like: " << endl;
Draw();
}


