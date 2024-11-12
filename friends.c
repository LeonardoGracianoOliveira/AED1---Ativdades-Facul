#include <stdio.h>
#include <string.h>

const int MAX_FRIENDS = 1000;
const int MAX_NAME_LENGTH = 21;

void atualizar_lista_amigos(char amigos[], char novos_amigos[], char amigo_indicado[]) {
    char lista_atualizada[5000];

    if (strcmp(amigo_indicado, "não") == 0) {
        sprintf(lista_atualizada, "%s %s", amigos, novos_amigos);
    } else {
        char *posicao = strstr(amigos, amigo_indicado);

        if (posicao != NULL) {
            int indice = posicao - amigos;
            strncpy(lista_atualizada, amigos, indice);
            lista_atualizada[indice] = '\0';
            strcat(lista_atualizada, novos_amigos);
            strcat(lista_atualizada, " ");
            strcat(lista_atualizada, amigos + indice);
        } else {
            sprintf(lista_atualizada, "%s %s", amigos, novos_amigos);
        }
    }

    printf("Lista atualizada de amigos: %s\n", lista_atualizada);
}

int main() {
    char amigos[5000];
    char novos_amigos[5000];
    char amigo_indicado[MAX_NAME_LENGTH];

    printf("Digite a lista atual de amigos: ");
    fgets(amigos, sizeof(amigos), stdin);
    amigos[strcspn(amigos, "\n")] = 0;

    printf("Digite a nova lista de amigos: ");
    fgets(novos_amigos, sizeof(novos_amigos), stdin);
    novos_amigos[strcspn(novos_amigos, "\n")] = 0;

    printf("Digite o nome do amigo para indicar ou 'não': ");
    fgets(amigo_indicado, sizeof(amigo_indicado), stdin);
    amigo_indicado[strcspn(amigo_indicado, "\n")] = 0;

    atualizar_lista_amigos(amigos, novos_amigos, amigo_indicado);

    return 0;
}