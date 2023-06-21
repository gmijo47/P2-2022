#include <stdio.h>
#include <string.h>


void main() {
	
	char str[10][16], pr[16], zr[16];
	int i;
	for(i = 0; i < 10; i++){
		gets(str[i]);
	}
	
	gets(pr);
	gets(zr);
	
	for(i = 0; i <= 10; i++){
		
		if(stricmp(pr, str[i]) < 0 && stricmp(zr, str[i]) > 0){
			
			puts(str[i]);
		}
	}
}
