#include <stdio.h>
#include <string.h>

struct word {
	
	int no;
	char txt[128];
	int nosam;
	char slv;
	
};



void srt(struct word s[], int br_rj){
	
	int i, j;
	struct word pom;
	for(i = 0; i < br_rj; i++){
		
		for(j = i+1; j < br_rj; j++){
			
			if(s[i].nosam < s[j].nosam){
				
				pom = s[i];
				s[i] = s[j];
				s[j] = pom;
				
			}
			
		}
		
	}
	
}

char rpt(char s[]){
	
	int i, j, brp = 1, cnt;
	char c = s[0];
	
	for(i = 0; i < strlen(s); i++){
		
		 cnt = 1;
		 
		for(j = i+1; j < strlen(s); j++){
			if(s[i] == s[j]){
				cnt++;
			}
		}
		if(cnt > brp){
			c = s[i];
			brp = cnt;
		}
	}
	
	return c;
}

int is_sam(char c){
	int i;
	char sam[10] = "aeiouAEIOU";
	for(i = 0; i < 10; i++){
		
		if(sam[i] == c){
			return 1;
		}
		
	}
	return 0;
}
void main(){
	
	char recenica[128];
	int i, br_sl = 0, br_rj = 0;
	
	struct word rur[16];
	
	puts("Unesite neku recenicu");
	fflush(stdin);
	gets(recenica);
	
	
	for(i = 0; i <= strlen(recenica); i++){
		
		
		if(recenica[i] == ' ' || recenica[i] == '\0'){
			
			rur[br_rj].no = br_rj+1;
			rur[br_rj].txt[br_sl] = '\0';
			br_sl = 0;
			br_rj++;
			
		}else {	
			if(br_sl == 0){
				rur[br_rj].nosam = 0;
			}
			rur[br_rj].txt[br_sl] = recenica[i];
			if(is_sam(recenica[i])){
				rur[br_rj].nosam++;
			} 
			br_sl++;
		}

		
	}
	
	srt(rur, br_rj);
	
	for(i = 0; i < br_rj; i ++ ){
		
		printf("\n\nBroj rijeci: %d\n", rur[i].no);
		printf("Rijec: %s\n", rur[i].txt);
		printf("Broj samoglasnika: %d\n", rur[i].nosam);
		printf("Najvise slova: %c\n", rpt(rur[i].txt));
		
	}
		
	
	
	
}

