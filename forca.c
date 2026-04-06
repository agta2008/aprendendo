#include <stdio.h>
#include <string.h>

//variaveis globais
char chutes[26];
char palavrasecreta[20];
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


void desenhaforca() {
    for (int i = 0; i < strlen(palavrasecreta); i++) {

        //aqui estava o codigo que verifica se achou a letra certa
        // essa funcao retorna {achou} paasando a funcao jachutou
        int achou = jachutou(palavrasecreta[i]);

        if(achou) {
                
            printf("%c ", palavrasecreta[i]);
            
        } else {
            printf("_ ");
        }
            
    }
    printf("\n");
}

void escolhapalavrasecreta() {
    sprintf(palavrasecreta, "MELANCIA");
}

int enforcou() {
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
    int acertou = 0;

    
//  palavra secreta
//  abertura
    escolhapalavrasecreta();
    abertura();

    do {

        desenhaforca();
        chuta(); 
        
    } while(!acertou && !enforcou() );

}
