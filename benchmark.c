#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "kraskal.h"

void gen_graph(int V, int E, Edge* edges) {
    for (int i = 0; i < E; i++) {
        edges[i].from = rand() % V;
        edges[i].to = rand() % V;
        edges[i].cost = rand() % 100;
    }
}

int main() {
    FILE *f = fopen("stats.csv", "w");
    fprintf(f, "Nodes;Edges;Time\n");

    for (int n = 10; n <= 1000; n += 50) { 
        int e = n * 2; 
        Edge* edges = malloc(e * sizeof(Edge));
        gen_graph(n, e, edges);

        clock_t start = clock();
        kraskal(n, e, edges);
        clock_t end = clock();

        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(f, "%d;%d;%f\n", n, e, time_spent);
        printf("V=%d, Time: %f\n", n, time_spent);

        free(edges);
    }
    fclose(f);
    return 0;
}