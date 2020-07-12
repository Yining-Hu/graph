#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "list.h"

int list_push(List* list, void* elem) {
    struct ListElem* tmp;

    if(!(tmp = malloc(sizeof(*tmp)))) {
        printf("Error allocating memory!\n");
        return 0;
    }
    tmp->elem = elem; // create new listElem with the node data
    tmp->next = *list; // elem->next points to the previous element
    *list = tmp; // replace the list head with the new element

    return 1;
}
/*  --free--    --free--    --free--    --free--  */
/* [1,next] -> [2,next] -> [3,next] -> [4,NULL] */
/* [1,NULL] */

void list_free(List* list) {
    struct ListElem* cur;

    cur = *list;
    while (cur) {
        struct ListElem* tmp = cur->next;
        free(cur);
        cur = tmp;
    }
    *list = NULL; // when the user frees the whole list, the list becomes NULL
}

/* randomly select an element from a linked list
 * Reservoir sampling
 */
void* list_select_elem(List* list) {
    struct ListElem* tmp;
    int n;
    void* res;

    tmp = *list;
    if (!tmp) {
        return NULL;
    }
    res = tmp->elem; //set default to beginning of the list

    srand(time(NULL));
    for (n = 2; tmp != NULL; n++) {
        if (rand() % n == 0) {
            res = tmp->elem;
        }
        tmp = tmp->next;
    }
    return res;
}
