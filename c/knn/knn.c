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

char* substr(char* raw_str, size_t idx, size_t len){
    char* result = malloc(sizeof(char)*(len+1));
    int i, j;
    for(i=idx, j=0; i<=(len+idx-1) && raw_str[i]!='\0'; i++, j++){
        result[j] = raw_str[i];
    }
    result[j] = '\0';
    return result;
}

char** parse_row(char* line, size_t col_num){
    char** str_vec = malloc(sizeof(char*) * col_num);
    int len = strlen(line);
    for(int pos=0, idx=0; pos < len; pos++, idx++){
        int i;
        for(i=pos; line[i]!='\0'&&line[i]!=','; i++); 
        str_vec[idx] = substr(line, pos, i-pos);
        pos = i;
    }
    return str_vec;
}

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
    char** col_names = parse_row(line, table->col_count);
    table->col_names = col_names;
    for(int i=0; i<table->col_count; i++){
        printf("%s\n", table->col_names[i]);
    }

    free(line);
    return table;
}



int main(){
    Table* table = init_table("iris.csv");
    /* char** res = parse_row("hel,my,name,is,asdf", 5); */
    free(table);
}
