/* Libraries */
#include <stdio.h>
#include <conio.h>

/*Function Prototypes*/
void calculationBanknote(int );

/* Main Function */
int main(){
	
	/* Variables */
	int requestedMoney = 0;
	
	printf("cekmek istediginiz para miktari : ");
	scanf("%d", &requestedMoney);
	
	/* check requested conditions */
	if (requestedMoney % 10 == 0)
	{
		calculationBanknote(requestedMoney);
	}

	else
	{
		printf("lütfen 10 ve 10'un katlarini giriniz!!!");
	}
		
	
	getch();

	return 0;
}

/* Function Definitions */
voids calculationBanknote(int requestedMoney){
	
	int x = 0, y = 0 ;

	int moneyTypes[5]={10,20,50,100,200};

/** 
*index 0 : Amount of 10 TL
*index 1 : Amount of 20 TL
*index 2 : Amount of 50 TL
*index 3 : Amount of 100 TL
*index 4 : Amount of 200 TL
**/
	int amountMoney[5]={250,35,40,18,12};

/**
*index 0 : 10 TL
*index 1 : 20 TL
*index 2 : 50 TL
*index 3 : 100 TL
*index 4 : 200 TL
**/
	int givenMoney[5]={0, 0, 0, 0, 0};
	
	x = (requestedMoney/100)*80;
	y = requestedMoney - x ;

	int i;

	for (i = 4 ; i >= 0; i-- ){
		while (x >= moneyTypes[i] && amountMoney[i]!=0)
		{
			x -= moneyTypes[i];
			
			givenMoney[i] += 1;
			
			amountMoney[i] -= 1;
		}
	}

	for (i = 0 ; i < 5; i++ ){
		while (y >= moneyTypes[i] && amountMoney[i]!=0)
		{
			y-=moneyTypes[i];
			
			givenMoney[i] += 1;
			
			amountMoney[i] -= 1;
		}
	}
	
	
	printf("\nIki Yuzluk Banknot :   %d \nYuzluk Banknot :       %d \nEllilik Banknot :      %d \nYirmilik Banknot :     %d \nOnluk Banknot :        %d \n",givenMoney[4],givenMoney[3],givenMoney[2],givenMoney[1],givenMoney[0]);

}
