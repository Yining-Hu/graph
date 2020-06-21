#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int main() {
    struct Graph graph;
    int i, id;

    graph_init(&graph);

    graph_add_node(&graph);
    graph_add_node(&graph);
    graph_add_node(&graph);
    graph_add_node(&graph);
    graph_add_node(&graph);
    graph_add_node(&graph);

    graph_connect(&graph, 0, 1);
    graph_connect(&graph, 0, 2);

    graph_print(&graph);

    graph_free(&graph);
}
