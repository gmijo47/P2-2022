#include <stdio.h>
#include <string.h>
#define num 5

//ret 1 if true
int ispal(char str[32]){
	int i = 0, j = 0, razlike = 0;
	char novi[32] = "";
	
	for(i = 0; i < strlen(str); i++)
		if(isalpha(str[i]))
			novi[j++] = toupper(str[i]);
	novi[j] = '\0';
	
	for(i = 0; i < strlen(novi) / 2; i++)
		if(novi[i] != novi[strlen(novi) - 1 - i])
			razlike++;
	
	if(razlike != 0)
		return 0;
	else
		return 1;
	
}
void main() {
	
	char rec[16][32];
	int i;
	
	for(i = 0; i < num; i++){
		fflush(stdin);
		gets(rec[i]);
	}
	
	puts("-----------------");
	
	
	for(i = 0; i < num; i++){
		
		if(ispal(rec[i])){
			
				puts(rec[i]);
				
		}
	

	}
	
}
