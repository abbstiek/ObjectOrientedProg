#include <iostream>
#include "time.h"
using namespace std;

Time::Time()
{
	DefaultTime();
}

Time::Time(int s) // resets counter if it goes over 60 for s+m, 24 for hs, adds one to each before
{
	DefaultTime();
	seconds=s; 
       Convert();
}

Time::Time(int d, int h, int m, int s) //if invalid time is entered, sets to 0, also sets ints to member data
{
	if (d>=0)
	    days = d;
	else 
	    days=0;
	if (h>=0)       		
            hours = h;
	else
	   hours=0;	
       	if (m>=0)
	    minutes = m;
	else
	    minutes=0;
	if (s>=0)
            seconds = s;
	else 
	    seconds = 0;
}		

void Time::DefaultTime()
{
	days = 0;
	hours = 0;
	minutes = 0;
	seconds = 0;
}

ostream& operator <<(ostream& os, const Time& t1) //output function
{
	if (t1.days>1)
		os <<  t1.days << "~";
	else 
		os << "0" << "~" ;
		
	if (t1.hours>9)
		os << t1.hours << ":";
	else 
		os << "0" << t1.hours << ":";
	if (t1.minutes>9)
		os << t1.minutes << ":";
	else 
		os << "0" << t1.minutes <<":";
	if (t1.seconds>9)
		os << t1.seconds << endl;
	else
		os << "0" << t1.seconds << endl;
	return os;
}

istream& operator >>(istream& is, Time& t1) //input function
{	
	
	char x; 
	is >> t1.days >> x >> t1.hours >> x >> t1.minutes >>  x >> t1.seconds;
	t1.Convert(); 
	if (t1.days<0||t1.hours<0||t1.minutes<0||t1.seconds<0) //sets vals to 0
		t1.DefaultTime();
	return is;
}

Time operator+(const Time&t1, const Time& t2) //addition operator
{	
	Time AddResult; //will be used to store the result of the added values
	AddResult.days=t1.days+t2.days;
	AddResult.hours=t1.hours+t2.hours;
	AddResult.minutes=t1.minutes+t2.minutes;
	AddResult.seconds=t1.seconds+t2.seconds;
	return AddResult;
}


Time operator-(const Time&t1, const Time&t2) //subtraction operator
{
	Time SubResult; //used to store the result of the subtracted values
	SubResult.days=t1.days-t2.days;
	SubResult.hours=t1.hours-t2.hours;
	SubResult.minutes=t1.minutes-t2.minutes;
	SubResult.seconds=t1.seconds-t2.seconds;
	if (SubResult.days<0)
		SubResult.days=0;
	if (SubResult.hours<0)
		SubResult.hours=0;
	if (SubResult.minutes<0)
		SubResult.minutes=0;
	if (SubResult.seconds<0)
		SubResult.seconds=0;
	return SubResult;
}

Time operator*(const Time&t1, int x) //multiplication operator
{
	return Time(t1.days * x, t1.hours * x, t1.minutes * x, t1.seconds * x);
}

int Check (const Time& t1)
{
        int temp=0;
        temp = temp+ t1.seconds;
        temp =temp+(t1.minutes*60);
        temp = temp +(t1.hours*3600);
        temp = temp + (t1.days*86400);
        return temp;
}

bool operator<(const Time& t1, const Time& t2) //less than bool operator
{
	if (Check(t1)<Check(t2))
		return true;
	else
		return false;
}


bool operator>(const Time& t1, const Time& t2) //greater than bool operator
{
	if (Check(t1)>Check(t2))
		return true;
	else
		return false;
}

bool operator<=(const Time& t1, const Time& t2) //less than or equal to bool operator
{
	if (Check(t1)<=Check(t2))
		return true;
	else 
		return false;
}

bool operator>=(const Time& t1, const Time& t2) //greater than or equal to bool operator
{
	if (Check(t1)>=Check(t2))
		return true;
	else
		return false;
}

bool operator==(const Time& t1, const Time& t2) //if two values are equal, bool returns true
{
	if (Check(t1)==Check(t2))
		return true;
	else
		return false;
}

bool operator!=(const Time& t1, const Time& t2)// if two values are not equal, bool returns true
{
	if (Check(t1)!=Check(t2))
		return true;
	else
		return false;
}

Time& Time::operator++() //pre increment of time
{
	seconds=seconds+1;
	return *this;
}

Time Time::operator++(int) //post increment of time
{	
	Time temp = *this;
	seconds = seconds + 1;
	return temp;	
}

Time& Time::operator--() //pre decrement of time
{
	seconds = seconds - 1;
	return *this;
}

Time Time::operator--(int) //post decrement of time
{
	Time temp = *this;
	seconds = seconds - 1;
	return temp;
}

void Time::Convert ()
{
	do 
	{
	if (seconds>=60)
        {
                seconds-=60;
                minutes+=1;
        }
        if (minutes>=60)
        {
                minutes-=60;
                hours+=1;
        }
        if(hours>=24)
        {
                hours-=24;
                days+=1;
        }
	}while (hours>=24 || minutes>=60 || seconds>=60); 
}

void Time::Convert(int d, int h, int m, int s)
{
	do {
	if (h>=24)
		{
			h-=60;
			d+=1;
		}
	if (m>=60)
		{
			m-=60;
			h+=1;
		}
	if (s>=60)
		{
			s-=60;
			m+=1;
		}
		} while (h>=24 || m>=60 || s>= 60);
}
