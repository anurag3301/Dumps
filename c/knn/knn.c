#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Column{
    char* colname;
    char** colvals;
    size_t col_count;
}Column;

typedef struct Table{
    Column *cols;
    size_t row_count, col_count;
    char** col_names;
}Table;

Table* init_table(char* file_name){
    FILE *f = fopen(file_name, "r");
    char *line = NULL;
    size_t len = 0;

    if(f == NULL){
        printf("Error in reading file");
        return NULL;
    }

    Table* table = malloc(sizeof(Table));

    getline(&line, &len, f);
    size_t comma_count = 0;
    for(int i=0; line[i]!='\0'; i++)if(line[i]==',')comma_count++;
    table->col_count = ++comma_count;

    rewind(f);
    size_t line_count = 0;
    while(getline(&line, &len, f) != -1)line_count++;
    table->row_count = line_count;
    
    rewind(f);
    getline(&line, &len, f);
    free(line);
    return table;
}

int main(){
    Table* table = init_table("iris.csv");
}
