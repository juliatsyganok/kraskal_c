#include <stdlib.h>  
#include <stdio.h>   
#include "kraskal.h" 

void sort(Edge* edges, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (edges[j].cost > edges[j+1].cost) {
                Edge nnew = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = nnew;
            }
        }
    }
    
}



int group(int* par, int i) {
    if (par[i] == i)
        return i; 
    return group(par, par[i]); 
}

int kraskal(int cnt, int cnt_edge, Edge* edges) {
    sort(edges, cnt_edge);
    for(int i=0; i<cnt_edge; i++) printf("%d ", edges[i].cost);
    int* par = (int*)malloc(cnt * sizeof(int));
    for (int i = 0; i < cnt; i++) {
        par[i] = i; 
    }
    printf("Выбранные ребра для минимального дерева:\n");
    int summ_cost = 0;
    int summ_edge = 0;

    for (int i = 0; i < cnt_edge; i++) {
        if (summ_edge == cnt - 1) break;

        Edge nnew = edges[i];
        int group_a = group(par, nnew.from);
        int group_b = group(par, nnew.to);

        if (group_a != group_b) {
            printf("рёбра %d и %d вес: %d\n", nnew.from, nnew.to, nnew.cost);
            summ_cost += nnew.cost;
            summ_edge++;

            par[group_b] = group_a;
        }
    }
    printf("Общая длина пути: %d\n", summ_cost);
    free(par);
    return summ_cost;
}