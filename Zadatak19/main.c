/*Napisati program koji dinamièki alocira memoriju za string koji se formira spajanjem 
unesenih stringova na naèin da se u obzir uzimaju samo velika slova engleskog alfabeta iz 
unesenih stringova. Memorija se realocira prije dodavanja svakog znaka u formirani 
string. Unos prestaje u trenutku kada broj samoglasnika u formiranom stringu bude veæi 
od 10. Nakon toga string se ispisuje. Koristiti iskljuèivo sintaksu pokazivaèa*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int brsug(char c[]){
	
	char sam[10] = "AEIOUaeiou";
	int i, j, n = 0;
	
	for(i = 0; i < strlen(c); i++){
		for(j = 0; j < 10; j++){
				if(c[i] == sam[j]){
					n++;
			}
			
		}
	}
	
	
	return n;
}
void main() {
	
	char *str, *newstr = NULL;
	int n = 0, i;
	str = (char *) malloc(sizeof(char)*32);
	newstr = (char *) malloc(sizeof(char));
	
	do{
		puts("Unesite string.");
		gets(str);
		for(i = 0; i < strlen(str); i++){
			if(isalpha(str[i]) && isupper(str[i])){
				newstr = (char *) realloc(newstr, sizeof(char)*(n+1));
				newstr[n] = str[i];
				n++;
			}
		}
		newstr[n] = '\0';
	}while(brsug(newstr) < 10);

	puts(newstr);
	free(str);
	free(newstr);
}
