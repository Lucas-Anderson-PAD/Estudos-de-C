#include <stdio.h>
# define PI 3.14

struct Ponto{
    float x;
    float y;
};

struct Circulo{
    struct Ponto * p;
    float raio;
};

struct Circulo* novocirculo(struct Ponto*  ponto, float raio)
{

    struct Circulo* c = (struct Circulo*)malloc(sizeof(struct Circulo));
    if(c == NULL)
    {
        return NULL;
    }

    c->p = ponto;
    c->raio = raio;

    return c;
    
}

void imprimicirculo(struct Circulo *c){
    printf("raio é %f\n", c->raio);
    printf("Ponto, %f %f", c-> Ponto->x, c->Ponto -> y);
}


float araCirculo(struct Circulo c){
    float area;
    area = PI * pow(c.raio,2);
    return area;
}

