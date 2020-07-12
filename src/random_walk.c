/* generate random walk vectors given a graph
 * one node -> one random walk vector
 * need a function for random selection within an array
 */

#include "random_walk.h"

/* to change the return value to int for malloc */
void get_walks(struct Mat* walks, struct Graph* graph) {
    int i, j;
    struct Node* node;
    struct Node* neighbor;
    List* nodeList;

    for (i = 0; i < walks->row; i++) {
        node = graph->nodes[i];
        for (j = 0; j < walks->col; j++) {
            /* randomly select a neighbor from the list
             * store -1 if no more neighbors to find
             */
            if (node) { 
                walks->data[i * walks->col + j] = node->id;
                node = list_select_elem(&node->neighbors);
            } else {
                walks->data[i * walks->col + j] = -1;
            }
        }
    }

    //return 1;
}
