#ifndef GRAPH_H
#define GRAPH_H

#include "list.h"

#define MAX_NB_NODES 1024

struct Node {
    int id;
    List neighbors;
};

struct Graph {
    struct Node* nodes[MAX_NB_NODES]; //
    int nbNodes; // nbNodes is the number of node the graph has
};

void graph_init(struct Graph* graph);

int graph_add_node(struct Graph* graph);

void graph_connect(struct Graph* graph, int node1, int node2);

void graph_print(struct Graph* graph);

void graph_free(struct Graph* graph);

#endif
