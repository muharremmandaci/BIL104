/* Libraries */
#include <stdio.h>

/* Main Function */
int main(){
	
/* Variables */
int limit = 0;
int mem =0, x = 0, a = 0, min = 0;


printf("Kac sayi girisi yapacaksiniz : ");
scanf("%d", &limit);

int numbers[limit];

/* Input Array Numbers */
int i;
for(i = 0 ; i < limit ; i++  )
{
	printf("sayi-%d : ",i+1);
	scanf("%d", &numbers[i]);	
}

/* Sorting */
for(i = 0 ; i < limit ; i++)
{
	
	min = numbers[x];

	int j;
	for(j = x ; j < limit ; j++)
	{	
		if(numbers[x] > numbers[j]){
			mem = numbers[x];
			numbers[x] = numbers[j];
			numbers[j] = mem;
		}	
	}	

	x++;
}

/* Print Sorted Numbers */
for(i = 0 ; i < limit ; i++  )
{
	printf("%d\n",numbers[i]);	
}	
	
	return 0;
}

