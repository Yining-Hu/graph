#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "rand_graph.h"
#include "graph_export.h"
#include "matn.h"
#include "random_walk.h"

int main() {
    struct Graph graph;
    int graphSize = 7, randWalkLen = 3;
    struct Mat walks;

    graph_init(&graph);

    rand_graph(&graph, graphSize);
    
    // graph_print(&graph);
    graph_export(&graph);

    // random walk vectors
    new_mat(&walks, graphSize, randWalkLen);
    get_walks(&walks, &graph);
    print_mat(&walks); 

    graph_free(&graph);
    free_mat(&walks);
}
