#include <stdio.h>


void abertura(int m) {
    printf("\n");
    printf("Tabuada do %d\n\n", m);
}


int main(){

    int multiplicador = 2; 

    abertura(multiplicador);

    for(int i = 0; i <=10; i++) {
        int resul = i * multiplicador;
        printf("%d X  %d = %d\n", multiplicador, i, resul);
    }

}