#include <stdio.h>
#define br 4

struct sport {
	
	char naziv[32];
	int broj_igraca;
	int trajanje;
};

void main() {
	
	int i, j;
	struct sport sportovi[br];
	struct sport pom;
	
	for(i = 0; i < br; i++){
		puts("Unesi ime sporta:");
		fflush(stdin);
		gets(sportovi[i].naziv);
		puts("Broj igraca");
		scanf("%d", &sportovi[i].broj_igraca);
		puts("Unesi trajanje (min)");
		scanf("%d", &sportovi[i].trajanje);

		
	}
	puts("__________________");
	
	//utakmica silazno, ako je isto uzlazno broj igraca na terenu
	for(i = 0; i < br; i++){
		for(j = i+1; j < br; j++){
			
			if(sportovi[i].trajanje != sportovi[j].trajanje){
				
					if(sportovi[i].trajanje < sportovi[j].trajanje){
					pom = sportovi[i];
					sportovi[i] = sportovi[j];
					sportovi[j] = pom;
				}
				
			}else {
				
				if(sportovi[i].broj_igraca > sportovi[j].broj_igraca){
					
					pom = sportovi[i];
					sportovi[i] = sportovi[j];
					sportovi[j] = pom;
					
				}
			
			}
			
		}
	}
	
	for(i = 0; i < br; i++){
		
		printf("Ime sporta: %s\n", sportovi[i].naziv);
		printf("Broj igraca: %d\n", sportovi[i].broj_igraca);
		printf("Trajanje %d min\n\n\n", sportovi[i].trajanje);

		
	}
	
	
}
