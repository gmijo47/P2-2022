#include <stdio.h>
#include <string.h>

struct data {
	
	char znak;
	int brp;
};
void input(char str[]){
	
	puts("Unesi neki string");
	fflush(stdin);
	gets(str);
	
}
void sort(int n, struct data d[]){
	
	int i, j;
	struct data pom;
	
	for(i = 0; i < n-1; i++){
		for(j = i + 1; j < n; j++){
			
			if (d[i].brp < d[j].brp) {
				
                pom = d[i];
                d[i] = d[j];
                d[j] = pom;
                
            }
		}
	}
	
}
void sprtstr(char str[], struct data d[], int *n){
	int i, j;
	
	for(i = 0; str[i] != '\0'; i++){
		
		for(j = 0; j < *n; j++){
			
			if(str[i] == d[j].znak){
				d[j].brp++;
				break;
			} 
			
		}
		if(j == *n){
			d[*n].znak = str[i];
			d[*n].brp = 1;
			(*n)++;
		}
		
		
	}
	sort(*n, d);
}


void main() {
	
	char str[64];
	int n = 0, i;
	struct data d[32] = {0};
	
	input(str);
	sprtstr(str, d, &n);
	
	for(i = 0; i < n; i++){
		
		printf("%c(%d) ", d[i].znak, d[i].brp);
		
	}
	
	
	
	
}
