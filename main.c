#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcao;
    FILE* fp;

    fp = fopen("../tarefas.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo do texto\n");
        exit(1);
    }

    printf("1. Adicionar tarefa\n2. Listar tarefas\n3. Remover tarefa\n0. Finalizar\nDigite sua escolha: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite a tarefa: ");
            scanf();
    }

    return 0;
}