#include <stdio.h>

int main(){
	
	int fri, dnut, burg, tea, cof, jui, jumlah;
	char greeting[] = "WELCOME to MBOIS CHANTEEN";
	char nama[50];
	
	printf("\t\t\t %s\n", greeting);
	printf("\t\t\t===========================\n\n");
	
	printf("Input Your Name\t: ");
	
	scanf("%[^\n]s", nama);
	fflush(stdin);
	
	printf("\n\n\nHai %s,\n\n", nama);
	printf("MENU [Press 0 if u dont want to order]");
	
	printf("\n\nFried Fries Rp.20.000\t: ");
	scanf("%d", &fri);
	
	printf("Dougnat	Rp.15.000\t: ");
	scanf("%d", &dnut);
	
	printf("Burger	Rp.18.000\t: ");
	scanf("%d", &burg);
	
	printf("Tea	Rp.7.500\t: ");
	scanf("%d", &tea);
	
	printf("Coffee	Rp.10.000\t: ");
	scanf("%d", &cof);
	
	printf("Juice	Rp.15.000\t: ");
	scanf("%d", &jui);
	
	getchar();
	
	printf("\n\nPurchase List : \n");
	printf("Fried Fries\tx %d = Rp.%d\n", fri, fri*20000);
	printf("Dougnat\t\tx %d = Rp.%d\n", dnut, dnut*15000);
	printf("Burger\t\tx %d = Rp.%d\n", burg, burg*18000);
	printf("Tea\t\tx %d = Rp.%d\n", tea, tea*7500);
	printf("Coffee\t\tx %d = Rp.%d\n", cof, cof*10000);
	printf("Juice\t\tx %d = Rp.%d\n", jui, jui*15000);
	
	jumlah = (fri*20000)+(dnut*15000)+(burg*18000)+(tea*7500)+(cof*10000)+(jui*15000);
	printf("\nTotal\t\t= Rp.%d\n\n", jumlah);
	getchar();
	
	printf("\n Thankyou for Coming...");
	getchar();
	
	return 0;

}
