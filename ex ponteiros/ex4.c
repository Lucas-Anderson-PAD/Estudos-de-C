 #include <stdio.h>

void converteHora(int total_segundos, int *hora, int *min, int *seg);

int main(){
    int n,competidores_validos=0;
    int maxinsc=0, maxseg=0, maxmin=0, maxhora=0;
    int mininsc = 0, minseg=0, minmin=0, minhora=0;
    int duracaomin=36000;
    int duracaomax=0;

    printf("Digite o numero de competidores\n");
    scanf("%d",&n);

    for (int i =0; i<n;i++){
        int tempinsc;
        int duracao=0;

        printf("Digite o numero de inscricao do competidor %d\n",i+1);
        scanf("%d",&tempinsc);

        printf("Digite a duracao do percurso em segundos do competidor %d\n",i+1);
        scanf("%d",&duracao);


        if (duracao>36000){
            printf("O competidor foi desqualificado pois ultrapassou o limite de 10min\n");

        }
        else{
            competidores_validos++;
            if(duracao > duracaomax){
                maxinsc = tempinsc;
                duracaomax = duracao;
                converteHora(duracao, &maxhora, &maxmin, &maxseg);
            }

            if(duracao < duracaomin){
                mininsc = tempinsc;
                duracaomin = duracao;
                converteHora(duracao, &minhora, &minmin, &minseg);
            }
        }
    }

    if (competidores_validos > 0) {
        printf("O competidor %d teve o menor tempo: %02d:%02d:%02d \n", mininsc, minhora, minmin, minseg);
        printf("O competidor %d teve o maior tempo: %02d:%02d:%02d \n", maxinsc, maxhora, maxmin, maxseg);
    } else {
        printf("Nenhum competidor válido foi registrado.\n");
    }


}

void converteHora(int total_segundos, int *hora, int *min, int *seg){
    *hora = total_segundos/3600;
    *min = (total_segundos - *hora *3600)/60;
    *seg = total_segundos - *hora * 3600 - *min *60;
}