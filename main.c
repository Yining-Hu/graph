#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "rand_graph.h"

int main() {
    struct Graph graph;
    int graphSize = 6;

    graph_init(&graph);

    rand_graph(&graph, graphSize);
    graph_print(&graph);

    graph_free(&graph);
}
