#include <stdio.h>
#include <string.h>
#define num 4

struct addr {
	char ulica[32];
	int kb;
	char mjesto[16];
	int pb;
};
void unos(struct addr p[], char m[]){
	
	int i;
	
	puts("Unesi podatke za 10 adresa:");
	for(i = 0; i < num; i++){
		printf("Adresa %d\n", i+1);
		puts("Ulica:");
		fflush(stdin);
		gets(p[i].ulica);
		puts("Kucni broj:");
		scanf("%d", &p[i].kb);
		puts("Mjesto:");
		fflush(stdin);
		gets(p[i].mjesto);
		puts("Postanski broj:");
		scanf("%d", &p[i].pb);
		printf("\n\n");
			
	}
	
	puts("Unesi dodatno mjesto:");
	fflush(stdin);
	gets(m);
	
	
}
void crarr(struct addr mjesta[], struct addr match[], int *brm, struct addr mismatch[], int *brmm, char mj[]){
	
	int i;
	for(i = 0; i < num; i++){
		
		if(strcmp(mjesta[i].mjesto, mj) == 0){
			
			match[*brm] = mjesta[i];
			(*brm)++;
			
		}else {
			mismatch[*brmm] = mjesta[i];
			(*brmm)++;
			
		}
		
	}
	
	
}
void sort(struct addr m[], int brc){
	
	int i, j;
	struct addr pom;
	
	for(i = 0; i < brc-1; i++){
		for(j = i+1; j < brc; j++){
			
			if(stricmp(m[i].ulica, m[j].ulica) == 0){
				
				if(m[i].kb > m[j].kb){
					
					pom = m[i];
					m[i] = m[j];
					m[j] = pom;
					
				}
						
			}else if(stricmp(m[i].ulica, m[j].ulica) > 0){
				
				pom = m[i];
				m[i] = m[j];
				m[j] = pom;
				
			}
			
		}
	}
	
	
}
void main() {
	
	struct addr p[32], m[32], mm[32];
	char dodmj[32];
	int broj_m = 0, broj_mm = 0, i;
	
	unos(p, dodmj);
	crarr(p, m, &broj_m, mm, &broj_mm, dodmj);
	sort(m, broj_m);
	sort(mm, broj_mm);
	
	puts("Adrese u unesenom mjestu su:");
	for(i = 0 ; i < broj_m; i++){
		
		printf("Ulica: %s\n", m[i].ulica);
		printf("Broj: %d\n", m[i].kb);
		printf("Postanski broj: %d\n\n", m[i].pb);
		
	}
	puts("Adrese van unesenog mjesta su:");
		for(i = 0 ; i < broj_mm; i++){
			
		printf("Mjesto: %s\n", mm[i].mjesto);
		printf("Ulica: %s\n", mm[i].ulica);
		printf("Broj: %d\n", mm[i].kb);
		printf("Postanski broj: %d\n\n", mm[i].pb);
		
	}
	
	
}
