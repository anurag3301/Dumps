#include <stdio.h>
#include <stdlib.h>
#include "csv.h"

void init_shuffel(Table *main, Table *toshuffel){
    size_t size = main->row_count;
    size_t *idx_arr = malloc(sizeof(size_t) * size);
    for(size_t i=0; i<size; i++) idx_arr[i] = i;
    for(size_t i=0; i<size; i++){
        size_t j = i + rand() / (RAND_MAX / (size-i) + 1);
        size_t t = idx_arr[j];
        idx_arr[j] = idx_arr[i];
        idx_arr[i] = t;
    }
    for(size_t i=0; i<size; i++){
        Row *cur_row = get_row(idx_arr[i], main);
        add_row(cur_row->row_vals, toshuffel);
        distroy_row(cur_row);
    }

    free(idx_arr);
}

void horizontal_split(Table *master, Table **train, Table **test, uint ratio){
    *train = init_table("headers.csv");
    *test = init_table("headers.csv");
    for(size_t i=0; i<master->row_count*ratio/100; i++){
        Row *cur_row = get_row(i, master);
        add_row(cur_row->row_vals, *train);
        distroy_row(cur_row);
    }

    for(size_t i=master->row_count*ratio/100; i<master->row_count; i++){
        Row *cur_row = get_row(i, master);
        add_row(cur_row->row_vals, *test);
        distroy_row(cur_row);
    }
}


int main(){
    Table* table = init_table("iris.csv");
    Table* shuffeled = init_table("headers.csv");
    Table *train=NULL, *test=NULL;
    
    init_shuffel(table, shuffeled);
    horizontal_split(shuffeled, &train, &test, 50);

    print_table(shuffeled);
    print_table(train);
    print_table(test);

    distroy_table(train);
    distroy_table(test);
    distroy_table(table);
    distroy_table(shuffeled);
}
