#include  <stdio.h>
#include <stdlib.h>


int main() {
    //introduçao ao jogo super fodastico
    printf("*********************************\n");
    printf("*Bem vindo ao jogo de advinhaçao*\n");
    printf("*********************************.\n");

    int numerosecreto = 42;
    int chute = -1;
    int i = 1;

    //adcionado pontos para que a brincadeira seja mais legal
    double pontos = 1000;
    pontos = pontos * 2;

    while(1) {

        printf("Qual é seu chute? \n");
        scanf("%d", &chute);
        i++;

        if (chute < 0) {
            printf("Você não pode chutar numeros negativos \n");

            continue;
        }

        //caso o jogador acerte
        else if(chute == numerosecreto){
            printf("Parabens voce acertou o numero secreto \n");

            break;
        }

        //caso o jogador erre
        else{
            if (chute > numerosecreto){
                printf("Seu chute foi maior que o numero secreto \n");
            }

            if (chute < numerosecreto){
                printf("Seu numero foi menor que o numero secreto \n");
            }
    }

        //calculo da pontuacao
        double pontosperdidos = abs(chute - numerosecreto) / 2.0;

        pontos = pontos - pontosperdidos;

    }

    printf("Tentativas %d \n", i);
    printf("Fim jogo \n");
    printf("Total de pontos %.f \n", pontos);
}
