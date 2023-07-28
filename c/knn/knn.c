#include <stdio.h>
#include <stdlib.h>
#include "csv.h"

int main(){
    Table* table = init_table("iris_full.csv");
    /* Table* table = init_table("copy.csv"); */
    
    print_table(table);

    distroy_table(table);
}
