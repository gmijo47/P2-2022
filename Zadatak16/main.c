/*Napisati program koji pita korisnika kolika je dimenzija niza cijelih brojeva, dinami�ki 
alocira memoriju za taj niz i unosi brojeve, a zatim unosi i dodatni cijeli broj u tako�er 
dinami�ki alociranu memoriju te na kraju ispisuje, sortiran po veli�ini, samo one brojeve 
iz niza koji su ve�i od dodanog broja. Koristiti isklju�ivo sintaksu pokaziva�a*/
#include <stdio.h>
#include <stdlib.h>

void main() {
	
	int *dim, *niz, i, j, *dod, *pom;
	
	dim = (int *) malloc(sizeof(int));
	pom = (int *) malloc(sizeof(int));
	
	
	puts("Kolika je dimenzija niza");
	scanf("%d", dim);
	
	niz = (int*) malloc(sizeof(int)* *(dim));
	
	puts("Unosi clanove niza");
	for(i = 0; i < *dim; i++){
		scanf("%d", niz+i);
	}
	
	dod = (int *) malloc(sizeof(int));
	puts("Unesi dodatni broj");
	scanf("%d", dod);
	

	for(i = 0; i < *(dim)-1; i++){
		for(j = i+1; j<*dim; j++){
			if(*(niz+i) < *(niz+j)){  
				
				*pom = *(niz+i);
				*(niz+i) = *(niz+j);
				*(niz+j) = *pom;
				
			}
		}
	}
	puts("To su brojevi:");
	for(i=0; i < *dim; i++){
		if(*(niz+i) > *dod){
			printf("%d\n", *(niz+i));
		}
	}
	
	
	
	
}
