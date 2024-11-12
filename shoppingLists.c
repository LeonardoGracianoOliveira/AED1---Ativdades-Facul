#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_ITEMS = 1000;
const int MAX_LENGTH = 21;

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void process_shopping_list(char items[][MAX_LENGTH], int count) {
    qsort(items, count, sizeof(items[0]), compare);

    int unique_count = 0;
    char unique_items[MAX_ITEMS][MAX_LENGTH];
    for (int i = 0; i < count; i++) {
        if (i == 0 || strcmp(items[i], items[i - 1]) != 0) {
            strcpy(unique_items[unique_count++], items[i]);
        }
    }

    for (int i = 0; i < unique_count; i++) {
        printf("%s", unique_items[i]);
        if (i < unique_count - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int N;
    printf("Digite o número de listas de compras: ");
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        char line[10000];
        printf("Digite a lista de compras %d: ", i + 1);
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';

        char items[MAX_ITEMS][MAX_LENGTH];
        int count = 0;
        char *token = strtok(line, " ");
        while (token != NULL && count < MAX_ITEMS) {
            strcpy(items[count++], token);
            token = strtok(NULL, " ");
        }

        process_shopping_list(items, count);
    }

    return 0;
}