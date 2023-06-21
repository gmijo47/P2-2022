#include <stdio.h>
#include <string.h>
struct city {
	char name[32];
	char cntry[32];
	int brst;
	char rvr[32];
	char mntn[32];
};

void unos(char p[], char m[]){
	
	puts("Unesi planinu:");
	fflush(stdin);
	gets(p);
	puts("Unesi rijeku:");
	fflush(stdin);
	gets(m);
	
}
void fltr(char pl[], char rj[], int *br, int *bp, struct city mp[], struct city mr[], struct city c[]){
	
	int i;
	for(i=0; i < 10; i++){
		if(strcmp(c[i].mntn, pl) == 0){
			
			mp[*bp] = c[i];
			(*bp)++;
			
		}else if(strcmp(c[i].rvr, rj) == 0){
			
			mr[*br] = c[i];
			(*br)++;
			
		}
		
		
	}
	
	
	
}
void srt(struct city c[], int n){
	
	int i, j;
	struct city pom;
	for(i = 0; i < n-1; i++){
		for(j=i+1; j < n; j++){
			if(c[i].brst > c[j].brst){
				
				pom = c[i];
				c[i] = c[j];
				c[j] = pom;
				
			}
		}
	}
	
}
void main() {
		
		struct city mr[10], mp[10], cities[10] = {
			{"Beograd", "Srbija", 1166000, "Dunav", "Avala"},
			{"Zagreb", "Hrvatska", 792875, "Sava", "Sljeme"},
			{"Ljubljana", "Slovenija", 292988, "Ljubljanica", "Smarna Gora"},
			{"Zenica", "Bosna i Hercegovina", 110663, "Bosna", "Vlasic"},
			{"Jajce", "Bosna i Hercegovina", 13759, "Vrbas", "Vlasic"},
			{"Jablanica", "Bosna i Hercegovina", 14267, "Neretva", "Prenj"},
			{"Sarajevo", "Bosna i Hercegovina", 275524, "Miljacka", "Bjelasnica"},
			{"Konjic", "Bosna i Hercegovina", 24555, "Neretva", "Bjelasnica"},
			{"Split", "Hrvatska", 178102, "Cetina", "Marjan"},
			{"Sinj", "Hrvatska", 142033, "Cetina", "Dinara"}
			
		};
		int br_r = 0, br_p = 0;
		char pl[32], rj[32];
		unos(pl, rj);
		fltr(pl , rj, &br_r, &br_p, mp, mr, cities);
		srt(mr, br_r);
		srt(mp, br_p);
		
		puts("Podatci o gradu za unesenu rijeku:");
		if(br_r == 0){
			
			puts("Nema podataka.");
			
		}else {
			printf("Grad : %s\n", mr[0].name);
			printf("Drzava : %s\n", mr[0].cntry);
			printf("Broj stanovnika : %d\n", mr[0].brst);
		}
		
		
		puts("Podatci o gradu za unesenu planinu:");
		if(br_p == 0){
			
			puts("Nema podataka.");
			
		}else {
			printf("Grad : %s\n", mp[0].name);
			printf("Drzava : %s\n", mp[0].cntry);
			printf("Broj stanovnika : %d\n", mp[0].brst);
		}
		
	
}
