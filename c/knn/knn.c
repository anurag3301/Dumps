#include <stdio.h>
#include "csv.h"

int main(){
    Table* table = init_table("iris.csv");
    /* Table* table = init_table("iris_full.csv"); */

    char* x[] = {"1.1", "2.2", "3.3", "4.4", "parul"};
    for(int i=0; i<100; i++){
        add_row(x, table);
    }

    print_table(table);
    printf("%zu\n", table->max_size);

    distroy_table(table);
}
