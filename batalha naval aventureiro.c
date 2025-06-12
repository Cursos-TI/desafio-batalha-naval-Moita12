#include <stdio.h>

#define TAM 10
#define NAVIO 3

int main() {
    int tabuleiro[TAM][TAM] = {0};

    int h1_linha = 1, h1_coluna = 2;
    int v1_linha = 4, v1_coluna = 7;
    int d1_linha = 0, d1_coluna = 0;     // diagonal principal
    int d2_linha = 6, d2_coluna = 9;     // diagonal secundária

    int sobreposicao = 0;

    if (h1_coluna + NAVIO <= TAM) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[h1_linha][h1_coluna + i] != 0) sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[h1_linha][h1_coluna + i] = 3;
            }
        }
    }

    sobreposicao = 0;
    if (v1_linha + NAVIO <= TAM) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[v1_linha + i][v1_coluna] != 0) sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[v1_linha + i][v1_coluna] = 3;
            }
        }
    }

    sobreposicao = 0;
    if (d1_linha + NAVIO <= TAM && d1_coluna + NAVIO <= TAM) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[d1_linha + i][d1_coluna + i] != 0) sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[d1_linha + i][d1_coluna + i] = 3;
            }
        }
    }

    sobreposicao = 0;
    if (d2_linha + NAVIO <= TAM && d2_coluna - NAVIO + 1 >= 0) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[d2_linha + i][d2_coluna - i] != 0) sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[d2_linha + i][d2_coluna - i] = 3;
            }
        }
    }

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
