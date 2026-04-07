#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "forca.h"

//variaveis globais
char chutes[26];
char palavrasecreta[TAMANHO_PALAVRA];
int chutesdados = 0;


void abertura() {
    printf("*************************\n");
    printf("**    Jogo de Forca    **\n");
    printf("*************************\n\n");

}

void chuta() {
    char chute; 
        scanf(" %c", &chute);

        chutes[chutesdados] = chute;
        chutesdados++;
}

int jachutou(char letra){
    int achou = 0;

    for(int j = 0; j < chutesdados; j++) {
        if (chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

int letraexiste(char letra) {

    for(int j = 0; j < strlen(palavrasecreta); j++) {
        if(letra == palavrasecreta[j]) {
            return 1;
        }
    }

    return 0;
}


int chuteserrados() {
    int erros = 0;

    for(int i = 0; i < chutesdados; i++) {

        if(!letraexiste(chutes[i])) {
            erros++;
        }
    }

    return erros;
}

void desenhaforca() {

    int erros = chuteserrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for(int i = 0; i < strlen(palavrasecreta); i++) {

        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}


void adicionapalavra() {
    char quer;
    printf("\n Voce quer adicionar uma nova palavra no banco de dados? (S/N) ");
    scanf(" %c", &quer);

    if (quer == 'S') {
        char novapalavra[29];

        printf("Qual a nova palavra voce quer? ");
        scanf("%s", novapalavra);

        FILE* f;
        f = fopen("palavras.txt", "r+");
        if (f == 0) {
            printf("Desclpa banco de dados nao disponivel \n\n");
            exit(1);            
        }


        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0,SEEK_END);
        fprintf(f, "\n%s", novapalavra);
        fclose(f);

    } else {
        printf("\n  OK  \n");
        exit(1);
    }
}



void escolhapalavrasecreta() {
    FILE* f;
    f = fopen("palavras.txt", "r");

    if(f==0) {
        printf("Desclpa banco de dados nao disponivel \n\n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() % qtddepalavras;

    for(int i = 0; i <= randomico; i++) {
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}

int ganhou() {
    for(int i = 0; i < strlen(palavrasecreta); i++) {
        if(!jachutou(palavrasecreta[i])) {
            return 0;
        }
    }
    return 1;
}


// AQUI 



int enforcou() {

    //COLOCAR A FUNCAO JACHUTOU

    int erros = 0;
    for(int i = 0; i < chutesdados; i++) {
        int existe = 0;

        for(int j = 0; j < strlen(palavrasecreta); j++) {
            if(chutes[i] == palavrasecreta[j]) {
                
                existe = 1;
                break;
            }
        }
        
        if(!existe) erros++;
    }

    return erros >= 5;
}


int main() {

    printf("\n");

//  palavra secreta
//  abertura
    escolhapalavrasecreta();
    abertura();

    do {

        desenhaforca();
        chuta(); 
        
    } while(!ganhou() && !enforcou() );
    
    if (ganhou()) {
        printf("Parabens voce acertou a palavra secreta era, %s", palavrasecreta);
    } else {
        printf("Voce atinjiu a quantidade maxima de chutes \n\n");
        printf("Sinto muito a palavra secreta era **%s**", palavrasecreta);
    }
    
    
    
    
    
    adicionapalavra();
}
