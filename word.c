/* Libraries */
#include <stdio.h>
#include <locale.h>

/* Main Function */
int main(){
	
	setlocale(LC_ALL,"Turkish");
	
	/* Variables */
	char array[500] = "Microsoft’s Surface PCs are known for their hinges. From the first, launched alongside Windows 8, to the new Surface Studio, each device has a hinge system that has evolved over time. That’s no accident, as the designers behind the scenes have been tweaking the Surface formula for years now. This latest creation, the Surface Studio, is designed to create an illusion of floating pixels. I met with the Surface Team last week to hear the history of the Surface and its latest Surface Studio hinge.";
	
	int a = 0,i = 0, b = 1, sayac = 0;
	
	/* Find number of the letters and words */ 
	while(array[a] != '\0')
	{
		if(array[a] == ' ')
		{
			b++;
		}
		a++;
	}
	
	
	printf("metin %d harf %d kelime \n", a-b-1, b);
	
	printf("ilk 5 kelime : ");
	
	/* print first five words */
	while(sayac != 5)
	{
		if(array[i] == ' ')
		{
			sayac++;
		}
		printf("%c", array[i]);
		i++;
	}
	
	return 0;
}