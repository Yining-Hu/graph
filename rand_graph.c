#include <stdlib.h>
#include <time.h>

#include "graph.h"

void rand_graph(struct Graph* graph, int graphSize) {
    int i, j, randNum;
    float th = 0.3;

    for (i = 0; i < graphSize; i++) {
        graph_add_node(graph);
    }

    srand(time(NULL));
    for (i = 0; i < graphSize; i++) {
        for (j = i + 1; j < graphSize; j++) {
            randNum = rand();
            if ((float)randNum/RAND_MAX > th) {
                graph_connect(graph, i, j);
            }
        }
    }
}


