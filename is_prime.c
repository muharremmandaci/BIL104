/* Libraries */
#include <stdio.h>
#include <conio.h>

/* Function Prototypes */
int is_prime(int );

/* Main Function */ 
int main()
{
	/*  Variables */
	int limit = 1000;
	int toplam = 0;

	/* counter */
	int i;	
	for (i = 2; i < limit; i++)
	{
		if (is_prime(i))
		{
			toplam += i;
		}
	}

	printf("%d\n", toplam);

	return 0;
}

/* Function Definitions */
int is_prime(int number)
{
	if (number == 2)
	{
		return 1;
	}

	/* counter */
	int i;
	/* control is_prime */
	for (i = 2; i < number; i++)
	{
		if(number % i == 0){
			return 0;//not prime
		}
	}
	return 1;//prime
}
