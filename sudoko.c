#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

bool verificar_linha(int matriz[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        bool existe[SIZE + 1] = {false};
        for (int j = 0; j < SIZE; j++) {
            int num = matriz[i][j];
            if (num < 1 || num > 9 || existe[num]) {
                return false;
            }
            existe[num] = true;
        }
    }
    return true;
}

bool verificar_coluna(int matriz[SIZE][SIZE]) {
    for (int j = 0; j < SIZE; j++) {
        bool existe[SIZE + 1] = {false};
        for (int i = 0; i < SIZE; i++) {
            int num = matriz[i][j];
            if (num < 1 || num > 9 || existe[num]) {
                return false;
            }
            existe[num] = true;
        }
    }
    return true;
}

bool verificar_blocos(int matriz[SIZE][SIZE]) {
    for (int bloco_linha = 0; bloco_linha < SIZE; bloco_linha += 3) {
        for (int bloco_coluna = 0; bloco_coluna < SIZE; bloco_coluna += 3) {
            bool existe[SIZE + 1] = {false};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int num = matriz[bloco_linha + i][bloco_coluna + j];
                    if (num < 1 || num > 9 || existe[num]) {
                        return false;
                    }
                    existe[num] = true;
                }
            }
        }
    }
    return true;
}

bool verificar_sudoku(int matriz[SIZE][SIZE]) {
    return verificar_linha(matriz) && verificar_coluna(matriz) && verificar_blocos(matriz);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int k = 1; k <= n; k++) {
        int matriz[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }
        
        printf("Instancia %d\n", k);
        if (verificar_sudoku(matriz)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }

    return 0;
}