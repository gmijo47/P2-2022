#include <stdio.h>
#include <string.h>

/*Napisati program koji iz datoteke drzave.txt �ita podatke o svim dr�avama zapisanima u 
datoteci: naziv dr�ave (string - pretpostaviti da se radi o jednoj rije�i), glavni grad (string -
pretpostaviti da se radi o jednoj rije�i), kontinent (string - pretpostaviti da se radi o 
jednoj rije�i), povr�ina dr�ave u kvadratnim kilometrima (int) i broj stanovnika (int). 
Nakon toga ispisuju se podaci o azijskim dr�avama sa manje od 10.000.000 stanovnika 
sortirani po broju stanovnika dr�ave uzlazno.*/
struct drzave {
	char n[32];
	char gg[32];
	char cnt[32];
	int prs;
	int brs;
};
void main() {
		struct drzave d[15], pom;
		int brc = 0, i, j;
		FILE *dat = fopen("drzave.txt", "r");
		
		while(!feof(dat)){
			fscanf(dat, "%s %s %s %d %d", &d[brc].n, &d[brc].gg, &d[brc].cnt, &d[brc].prs, &d[brc].brs);
			brc++;
		}
		
		for(i = 0; i< brc-1; i++){
			for(j = i+1; j < brc; j++){
				if(d[i].brs > d[j].brs){
					pom = d[i];
					d[i] = d[j];
					d[j] = pom;					
				}
			}
		}
		puts("-----------------\n");
		for(i = 0; i < brc-1; i++){
		if(stricmp("Azija", d[i].cnt) == 0 && d[i].brs < 10000000){
				printf("%s %s %s %d %d\n", d[i].n, d[i].gg, d[i].cnt, d[i].prs, d[i].brs);
			}
		}
		
		

}
