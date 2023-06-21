#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct data {
	
	char znak;
	int brp;
	
};

void main() {
	
	char str[32];
	struct data dataarr[26] = {0}, tmp;
	int i, j;
	
	
	puts("Unosi neke stringove (kraj za kraj)");
	do{
		
		fflush(stdin);
		gets(str);
		for(i = 0; i < strlen(str); i++){
			if(isalpha(str[i])){
				char s = toupper(str[i]);
				int idx = s - 'A';
				dataarr[idx].znak = s;
				dataarr[idx].brp++;	
			}
		}
		
	}while(stricmp(str, "kraj") != 0);
	
	    for (i = 0; i < 26 - 1; i++) {
       	 	for (j = i + 1; j < 26; j++) {
        	
            if (dataarr[i].brp < dataarr[j].brp) {
                tmp = dataarr[i];
                dataarr[i] = dataarr[j];
                dataarr[j] = tmp;
            }
        }
    }
    
	for(i = 0; i < 26; i++){
		if(dataarr[i].brp > 0){
			
			printf("%c,%d-", dataarr[i].znak, dataarr[i].brp);
			
		}
	}
	
}
