#include <stdio.h>
#include <stdlib.h>

//int ALTURA = 10;
//int LARGURA = 10;
int TAMANHO = 10;
int cobra[10][10];

//Algumas constantes para reaproveitar
int COMIDA = -1;
int COBRINHA = 1;
int VAZIO = 0;
int SIM = 1;
int NAO = 0;

//x e y é a coordenada do cursor
int x;
int y;

int finalizou;
int move_x = 1; //SIM
int move_y = 0; //NAO

int main()
{
    printf("cobrinha\n");
    inicio();

    while (!finalizou) {
        desenhar();
        scan();
        proximo_frame();
    }
    return 0;
}

void inicio() {
    printf("O jogo vai comecar \n");

    //preenche com zeros
    for (int i=0; i < (TAMANHO * TAMANHO); i++) {
        int linha = i/TAMANHO;
        int coluna = i%TAMANHO;
        //limpa
        cobra[linha][coluna] = VAZIO;
    }

    //nasce a cobra
    cobra[2][2] = COBRINHA; //1 representa cobra
    cobra [0][7] = COBRINHA;
    cobra [0][8] = COBRINHA;

    //nasce comida
    int x_comida = rand() % TAMANHO;
    int y_comida = rand() % TAMANHO;
    cobra[x_comida][y_comida] = COMIDA; //-1 representa comida

    finalizou = NAO;
}

void proximo_frame() {
    //recalcula a cobrinha
}

char simbolo(int cursor) {
    // Simbolo de acordo com a tabela ASCII https://theasciicode.com.ar/
    if (cursor == COBRINHA) {
        return 219;
    } else if (cursor == COMIDA) {
        return 254;
    } else
    {
        return 176; //light shadow
    }
}

void desenhar() {
  system("cls");
  for (int i=0; i < TAMANHO; i++) {
    for (int j=0; j < TAMANHO; j++) {
        printf("%c", simbolo(cobra[i][j]));
    }
    printf("\n");
  }
}

void scan() {
    system("PAUSE");
    //todo! implementar captura da tecla
    //exemplo: getch();
    //precisa <conio.h>
}
