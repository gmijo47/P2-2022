/*Napisati program koji dinamièki zauzima memoriju za 20 stringova maksimalne duljine 
od 20 znakova, unosi stringove, sortira ih po duljini silazno, odnosno po abecedi (ako je 
duljina ista) te ih ispisuje. Koristiti iskljuèivo sintaksu pokazivaèa*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define vlc 20

void main() {
	

	char **strarr, pom[vlc];
	int i, j;
	
	//Allociranje memorije za pointere na clanove niza
	strarr = (char **) malloc(sizeof(char*) * vlc);

	for(i = 0; i < vlc; i++){
		
		//Alokacija memorije za 20 karaktera, tj svakog clana niza
		strarr[i] = (char*) malloc(sizeof(char) * vlc);
		
	}
	
	printf("Unesite %d stringova max duzine %d\n", vlc, vlc);
	for(i = 0; i< vlc; i++){
		gets(strarr[i]);
	}
	
	for(i = 0 ; i < vlc-1; i++){
		for(j = i+1; j < vlc; j++){
			if(strlen(strarr[i]) < strlen(strarr[j])){
					
					strcpy(pom, strarr[i]);
					strcpy(strarr[i], strarr[j]);
					strcpy(strarr[j], pom);
				
			}else if(strlen(strarr[i]) == strlen(strarr[j])){
				if(stricmp(strarr[i], strarr[j]) > 0){
					
					strcpy(pom, strarr[i]);
					strcpy(strarr[i], strarr[j]);
					strcpy(strarr[j], pom);
					
				}
			}
		}
	}
	puts("\n\nIspis");
	for(i = 0; i < vlc; i++){
		puts(strarr[i]);
	}
}
