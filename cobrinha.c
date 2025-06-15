#include <stdio.h>
#include <stdlib.h>

//int ALTURA = 10;
//int LARGURA = 10;
int TAMANHO = 11;
int cobra[121]; //array unidimensional MxM

//Algumas constantes para reaproveitar
int COMIDA = -1;
int COBRINHA = 1;
int VAZIO = 0;
int SIM = 1;
int NAO = 0;

// coordenada do cursor
int pos;

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
        cobra[i] = VAZIO; //limpa
    }

    //nasce a cobra
    cobra[22] = COBRINHA; //1 representa cobra
    cobra [8] = COBRINHA;
    cobra [9] = COBRINHA;

    //nasce comida
    int pos_comida = rand() % (TAMANHO * TAMANHO);
    cobra[pos_comida] = COMIDA; //-1 representa comida

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
  //system("cls");
    limpar_tela();
  for (int j=0; j < TAMANHO; j++) {
    for (int i=0; i < TAMANHO; i++) {
        printf("%c", simbolo(cobra[j*TAMANHO + i]));
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

int GREEN = 10;
int RED = 12;
int WHITE = 15;
int GRAY = 7;

void set_color(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, GREEN);
}

void hide_cursor() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &cursorInfo);
}

void limpar_tela() {
    COORD cursorPos;
    cursorPos.X = 0;
    cursorPos.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
}
