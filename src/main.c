#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kraskal.h"

int main() {
    int cnt, cnt_edge;
    Edge* edges;
    FILE* input = stdin;
    FILE* output = stdout;
    int chouse;

    printf("алгоритм Краскала\n");
    printf("1 ввести вручную\n");
    printf("2 прочитать из файла\n");
    printf("Выберите пункт: ");
    scanf("%d", &chouse);

    if (chouse == 2) {
        char filename[256];
        printf("Введите имя файла: ");
        scanf("%s", filename);
        input = fopen(filename, "r");
        if (!input) {
            fprintf(stderr, "ошибка открытия %s\n", filename);
            return 1;
        }
    }

    printf("1. На экран\n");
    printf("2. В output.txt\n");
    printf("Выберите пункт: ");
    scanf("%d", &chouse);

    if (chouse == 2) {
        output = fopen("output.txt", "w");
        if (!output) {
            fprintf(stderr, "ошибка создания\n");
            if (input != stdin) fclose(input);
            return 1;
        }
    }

    if (input == stdin) printf("\nВведите кол-во вершин и ребер: ");
    if (fscanf(input, "%d %d", &cnt, &cnt_edge) != 2) {
        fprintf(stderr, "ошибка ввода\n");
        return 1;
    }

    edges = (Edge*)malloc(cnt_edge * sizeof(Edge));
    if (!edges) {
        fprintf(stderr, "-память\n");
        return 1;
    }

    for (int i = 0; i < cnt_edge; i++) {
        if (input == stdin) printf("Ребро %d: ", i + 1);
        if (fscanf(input, "%d %d %d", &edges[i].from, &edges[i].to, &edges[i].cost) != 3) {
            fprintf(stderr, "ошибка в данных ребра %d\n", i + 1);
            free(edges);
            return 1;
        }
    }

    int dlina = kraskal(cnt, cnt_edge, edges);

    fprintf(output, "\nитог алгоритма\n");
    fprintf(output, "кол-во вершин: %d\n", cnt);
    fprintf(output, "общая длина дерева: %d\n", dlina);

    free(edges);
    if (input != stdin) fclose(input);
    if (output != stdout) {
        fclose(output);
    }

    return 0;
}