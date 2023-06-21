#include <stdio.h>
#include <string.h>

struct car {
	char proizvodac[32];
	char model[16];
	int snaga;
	float price;
};

void main(){
	
	struct car auti[5];
	int i, max_pwr;
	float min_price;
	
	for(i = 0; i < 5; i++){
		
		printf("Auto %d\n", i+1);
		fflush(stdin);
		puts("Unesi proizvodaca:");
		gets(auti[i].proizvodac);
		
		puts("Unesi model:");
		gets(auti[i].model);
		
		puts("Unesi snagu:");
		scanf("%d", &auti[i].snaga);
		
		puts("Unesi cijenu:");
		scanf("%f", &auti[i].price);
		
		puts("");
		puts("");
		
		
	}
	
	puts("Unesi maksimalnu snagu");
	scanf("%d", &max_pwr);
	puts("Unesi minimalnu cijeu");
	scanf("%f", &min_price);
	
	
	for(i=0; i < 5; i++){
		
		if(auti[i].snaga < max_pwr && auti[i].cijena > min_price){
			
			printf("Proizvodac: %s\n Model %s\n Snaga %d\n Cjena %.2f\n\n", auti[i].proizvodac, auti[i].model, auti[i].snaga, auti[i].price);
			
		}
	}
	
	
}
