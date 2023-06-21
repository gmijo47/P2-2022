#include <stdio.h>
#include <math.h>

/* Napisati program koji definira strukturu za zapis kompleksnih brojeva: realni i imaginarni 
dio (float), inicijalizira niz od 10 kompleksnih brojeva i u datoteku 
kompleksni_brojevi.txt upisuju se sortirani po udaljenosti od ishodišta kompleksne 
ravnine.  */
struct complex {
	float re;
	float im;
};

float modul (float re, float im){
	return sqrt((re * re) + (im * im));
}

void main() {
	
	struct complex pom, niz[10] = {{9.4, -3.7}, {-5.2, 1.3}, {8.9, -4.8}, {-2.1, -5.9}, {0.8, 2.3},
								{7.6, -9.1}, {3.5, -6.4}, {1.2, 7.9}, {6.8, -4.5}, {4.3, -6.7}};
	
	int i, j;
	
	for(i = 0; i < 9; i++){
		for(j = i+1; j < 10; j++){
			
		if(modul(niz[i].re, niz[i].im) < modul(niz[j].re, niz[j].im)){
		
				pom = niz[i];
				niz[i] = niz[j];
				niz[j] = pom; 
				
			}
			
		}
	}
	
	FILE *dat = fopen("kompleksni_brojevi.txt", "w");
	for(i = 0; i < 10; i++){
		fprintf(dat, "%.1f + %.1fi\n", niz[i].re, niz[i].im);
	}
	fclose(dat);
}
