#include <stdio.h>

int main(void){
    int a;
    int b;
    int *pa = &a;
    int *pb = &b;

    printf("Digite o valor de dois numeros inteiro");
    scanf("%d\n%d",pa,pb);


    printf("%d\n",*pb);
    printf("%d",*pa);


}