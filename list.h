#ifndef LIST_H
#define LIST_H

struct ListElem {
    void* elem;
    struct ListElem* next;
};

typedef struct ListElem* List;

int list_push(List* list, void* elem);

void list_free(List* list);
#endif
