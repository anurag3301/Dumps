#include <stdio.h>
#include <stdlib.h>
#include "csv.h"

int main(){
    Table* table = init_table("username.csv");
    
    print_table(table);
    delete_col("Username", table);
    print_table(table);
    delete_col("Location", table);
    print_table(table);
    distroy_table(table);
}
