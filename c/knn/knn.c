#include <stdio.h>
#include "csv.h"

int main(){
    Table* table = init_table("iris.csv");
    /* Table* table = init_table("iris_full.csv"); */
    print_table(table);
    distroy_table(table);
}
