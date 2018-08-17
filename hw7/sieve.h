#ifndef _SIEVE_H
#define _SIEVE_H
#include "bitarray.h"


int Sieve(BitArray&ba) 
{
	ba.Unset(0);
	ba.Unset(1);
	int primes;
	primes=2;
	while(primes*primes < ba.Length()) 
	{
		for(int i=primes+1;i<ba.Length();i++)
		{
			if(i%primes==0)
				ba.Unset(i);
		}
		for(int i = primes+1;i<ba.Length();i++)
		{
			// check to see if # is prime
			if(ba.Query(i)==true)
			{
				// reset prime
				primes= i;
				break;

			}
		}
	}
	return 0;
}


#endif
