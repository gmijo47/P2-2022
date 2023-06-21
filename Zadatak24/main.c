#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*Napisati program koji uèitava sva slova iz datoteke tekst.txt i nakon svakog uèitanog 
znaka ispisuje, sortirane po abecedi sva do tada uèitana slova. Na kraju se ispisuje broj 
ponavljanja svakog od samoglasnika (ne vodeæi raèuna radi li se o velikim i malim 
slovima) */
void sort(char niz[], int br_cl){
	char pom;
	int i, j;
	
	for(i = 0; i< br_cl-1; i++){
		for(j = i+1; j < br_cl; j++){
			if(tolower(niz[i]) > tolower(niz[j])){
				pom = niz[i];
				niz[i]= niz[j];
				niz[j] = pom;
			}
		}
	}
	puts("\n----------------------------");	
	for(i = 0; i< br_cl; i++){
				printf("%c -", niz[i]);
			}
	puts("\n----------------------------\n\n");			
}

void samnum(int sam[], char znak){
	
	switch(znak){
		case 'A':
			case 'a': {
				sam[0]++;
				break;
			}
		case 'E':
			case 'e': {
				sam[1]++;
				break;
			}
		case 'I':
			case 'i': {
				sam[2]++;
				break;
			}
		case 'O':
			case 'o': {
				sam[3]++;
				break;
			}
		case 'U':
			case 'u': {
				sam[4]++;
				break;
			}
	}
	
}
void main() {
	
	FILE *dat = fopen("tekst.txt", "r");
	
	char znakovi[256], znak;
	int brz = 0, i, sam[5] = {0, 0, 0, 0, 0};
	
	while(!feof(dat)){
		znak = fgetc(dat);
		//fscanf(dat, "%c", &znak);
		if(znak != EOF && isalpha(znak)){
			znakovi[brz++] = znak;
			sort(znakovi, brz);
			samnum(sam, znak);
		}	
	}
	fclose(dat);
	puts("Broj samoglasmnika:");
	printf("A,a -> %d\n E,e-> %d \n I,i-> %d\n O,o-> %d\n U,u-> %d", sam[0], sam[1], sam[2], sam[3], sam[4]);
}
