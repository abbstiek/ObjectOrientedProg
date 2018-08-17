#include <iostream>
#include <cstring>
#include <cctype>
#include "myint.h"
using namespace std;

//C2I made by ~~~*BOB MYERS*~~~
// converts character into integer (returns -1 for error)
int MyInt::C2I(char c)
{
   if (c < '0' || c > '9')      return -1;      // error
   return (c - '0');                            // succecss
}

//constructor, expects regular int parameter set to 0
MyInt::MyInt(int n)
{
	currentsize=0;
	int temp;
	p= new int[maxsize];
	if (n>='0' ||n<='9') //if negative number is submitter, sets to 0
	{
	for (int i=0; n>0; i++)
		{
		temp=n%10;
		n=n/10;
		p[i]=temp;
		currentsize++;		
		 if (currentsize>=maxsize)//allows maxsize to increase
	        	Resize(); //with currentsize by 5
		}
	}
	else
{
	maxsize=1; 
	p[0]=0;//sets array to 0 if it is negative
}
}

MyInt::MyInt(char mystring[])
{ //sets maxsize and currentsize
//determines size of array
	maxsize=currentsize+4;
	currentsize = 0;
	int size;
	char ch;
	p= new int[maxsize];
	size=strlen(mystring);
	for (int i=0;i<size;i++)
	{	if (size==0)
		{
			p[i]=0;
		}
		if (currentsize>=maxsize)
			Resize();
	}		
}

MyInt::MyInt(const MyInt& x) //copies object 'x' into the new object 
				//being created
{ //sets member variables to work with constructor. copies dynamic array data to 
  maxsize = x.maxsize;  	//new array
  currentsize = x.currentsize; 
  // create a new dynamic array 
  p = new int[x.maxsize];
  // copy the dynamic data 
  for (int i = 0; i < currentsize; i++) 
    p[i] = x.p[i]; 
}
MyInt& MyInt::operator=(const MyInt& x) //copies object 'd' into new obj 
{
	if (this != &x)  
  { 
    //delete any information currently attached 
    delete [] p; 
    // basically the copy constructor
    maxsize = x.maxsize; 
    currentsize = x.currentsize; 
    p = new int[x.maxsize]; 
    for (int i = 0; i < currentsize; i++)  //copy dynamic data
      p[i] = x.p[i]; 
  } 
  return *this;     // return the object itself (by reference) 
}
MyInt::~MyInt()
{
	delete [] p; 	//DESTRUCTOR
}


// Add in operator overload and member function definitions 
ostream& operator <<(ostream& os, const MyInt& x)
{
	for (int i=0; x.p[i]!= '\0'; i++)
		os << x.p[i]; //goes through elements of array and prints them
	return os;
}
istream& operator >>(istream& is, MyInt& x) //input stream operator, 
{
	char temp;
	int i=0;
	x.Clear();
	if(isdigit(is.peek())) //check if its a digit, if so increment
	{ 	//or change it to an int
	do{	is >>temp;
		x.p[i]=x.C2I(temp);
		i++;
		x.maxsize++;
	}while(isdigit(is.peek())); //while it's a digit
	}
	return is;
}

