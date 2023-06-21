#include <stdio.h>

/* Napisati program koji sa tastature unosi cijele brojeve sve dok se ne unese broj 0. Nakon 
svakog unosa broj se smješta u datoteku uneseni_brojevi.txt. Nakon toga u datoteku 
sortirani_neparni_brojevi.txt pohranjuju se uneseni neparni brojevi sortirani po velièini.
 */

void main() {

	int broj, brub = 0, niz[128], i , j, pom;
	FILE *dat1, *dat2;

	puts("Unosite cijele brojeve (0 za kraj)");
	dat1 = fopen("uneseni_brojevi.txt", "r+");
	dat2 = fopen("sortirani_neparni_brojevi.txt", "w");
	
	do{
		
		scanf("%d", broj);
		fprintf(dat, "%d\n");
		niz[brub++] = broj;
		
	}while(broj != 0);
	
	for(i = 0; i < brub-2; i++){
		for(j = i+1; j < brub-1; j++){
			
			if(niz[i] < niz[j]){
				pom = niz[i];
				niz[i] = niz[j];
				niz[j] = pom;
			}
		}
	}
	
	for(i = 0; i < brub-1; i++){
		if(niz[i] % 2 == 1){
			fprintf(dat2, "%d\n", niz[i]);
		}
	}
	
}
