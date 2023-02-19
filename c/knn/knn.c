#include <stdio.h>
#include <stdlib.h>
#include "csv.h"

int main(){
    Table* table = init_table("username.csv");

    Row* row = get_row(3, table);
    char* dat = get_row_val(row, "Identifier", 0);
    printf("%s\n", dat);
    distroy_row(row);

    dat = get_row_val(get_row(3, table), "Identifier", 1);
    printf("%s\n", dat);
    free(dat);

    distroy_table(table);
}
