
#include <stdio.h>
#include <stdlib.h>

#include "matn.h"

void new_mat(struct Mat* mat, int row, int col) {
    mat->row = row;
    mat->col = col; 
    mat->data = malloc(row * col * sizeof(int));
}

void free_mat(struct Mat* mat) {
    free(mat->data);
}

void print_mat(struct Mat* mat) {
    int i, j;

    for (i = 0; i < mat->row; i++) {
        for (j = 0; j < mat->col; j++) {
            fprintf(stderr, "%d ", mat->data[i * mat->col + j]);
        }
        fprintf(stderr, "\n");
    }
}

