#include  <stdio.h>

#define NUMERO_DE_TENTATIVAS 5

int main() {
    //introduçao ao jogo super fodastico
    printf("*********************************\n");
    printf("*Bem vindo ao jogo de advinhaçao*\n");
    printf("*********************************.\n");

    int numerosecreto = 42;
    int chute;

    for(int i = 1; i <= NUMERO_DE_TENTATIVAS; i++) {

        printf("Tentativas %d de %d \n", i, NUMERO_DE_TENTATIVAS);
        printf("Qual é seu chute? \n");
        scanf("%d", &chute);


        if (chute < 0) {
            printf("Você não pode chutar numeros negativos \n");
            i--;

            continue;
        }

        //caso o jogador acerte
        if(chute == numerosecreto){
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
    }
    printf("Fim jogo \n");
}