MyInt operator+ (const MyInt& x, const MyInt& y)
{
	MyInt temp, temp2;
	temp=x;
	temp2=y;
	temp.Reverse(); //reverse both arrays to make addition easier
 	temp2.Reverse();
	MyInt z;
	int fun2 = 0; 
	for (int i = 0; i<z.currentsize; i++)
	{ //goes through values and adds them together
		z.p[i] = x.p[i] + y.p[i] + fun2;
		if (z.p[i]>9) //if value is bigger than 9 after addition, 
		{             //adds to the 10s place
			fun2 = z.p[i]/10;
			z.p[i] %10;
		}
	}
	return z;
}
bool operator< (const MyInt& x, const MyInt& y)
{ //tests if x array is less than y array
	if(x.currentsize<y.currentsize)
		return true;
	else if (x.currentsize > y.currentsize)
		return false;
	else //if it is greater than or equal to, return FALSE
	{
		for (int i=0; i<x.currentsize;i++)
		{
		if (x.p[i]>y.p[i])
		return false;
		else if (x.p[i]<y.p[i])
		return true;
		}
	}
//compare the # of elements in array
	return false; //if it reaches this point then all r same
}
bool operator>(const MyInt& x, const MyInt& y)
{
	if (x<y)
	return false; //uses other operator, returns false if its less than
	else if (x.currentsize>y.currentsize)
	return true;
	else 
	{
		for (int i=0; i<x.currentsize;i++)
		{ //goes through contents of array as well
			if (x.p[i]>y.p[i])
			return true;
			else if(x.p[i]<y.p[i])
			return false;
		}
	}
return true;
}
bool operator<= (const MyInt& x, const MyInt& y)
{ //runs equals to and less than to see if it's equal in size AND 
//has similar contents
	if (x<y || x==y)
	return true;
	else
	return false;
}
bool operator>= (const MyInt& x, const MyInt& y)
{//runs equal than and greater than to see if it's equal in size as well
//as similar in content
	if (x>y || x==y)
	return true;
	else
	return false;
}
bool operator== (const MyInt& x, const MyInt& y)
{
	//compare # of elements in array, then compare content
	int counter;
	if (x.currentsize<y.currentsize)
	return false;
	else if (x.currentsize>y.currentsize)
	return false;
	else if (x.currentsize==y.currentsize)
	{//goes through array and compares contents of the array
		for (int i=x.currentsize;i>=0; i--)
		{
		if (x.p[i]<y.p[i])
		return false;
		else if (x.p[i]>y.p[i])
		return false;
		else if(x.p[i]==y.p[i])
		{
		counter++;
		}
		}
	}
	if (counter==x.currentsize)
		return true;
}
bool operator!= (const MyInt& x, const MyInt& y)
{//tests if contents in array x and y are NOT equal in size/content
	if (x==y)
	return false;
	else
	return true;
}
MyInt operator* (const MyInt& x, const MyInt& y)
{// uses temp variables to set up a multiplication constructor
//if 
	int temp;
	int temp1;
	int temp2;
	MyInt tempy, tempy2;
	tempy=x;
	tempy2=y;
	if (x.maxsize>y.maxsize)
	{
	do
		{ //resizes if currentsize is too big
		if (((x.currentsize+y.currentsize)-1)>x.maxsize)	
			tempy.Resize();
		}while(((x.currentsize+y.currentsize)-1)> x.maxsize);
			temp1= x.maxsize;
	}
	else
	{	
		do
		{	//also resizes y if currentsize is too bixg
		if (((x.currentsize+y.currentsize)-1)>y.maxsize)
		tempy2.Resize();
		}while(((x.currentsize+y.currentsize)-1) >y.maxsize);
	temp1=y.maxsize; //sets var to maxsize
	}
	int array[temp1];
	int array1[temp1];
	for (int q = 0; q < temp1; q++)
	{
		array1[q] = 0;
	} //sets array to 0
	if (x.currentsize<y.currentsize)
	temp = x.currentsize;
	else
	temp=y.currentsize;
	//multiplies contents and takes care of moving numbers in the 10s place
	for (int i=0; i <=x.currentsize;i++)
	{
	for (int j=0; j<=y.currentsize;j++)
	{
	array[i]=x.p[i]*(y.p[j]*(10^j));
	array1[i]=array1[i]+ array[i];
	}
	}
return *array1;
}

MyInt& MyInt::operator++() //pre increment
{ //honestly, didn't really have time to complete this but 
//followed a layout similar to one in previous assignment
	p[currentsize-1]+=1;
	return *this;
}
MyInt MyInt::operator++(int) //post increment
{//same as the preincrement explanation, used a temp variable and increased
//size of array as well as adding a numb at end of array
	MyInt temp = *this;
	currentsize=currentsize+1;
	return temp;
}

void MyInt::Resize() //resize to allow for operator overloads
{//takes care of the difference in space that happens
//when multiplying or adding arrays together
 maxsize = currentsize+5;
 int * newarr = new int[maxsize]; //allocate a new array
for (int i=0; i<currentsize;i++)
	newarr[i]=p[i]; //copy each entry into new array
delete [] p; //remove old array 
p=newarr; //points old name to new array
}

int MyInt::showsize()
{//self explanatory, returns current size of the array
	return currentsize;
}

void MyInt::Reverse() //reverses all of the contents of the array
{//makes it easier to add values
	int temp, count;
	for (int i = 0; i< (count/2); ++i)
		{
		temp = p[count-i-1];
		p[count-i-1]=p[i];
		p[i]=temp;
		}
}

void MyInt::Clear() //creates a new array size 1, set to 0, delete old array
{ 
	maxsize=1;
	int* temporary = new int[maxsize];
	temporary[maxsize-1]=0;
	delete [] p;
	p = temporary;
	temporary =NULL;
}


