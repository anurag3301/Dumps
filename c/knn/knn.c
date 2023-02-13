#include <stdio.h>
#include "csv.h"

int main(){
    Table* table = init_table("iris.csv");
    /* Table* table = init_table("iris_full.csv"); */
    Column* col = get_col("species", table);
    for(int i=0; i<table->row_count; i++){
        printf("%s\n", col->colvals[i]);
    }
    /* print_table(table); */
    distroy_table(table);
}
