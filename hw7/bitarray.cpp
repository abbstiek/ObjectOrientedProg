#include <iostream>
#include "bitarray.h"
using namespace std;
 
BitArray::BitArray(unsigned int n)
{
	int arraysize;
	if((n%8)!=0)
		arraysize = (n/8)+1;
	else
		arraysize = (n/8);
	barray  = new unsigned char[arraysize];
	for (int i=0;i<arraysize; i++)
		this->barray[i] = 255;
	arraySize = n;
} 

// copy constructor
BitArray::BitArray(const BitArray& b)
{
	int arraysize;
	// converts bit array size to byte
	if( (b.arraySize % 8) != 0 )
		arraysize = (b.arraySize/8) + 1;
	else
		arraysize = (b.arraySize/8);
	this->barray = new unsigned char [arraysize];
	this->arraySize = b.arraySize;
	for(int i=0; i<arraysize;i++)
	this->barray[i]= b.barray[i];
}

//DESTRUCTOR
BitArray::~BitArray()
{
	delete [] barray;
}


ostream& operator<< (ostream& os, const BitArray& a)
{
	int arraysize;
	if((a.arraySize%8)!=0)
		arraysize = (a.arraySize/8) + 1;
	else
		arraysize = (a.arraySize/8);
	for (int i = 0; i<arraysize;i++)
	{
		int q=7;
		while (q>=0)
		{
			if ((a.barray[i]>>q)&0x01)
				os << "1";
			else
				os << "0";
			q--;
		}	
	}
	return os;
}

bool operator== (const BitArray& x, const BitArray& y)
{
	 if(x.arraySize== y.arraySize)
	 {
		 for(int i=0;i<x.arraySize/8; i++)
		{
			if(x.barray[i] != y.barray[i])
				return false;
		}
		 return true;
	 }
	 return false;

 }

bool operator!= (const BitArray& x, const BitArray& y)
 {
	 if(x.arraySize == y.arraySize )
	 {
		 for( int i = 0; i < x.arraySize/8; i++ )
		{
			if(x.barray[i] != y.barray[i] )
				return true;
		}
		 return false;
	 }
	 return true;

 }

BitArray& BitArray::operator= (const BitArray& x)
{
	for( int i = 0; i < x.arraySize; i++ )
	{
		this->barray[i] = x.barray[i];
	}
	this->arraySize = x.arraySize;
	return *this;
}

unsigned int BitArray::Length() const
{
	return this->arraySize;
}

void BitArray::Set (unsigned int index)
{
	switch(index%8)
	{
		case 7: 
		barray[index/8] = barray[index/8]|1;
		break;
	case 6: 
		barray[index/8] = barray[index/8]|2;
		break;
	case 5:
		barray[index/8] = barray[index/8]|4;
		break;
	case 4:
		barray[index/8] = barray[index/8]|8;
		break;
	case 3:
		barray[index/8] = barray[index/8]|16;
		break;
	case 2:
		barray[index/8] = barray[index/8]|32;
		break;
	case 1:
		barray[index/8] = barray[index/8]|64;
		break;
	case 0:
		barray[index/8] = barray[index/8]|128;
		break;
	default: cout << "Error. Index is less than 0.";
	} 
} 

void BitArray::Unset (unsigned int index)
{
	switch(index%8)
	{
	case 7: 
		barray[index/8] = barray[index/8]&~1;
		break;
	case 6: 
		barray[index/8] = barray[index/8]&~2;
		break;
	case 5:
		barray[index/8] = barray[index/8]&~4;
		break;
	case 4:
		barray[index/8] = barray[index/8]&~8;
		break;
	case 3:
		barray[index/8] = barray[index/8]&~16;
		break;
	case 2:
		barray[index/8] = barray[index/8]&~32;
		break;
	case 1:
		barray[index/8] = barray[index/8]&~64;
		break;
	case 0:
		barray[index/8] = barray[index/8]&~128;
		break;
	default: cout << "Error. Index less than 0. Cannot unset the bit.";
	}
}

bool BitArray::Query (unsigned int index) const
{
	char byte;
	// location of byte in array
	byte = barray[index/8];
	// shift index
	index = index%8;
	// if index == byte location
	if(index==7)
	{
		if((byte | 1) == byte)
			return true;
		else
			return false;
	} 
	if(index==6)
	{
		if( (byte | 2) == byte)
			return true;
		else
			return false;
	} 
	if(index==5)
	{
		if((byte|4)==byte)
			return true;
		else
			return false;
	}
	if(index==4)
	{
		if((byte|8)==byte)
			return true;
		else
			return false;
	}
	if(index==3)
	{
		if((byte|16)==byte)
			return true;
		else
			return false;
	}
	if(index==2)
	{
		if((byte|32)==byte)
			return true;
		else
			return false;
	}
	if(index==1)
	{
		if((byte|64)==byte)
			return true;
		else
			return false; 
	} 
	if(index==0)
	{
		if((byte | 128) == byte)
			return true;
		else
			return false;
	}
	return false;
} 
void BitArray::Flip( unsigned int index )
{
	char bytes;
	bytes = barray[((index/8)+1) ];
	if(index==7)
	{
		if(this->Query(index) == true )
			this->Unset(index);
		else
			this->Set(index);
	}

	if( index == 6 )
	{
		if( this->Query(index) == true )
			this->Unset(index);
		else
			this->Set(index);
	}
	

	if( index == 5)
	{
		if( this->Query(index) == true )
			this->Unset(index);
		else
			this->Set(index);
	}

	if( index == 4 )
	{
		if(this->Query(index)==true)
			this->Unset(index);
		else
			this->Set(index);
	}

	if(index==3)
	{
		if(this->Query(index)==true)
			this->Unset(index);
		else
			this->Set(index);
	} 

	if(index==2)
	{
		if( this->Query(index)==true)
			this->Unset(index);
		else
			this->Set(index);
	}

	if(index == 1)
	{
		if( this->Query(index)==true)
			this->Unset(index);
		else
			this->Set(index);
	}

	if(index==0)
	{
		if( this->Query(index)==true)
			this->Unset(index);
		else
			this->Set(index);
	}
}