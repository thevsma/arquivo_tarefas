#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAREFA 256
#define MAX_TAREFAS 100

void adicionar_tarefa() {
    char tarefa[MAX_TAREFA];
    printf("Digite a descricao da tarefa: ");
    getchar();
    fgets(tarefa, MAX_TAREFA, stdin);

    size_t len = strlen(tarefa);
    if (len > 0 && tarefa[len-1] == '\n') {
        tarefa[len-1] = '\0';
    }

    FILE *fp = fopen("../tarefas.txt", "a");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo tarefas.txt\n");
        return;
    }
    fprintf(fp, "%s\n", tarefa);
    fclose(fp);
    printf("Tarefa adicionada!\n");
}

int listar_tarefas(char tarefas[][MAX_TAREFA]) {
    FILE *fp = fopen("../tarefas.txt", "r");
    if (fp == NULL) {
        printf("Nenhuma tarefa encontrada.\n");
        return 0;
    }

    int count = 0;
    while (fgets(tarefas[count], MAX_TAREFA, fp) != NULL) {
        size_t len = strlen(tarefas[count]);
        if (len > 0 && tarefas[count][len-1] == '\n') {
            tarefas[count][len-1] = '\0';
        }
        printf("%d. %s\n", count+1, tarefas[count]);
        count++;
    }
    fclose(fp);
    if(count == 0)
        printf("Nenhuma tarefa encontrada.\n");
    return count;
}

void remover_tarefa() {
    char tarefas[MAX_TAREFAS][MAX_TAREFA];
    int total = listar_tarefas(tarefas);

    if (total == 0) return;

    int num;
    printf("Digite o numero da tarefa a ser removida: ");
    scanf("%d", &num);
    if (num < 1 || num > total) {
        printf("Numero invalido.\n");
        return;
    }

    FILE *fp = fopen("../tarefas.txt", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo tarefas.txt\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        if (i != num-1) {
            fprintf(fp, "%s\n", tarefas[i]);
        }
    }
    fclose(fp);
    printf("Tarefa removida!\n");
}

int main() {
    int opcao;
    do {
        printf("\n===== MENU =====\n");
        printf("1. Adicionar Tarefa\n");
        printf("2. Listar Tarefas\n");
        printf("3. Remover Tarefa\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                adicionar_tarefa();
                break;
            case 2: {
                char tarefas[MAX_TAREFAS][MAX_TAREFA];
                listar_tarefas(tarefas);
                break;
            }
            case 3:
                remover_tarefa();
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 4);

    return 0;
}