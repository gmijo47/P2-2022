/*Napisati program koji dinamièki alocira memoriju za niz realnih brojeva koji se unose sve 
dok neki od unesenih brojeva ne bude identièan prvom unesenom broju. Memorija se 
realocira prije svakog unosa broja tako da se koristi optimalno. Brojevi se ispisuju, 
sortirani silazno po velièini decimalnog dijela. Koristiti iskljuèivo sintaksu pokazivaèa*/
#include <stdio.h>
#include <stdlib.h>

void main() {
	
	float *niz, pom;
	int  n= 0, i, j;
	
	niz = (float *) malloc(sizeof(float)*2);

	
	do{
		if(n >= 2){
			niz = (float *) realloc(niz, sizeof(float)*(n+1));
		}
        scanf("%f", (niz + n));
        n++;
	} while (n < 2 || niz[0] != niz[n-1]);
	
	for(i = 0; i < n-2; i++){
		for(j = i+1; j < n-	1; j++){
			

			if(niz[i]-(int) niz[i] < niz[j] - (int) niz[j]){
				
				pom = niz[i];
				niz[i] = niz[j];
				niz[j] = pom; 
			}
			
		}
	}
	
	puts("\n\n");
	for(i = 0; i < n-1; i++){
		printf("%.3f\n", niz[i]);
	}
	free(niz);
}
