#include <stdio.h>

#define TAM 10
#define H 5
#define NAVIO 3
#define HABILIDADE 5

void aplicarHabilidade(int tabuleiro[TAM][TAM], int efeito[H][H], int origem_linha, int origem_coluna) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            int linha_tab = origem_linha - H/2 + i;
            int col_tab = origem_coluna - H/2 + j;
            if (linha_tab >= 0 && linha_tab < TAM && col_tab >= 0 && col_tab < TAM) {
                if (efeito[i][j] == 1 && tabuleiro[linha_tab][col_tab] != NAVIO) {
                    tabuleiro[linha_tab][col_tab] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[2][2 + i] = NAVIO;
        tabuleiro[5 + i][6] = NAVIO;
        tabuleiro[0 + i][0 + i] = NAVIO;
        tabuleiro[6 + i][9 - i] = NAVIO;
    }

    int cone[H][H] = {0};
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (j >= H/2 - i && j <= H/2 + i) {
                cone[i][j] = 1;
            }
        }
    }

    int cruz[H][H] = {0};
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (i == H/2 || j == H/2) {
                cruz[i][j] = 1;
            }
        }
    }

    int octaedro[H][H] = {0};
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (abs(i - H/2) + abs(j - H/2) <= H/2) {
                octaedro[i][j] = 1;
            }
        }
    }

    aplicarHabilidade(tabuleiro, cone, 1, 2);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 8, 2);

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("~ ");
            } else if (tabuleiro[i][j] == NAVIO) {
                printf("N ");
            } else if (tabuleiro[i][j] == HABILIDADE) {
                printf("* ");
            }
        }
        printf("\n");
    }

    return 0;
}
