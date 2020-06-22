#include <stdio.h>

#include "graph.h"
#include "graph_export.h"

void graph_head() {
    printf("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    printf("<graphml xmlns=\"http://graphml.graphdrawing.org/xmlns\"\n");
    printf("xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n");
    printf("xsi:schemaLocation=\"http://graphml.graphdrawing.org/xmlns\n");
    printf("http://graphml.graphdrawing.org/xmlns/1.0/graphml.xsd\">\n");
    printf("<graph id=\"G\" edgedefault=\"undirected\">\n");
}

void graph_tail() {
    printf("</graph>\n");
    printf("</graphml>\n");
}

void graph_body(struct Graph* graph) {
    int i, j, count, graphSize, nodeID, neighborID;
    List neighbors;

    graphSize = graph->nbNodes;

    // print nodes
    for (i = 0; i < graphSize; i++) {
        nodeID = graph->nodes[i]->id;
        printf("<node id=\"n%d\"/>\n", nodeID);
    }

    // print edges
    count = 0;
    for (i = 0; i < graphSize; i++) {
        nodeID = graph->nodes[i]->id;
        neighbors = graph->nodes[i]->neighbors;
        while (neighbors != NULL) {
            neighborID = ((struct Node*)(neighbors->elem))->id;
            neighbors = neighbors->next;
            if (nodeID < neighborID) {
                count++;
                printf("<edge id=\"e%d\" source=\"n%d\" target=\"n%d\"/>\n", count, nodeID, neighborID);
            }
        }
    }
}

void graph_export(struct Graph* graph) {
    graph_head();
    graph_body(graph);
    graph_tail();
}

