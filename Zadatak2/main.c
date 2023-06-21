#include <stdio.h>
#include <string.h>

void rplc(char a[][32], int ai, int bi){
	
	char pom[32];
	
	strcpy(pom, a[ai] + 0);
	strcpy(a[ai] + 0, a[bi] + 0);	
	strcpy(a[bi] + 0, pom);
	
}
void main() {
	
	char str[32][32], pom[32];
	int i,j, br = 0, c = 1;
	
	while(c){
		
		gets(str[br]);
		for(i = 0; i < br; i++){
			if(!stricmp(str[br], str[i])){
				c = 0;
			}
		}
		br++;
		
	}
	
	for(i = 0; i < br-1; i++){
		
		for(j = i+1; j < br-1; j++){
			
			if(strlen(str[i]) == strlen(str[j])){
				
			if(stricmp(str[i], str[j]) > 0){    			
				
				rplc(str, i, j);
				
			}
			
			}else if(strlen(str[i] > strlen(str[j]))){
			
				rplc(str, i, j);
			
			}
			
		}
	}
	
	for(i = 0; i < br-1; i++){
		puts(str[i]);
	}
	
}
