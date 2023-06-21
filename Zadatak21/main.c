#include <stdio.h>
/*Napisati program koji od korisnika traži naziv datoteke u kojoj su zapisane izmjereni
vodostaji (realni brojevi) na odreðenom mjernom mjestu tijekom vremena. Proèitati sve 
vodostaje i odrediti prosjeèan vodostaj na tom mjernom mjestu
*/

int main() {
	
	FILE *dat;
	char naziv[64];
	float zn, sum = 0;
	int br = 0;
	
	puts("Unesi naziv datoteke u kojoj se nalaze podatci o vodostajima");
	gets(naziv);

	
	dat = fopen(naziv, "r");
	
	if(dat == NULL){
		
		puts("Ne valja naziv");
		return 0;
		
	}else {
		while(!feof(dat)){
			
			
			fscanf(dat, "%f\n", &zn);
			sum+=zn;
			br++;
		
	}
	}
	printf("Prosjecni vodostaj je %.2f", sum/br);
}
