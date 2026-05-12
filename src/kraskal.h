#ifndef KRASKAL_H
#define KRASKAL_H

typedef struct {
    int from;
    int to;
    int cost;
} Edge;

int kraskal(int cnt, int cnt_edge, Edge* edges);

#endif