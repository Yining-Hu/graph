#ifndef MATN_H
#define MATN_H

struct Mat {
    int row;
    int col;
    int* data;
};

void new_mat(struct Mat* mat, int row, int col);

void free_mat(struct Mat* mat);

void print_mat(struct Mat* mat);

#endif
