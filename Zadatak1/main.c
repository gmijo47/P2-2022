#include <stdio.h>
#include <string.h>
#include <ctype.h>


void main() {

	char string[265], novi_string[256];	
	int i, j = 0;	
	
	puts("Molimo unesite neki tekst!");
	
	gets(string);
	
	 i = strlen(string);
	while(i >= 0){
	
	
		if(isalpha(string[i])){
			
			if(islower(string[i])){
				
				novi_string[j] = toupper(string[i]);
				j++;
				
			}else {
				
				novi_string[j] = tolower(string[i]);
				j++;
				
			}	
		}
		i--;
		}
		
		novi_string[j] = '\0';
		
		puts(novi_string);
		
}
