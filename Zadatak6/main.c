#include <stdio.h>

	struct complex{
	float Re;
	float Im;
	}z1, z2;
	
struct complex zbroj(struct complex z1, struct complex z2){
	
	struct complex sum;
	
	sum.Re = z1.Re + z2.Re;
	sum.Im = z1.Im + z2.Im;
	
	return sum;	
}

struct complex razlika(struct complex z1, struct complex z2){
	
	struct complex raz;
	
	raz.Re = z1.Re - z2.Re;
	raz.Im = z1.Im - z2.Im;
	
	return raz;	
}

struct complex umnozak(struct complex z1, struct complex z2){
	
	struct complex um;
	
	um.Re = (z1.Re * z2.Re) - (z1.Im * z2.Im);
	um.Im = (z1.Re * z2.Im) + (z1.Im * z2.Re);
	
	return um;	
}

struct complex kolicnik(struct complex z1, struct complex z2){
	
	struct complex kol;
	
	//https://prnt.sc/WK0TkgkTfRPD
	kol.Re = (((z1.Re * z2.Re) + (z1.Im * z2.Im)) / ((z2.Re * z2.Re) + (z2.Im * z2.Im)));
	kol.Im = (((z1.Im *z2.Re) - (z1.Re *z2.Im)) / ((z2.Re * z2.Re) + (z2.Im * z2.Im)));
	
	return kol;	
}

void main(){
	

	
	puts("Unesi prvi komplekni broj z1");
	scanf("%f %f", &z1.Re, &z1.Im);
	
	puts("Unesi drugi komplekni broj z2");
	scanf("%f %f", &z2.Re, &z2.Im);
	
	
	//z1+z2 = Re(z1+z2) + Im(z1+z2)
	//z1-z2 = Re(z1-z2) + Im(z1-z2)
	//(3+2i) * (2 + 2i) = (3 * 2) + (3*2i) + (2i * 2) + (2i*2i)
	//(3+2i) / (2+2i) = ((3*2 + 2 * 2) + (2*2 - 3 * 2)i)/ (2^2 + 2^2)
	
	
	
	printf("Suma je %.1f + %.1fi\n", zbroj(z1, z2).Re, zbroj(z1, z2).Im);
	printf("Razlika je %.1f + %.1fi\n", razlika(z1, z2).Re, razlika(z1, z2).Im);
	printf("Umnozak je %.1f + %.1fi\n", umnozak(z1, z2).Re, umnozak(z1, z2).Im);
	printf("Kolicnik je %.1f + %.1fi\n", kolicnik(z1, z2).Re, kolicnik(z1, z2).Im);


}
