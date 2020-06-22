#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "graph.h"

void graph_init(struct Graph* graph) {
    graph->nbNodes = 0;
}

// add a node to the graph, returns the new node id
int graph_add_node(struct Graph* graph) {
    struct Node* node;

    if(!(node = malloc(sizeof(*node)))) {
        printf("Error allocating memory!\n");
        return -1;
    }

    node->id = graph->nbNodes;
    node->neighbors = NULL;

    graph->nodes[graph->nbNodes] = node;
    graph->nbNodes++;

    return node->id;
}

void graph_connect(struct Graph* graph, int node1, int node2) {
    if (!list_push(&graph->nodes[node1]->neighbors, graph->nodes[node2])) {
        printf("Error allocating memory for new neighbor.\n");
        return;
    }

    if (!list_push(&graph->nodes[node2]->neighbors, graph->nodes[node1])) {
        printf("Error allocating memory for new neighbor.\n");
        return;
    }
}

void graph_print(struct Graph* graph) {
    struct Node* node;
    int i;
    List nodeList;

    /* Node #1:
     *      -> 2
     *      -> 3
     *      -> 4
     * Node #2:
     */

    for (i = 0; i < graph->nbNodes; i++) { // each node
        /* print id */
        printf("Node #%d:\n", graph->nodes[i]->id);
        nodeList = graph->nodes[i]->neighbors;

        while(nodeList != NULL) {
            node = nodeList->elem;
            nodeList = nodeList->next;
            printf("     ->%d\n", node->id);
        }
    }
}

void node_free(struct Node* node) {
    list_free(&node->neighbors);
}

void graph_free(struct Graph* graph) {
    int i;

    for (i = 0; i < graph->nbNodes; i++) {
        node_free(graph->nodes[i]);
        free(graph->nodes[i]);
    }
}
