#include <stdio.h>
#include <string.h>

struct s {
	
	char ime[32];
	char studiji[64];
	int semestar;
	float prosjek;
	
};

float prosjek(struct s st[], int brst){
	
	float prosjek = st[0].prosjek;
	int i;

	for(i = 0; i < brst; i++){
		
		if(st[i].prosjek > prosjek){
			prosjek = st[i].prosjek;
		}
			
	}
	return prosjek;
}

void sort(struct s st[], int brst){
	
	int i, j;
	struct s pom;
	
	for(i=0; i < brst; i++){
		
		for(j = i+1; j < brst; j++){
			
			if(strcmp(st[i].ime, st[j].ime) > 0)
			{
				pom = st[i];
				st[i] = st[j];
				st[j] = pom;
				
			}
			
		}
	}
	
}
	
void ispis(struct s st[], int brst){
	
	int i;
	if(brst == 0){
		puts("Nema studenata.\n\n");
	}else{
		sort(st, brst);
		for(i = 0; i < brst; i++){
			printf("Ime: %s\nSemestar: %d\nProsjek: %.1f\n\n", st[i].ime, st[i].semestar, st[i].prosjek);
			
		}
		printf("\n");
		printf("Broj studenata: %d\n Najveci prosjek %.1f\n\n\n", brst, prosjek(st, brst));
	}
	
}

void main() {
		
	struct s ns[5], str[5], rac[5], ele[5];
	int i, brstr = 0, brrac = 0, brele = 0;
		for(i=0; i < 5; i++){
		
		puts("Unesi ime i prezime");
		fflush(stdin);
		gets(ns[i].ime);
		
		puts("Unesi studiji (strojarstvo, racunarstvo i elektrotehnika.)");
		
		
		do{
			
			fflush(stdin);
			gets(ns[i].studiji);
			
		}while(stricmp(ns[i].studiji, "strojarstvo") != 0 &&
			stricmp(ns[i].studiji, "racunarstvo") != 0 &&
			stricmp(ns[i].studiji, "elektrotehnika") != 0);
			
		puts("Unesi semestar");
		fflush(stdin);
		scanf("%d", &ns[i].semestar);
		
		
		puts("Unesi prosjek");
		fflush(stdin);
		scanf("%f", &ns[i].prosjek);
		
	}	
	
	for(i = 0; i < 5; i++){
		if(stricmp(ns[i].studiji, "strojarstvo") == 0){
				str[brstr] = ns[i];
				brstr++;
			}else if(stricmp(ns[i].studiji, "racunarstvo") == 0){
				rac[brrac] = ns[i];
				brrac++;
			}
			else if(stricmp(ns[i].studiji, "elektrotehnika") == 0){
				ele[brele] = ns[i];
				brele++;

			}
		}

	
	puts("-------------------------\n\n\n");
	puts("Elektrotehnika:");
	ispis(ele, brele);
	
	puts("Racunarstvo:");
	ispis(rac, brrac);
	
	puts("Strojarstvo:");
	ispis(str, brstr);
	
	
		
		
}
