#include <stdio.h>
#include <stdlib.h>
#include "csv.h"

int main(){
    Table* table = init_table("username.csv");
        
    print_table(table);
    char* col_vals[] = {"1", "2", "3", "4", "5"};
    add_col("hello", col_vals, table);

    print_table(table);

    distroy_table(table);
}
