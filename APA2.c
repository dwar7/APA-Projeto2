#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Time {
    char nome[30];
    int pontos;
    int posicao;
};

int compararPorPontos(const void *a, const void *b) {
    return ((struct Time *)b)->pontos - ((struct Time *)a)->pontos;
}

void buscarTimePorPontos(struct Time times[], int n, int pontos, int index) {
    if (index < n) {
        if (times[index].pontos == pontos) {
            printf("Nome: %s, Posicao: %d\n", times[index].nome, times[index].posicao);
        }
        buscarTimePorPontos(times, n, pontos, index + 1);
    }
}

void exibirCincoPrimeiros(struct Time times[], int n, int index) {
    if (index < 5) {
        printf("Nome: %s, Posicao: %d\n", times[index].nome, times[index].posicao);
        exibirCincoPrimeiros(times, n, index + 1);
    }
}

void exibirCincoUltimos(struct Time times[], int n, int index) {
    if (index < 5) {
        printf("Nome: %s, Posicao: %d\n", times[n - 5 + index].nome, times[n - 5 + index].posicao);
        exibirCincoUltimos(times, n, index + 1);
    }
}

void exibirDiferencaPontosCincoPrimeiros(struct Time times[], int n, int index) {
    if (index < 4) {
        int diferenca = times[index].pontos - times[index + 1].pontos;
        printf("Diferenca entre %s e %s: %d pontos\n", times[index].nome, times[index + 1].nome, diferenca);
        exibirDiferencaPontosCincoPrimeiros(times, n, index + 1);
    }
}

void exibirDiferencaPontosCincoUltimos(struct Time times[], int n, int index) {
    if (index < 4) {
        int diferenca = times[n - 5 + index].pontos - times[n - 5 + index + 1].pontos;
        printf("Diferenca entre %s e %s: %d pontos\n", times[n - 5 + index].nome, times[n - 5 + index + 1].nome, diferenca);
        exibirDiferencaPontosCincoUltimos(times, n, index + 1);
    }
}

void reordenarTabela(struct Time times[], int n) {
    qsort(times, n, sizeof(struct Time), compararPorPontos);
    int novaQuantidade = n / 2;
    int i;
	for (i = 0; i < novaQuantidade; i++) {
        printf("Nome: %s, Posicao: %d, Pontos: %d\n", times[i].nome, i + 1, times[i].pontos);
    }
}

void exibirMenu() {
    printf("\nMenu:\n");
    printf("1. Buscar time por pontos\n");
    printf("2. Exibir cinco primeiros colocados\n");
    printf("3. Exibir cinco últimos colocados\n");
    printf("4. Exibir diferença de pontos entre os cinco primeiros\n");
    printf("5. Exibir diferença de pontos entre os cinco últimos\n");
    printf("6. Reordenar tabela e exibir metade dos times\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    struct Time times[] = {
        {"Palmeiras", 63, 0},
        {"Flamengo", 63, 1},
        {"Botafogo", 62, 2},
        {"Atletico Mineiro", 60, 3},
        {"Gremio", 59, 4},
        {"Bragantino", 59, 5},
        {"Fluminense", 53, 6},
        {"Atletico-PR", 52, 7},
        {"Cuiaba", 48, 8},
        {"Sao Paulo", 47, 9},
        {"Internacional", 46, 10},
        {"Fortaleza", 45, 11},
        {"Cruzeiro", 44, 12},
        {"Corinthians", 44, 13},
        {"Santos", 43, 14},
        {"Vasco", 42, 15},
        {"Bahia", 41, 16},
        {"Goias", 35, 17},
        {"Coritiba", 29, 18},
        {"America MG", 21, 19}
    };

    int n = sizeof(times) / sizeof(times[0]);
    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe a quantidade de pontos: ");
                int pontos;
                scanf("%d", &pontos);
                buscarTimePorPontos(times, n, pontos, 0);
                break;

            case 2:
                exibirCincoPrimeiros(times, n, 0);
                break;

            case 3:
                exibirCincoUltimos(times, n, 0);
                break;

            case 4:
                exibirDiferencaPontosCincoPrimeiros(times, n, 0);
                break;

            case 5:
                exibirDiferencaPontosCincoUltimos(times, n, 0);
                break;

            case 6:
                reordenarTabela(times, n);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

