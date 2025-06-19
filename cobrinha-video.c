#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// 4 x 4
int size = 2;
int cobra[4];
int cursor_antigo;
int cursor;
int terminou = 0;
int n ;

//int cobraxy[4][4];
//int cursorx;
//int cursory;

//Divisao da parte inteira
//0 => 0
//1 => 0
//2 => 0
//3 => 0

//Resto da divisao
//0 => 0 -> 0
//1 => 0 -> 1
//2 => 0 -> 2
//3 => 0 -> 3
//4 => 1 -> 0
//5 => 1 -> 1
//6 => 1 -> 2

int linha(cursor) {
   return cursor / size;
}

int coluna(cursor) {
   return cursor % size;
}

//todo! Implementar a movimentação

//todo! Implementar alimentar
//int n = 6;

//cobra
// 0 0 0 0
// 0 3 2 1
// 0 4 0 0
// 0 0 0 0

// impressão
//----------------
// _ _ 0 _
// _ _ S _
// S S _ _
// S _ _ _


//----------------
// _ _ S _
// _ _ S _
// S S S _
// S _ _ _

int fixo_cob = 2;

int FOOD = -1;
int COB = 1;
int VAZIO = 0;

void inicializar() {
    for (int i=0; i<(size * size); i++) {
       cobra[i] = 0;
    }
}

char caractere(int x) {
    if ( x == FOOD ) {
            return '@';
    } else if ( x >= COB ) {
            return 'S';
    } else return ' ';
}

void novo_personagem() {
    //nascer a cobrinha num ponto fixo_cob
    cobra[fixo_cob] = COB;
    cursor = fixo_cob;
    n = 1;
}

void nova_comida() {
    int posicao_food = rand() % (size * size);
    if (n == (size * size)) {
      return;
    }

    while (cobra[posicao_food] != 0) {
       posicao_food = rand() % (size * size);
    }

    cobra[posicao_food] = FOOD;
}

void desenhar_linha() {
//  ******
    printf("\n");
    for (int j=0; j < size+2; j++) {
       printf("#");
    }
    //printf("\n");
}

void desenhar() {
    system("CLS");

    desenhar_linha();

    for (int i=0; i<(size * size); i++) {
      if (i%size==0) {
            printf("\n#");
      }
      printf("%c", caractere(cobra[i]));

      if (i%size==size-1) {
            printf("#");
        }
    }

    desenhar_linha();

    printf("\n\n score %d \n\n\n", n);

    //debug
    for (int i=0; i<(size * size); i++) {
      if (i%size==0) {
            printf("\n#");
      }
      printf("%d", cobra[i]);
    }
}

void game_over() {
    printf("Voce perdeu");
}

void lendo_input() {
    char digitou;
    digitou = getch();

    //cursor = 2

    if (digitou  == 'w') { //movimenta pra cima
        int lin_cursor = linha(cursor);
        if (lin_cursor == 0) {
            game_over();
        } else {
            cursor_antigo = cursor;
            cursor -= size;
        }

    } else if (digitou  == 's') { //movimenta pra baixo
        int lin_cursor = linha(cursor);
        if (lin_cursor == size - 1) {
            game_over();
        } else {
            cursor_antigo = cursor;
            cursor += size;
        }

    } else if (digitou  == 'a') { //movimenta pra esquerda
        int col_cursor = coluna(cursor);
        if (col_cursor == 0) {
            game_over();
        } else {
            cursor_antigo = cursor;
            cursor --;
        }

    } else if (digitou  == 'd') { //movimenta pra direita
        int col_cursor = coluna(cursor);
        if (col_cursor == size - 1) {
            game_over();
        } else {
            cursor_antigo = cursor;
            cursor ++;
        }

    } else if (digitou  == 'x') {
        exit(0);
    };
    //acima



    //if (digitou  == 's') //abaixo
    //if (digitou  == 'a') //esquerda
    //if (digitou  == 'd') //direita

}

void voce_ganhou() {
    printf("\n\Parabens Voce ganhou\n\n");
    terminou = 1;
}

void alimentar_cobrinha() {
   n++;
   cobra[cursor] = n;

   if (n == (size * size) ) {
    voce_ganhou();
   } else {
    nova_comida();
   }
}

void movimentar_cobrinha() {
   for (int i=0; i<(size * size); i++) {
        if (cobra[i] > 0) {
            cobra[i] = cobra[i]-1;
        }
    }

   cobra[cursor] = n;
}

void atualizar() {
    if (cobra[cursor] == FOOD) {
        alimentar_cobrinha();
    //} else if (cobra[cursor] > 0) {
    //    printf("Embaracou");
    //    game_over();
    } else if (cobra[cursor]==0) { //
        movimentar_cobrinha();
    }
}

int main() {

   inicializar();
   novo_personagem();
   nova_comida();
   desenhar();

   while (terminou == 0) {
        lendo_input();
        atualizar();

        desenhar();

        if (n == size * size ) {
            voce_ganhou();
        }

   }

    return 0;
}
