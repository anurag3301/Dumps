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

    Table* table = malloc(sizeof(table));

    getline(&line, &len, f);
    uint comma_numer = 0;
    for(int i=0; line[i]!='\0'; i++)if(line[i]==',')comma_numer++;
    printf("%d", comma_numer);
    
    free(line);
    return table;
}

int main(){
    Table* table = init_table("iris.csv");
}
