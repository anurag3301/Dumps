#include <stdio.h>
#include <stdlib.h>
#include "csv.h"

int main(){
    Table* table = init_table("username.csv");
    Table* new = copy_table(table);
        
    print_table(new);

    distroy_table(table);
    distroy_table(new);
}
