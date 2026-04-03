#include <stdio.h>

void calcula(int* c){
    printf("calcula, c no ponteiro  %d , c inteiro %d, c com o & %d\n", (*c), c, &c);
    (*c)++;
    printf("calcula, c no ponteiro  %d , c inteiro %d, c com o & %d\n", (*c), c, &c);
    (*c)++;
}

int main() {

    int c = 10;

    printf("main %d %d\n", c, &c);

    calcula(&c);

    printf("main %d %d\n", c, &c);
}