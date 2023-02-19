#include <stdio.h>
#include <stdlib.h>
#include "csv.h"

int main(){
    Table* table = init_table("username.csv");
        
    cell_update(table, "Identifier", 0, "hello"); 
    print_table(table);

    distroy_table(table);
}
