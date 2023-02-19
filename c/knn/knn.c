#include <stdio.h>
#include "csv.h"

int main(){
    Table* table = init_table("username.csv");

    char* dat = get_col_val(get_col("Identifier", table), 0);
    printf("%s\n", dat);

    print_table(table);
    printf("%zu\n", table->max_size);

    distroy_table(table);
}
