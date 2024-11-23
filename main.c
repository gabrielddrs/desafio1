#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir_bin(unsigned char item){

    puts("=================================");
    puts("Todos os armários existentes:");
    printf("8 7 6 5 4 3 2 1\n");
    for(int i = 7; i >= 0; --i){
        printf("%d ", (item >> i) & 1);
    }
    printf("\n================================\n\n");
}

unsigned char escolha(unsigned char armarios){
    unsigned char old = armarios;
    unsigned char pos;

    srand(time(NULL));
    do{
        unsigned char mask = 0x01;

        pos = 1 + rand() % 8;

        mask <<= (pos-1);
        armarios = armarios | mask;

    if (armarios >= 255) {
        break;
    } else {
        continue;
}

    }while(armarios == old);

    imprimir_bin(armarios);
    return armarios;
}


unsigned char libera(unsigned char armarios, unsigned char pos){
    unsigned char mask = 0x01;

    armarios = armarios & ~(mask << (pos - 1));

    imprimir_bin(armarios);

    return armarios;
}


int main(void){
    unsigned char armarios = 0x00;
    unsigned char op = 0;
    unsigned char pos;

    do {
        puts("Escolha a opçao:");
        puts("[1]Ocupar armario");
        puts("[2]Liberar armario");
        puts("[3]Sair");
        puts("[0]Visualizar armarios\n");

        if (scanf(" %hhu", &op) != 1) {
            puts("Entrada inválida! Digite um número entre 0 e 3.");
            while (getchar() != '\n');
            continue;
        }

        switch (op) {

            case 0:
                imprimir_bin(armarios);
                printf("%hhu", op);
                break;

            case 1:
                armarios = escolha(armarios);
                break;

            case 2:
                puts("Digite numero do armário que deseja desocupar");
                scanf(" %hhu", &pos);
                armarios = libera(armarios, pos);
                break;

            default:
                break;
        }
    } while (op != 3);

  return 0;
}