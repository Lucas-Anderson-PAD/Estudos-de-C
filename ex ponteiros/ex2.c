#include <stdio.h>

void le_dados(int * end);
void maior(int n1, int n2, int * nmax);
float calculos(int n1, int n2, int * soma);



int main (void)
{	int num1, num2, max, soma;
	printf("Informe um numero inteiro");
	le_dados (&num1); // captura um número do teclado
	printf("Informe outro numero inteiro");
	le_dados (&num2);
	maior(num1, num2, &max);  // armazena em Max o maior valor entre os fornecidos
	printf("O maior numero eh %d ", max);
	printf("A media dos numeros eh %.1f ", calculos(num1, num2, &soma)); // obs
	printf("A soma dos numeros eh %d ", soma);
	return 0;
}

void le_dados(int * end){
    scanf("%d",end);
}

void maior(int n1, int n2, int * nmax){   
    if (n2> n1){
        *nmax = n2;
    }
    else{
        *nmax = n1;
    }
}

float calculos(int n1, int n2, int * soma){

    *soma= n1 +n2;
     
    float media = (float)*soma/2;
    return media;
}