#include <stdio.h>
#include "csv.h"

int main(){
    /* Table* table = init_table("iris.csv"); */
    Table* table = init_table("iris_full.csv");
    Row* row = get_row(149, table);
    for(int i=0; i<row->col_count; i++){
        printf("%s %s\n", row->col_names[i], row->row_vals[i]);
    }
    distroy_row(row); 
    /* print_table(table); */
    distroy_table(table);
}
