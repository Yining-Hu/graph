#include <stdlib.h>
#include <stdio.h>

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

