#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Column{
    char* colname;
    char** colvals;
    size_t row_count;
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
    table->cols = malloc(sizeof(Column) * table->col_count);

    rewind(f);
    size_t line_count = 0;
    while(getline(&line, &len, f) != -1)line_count++;
    table->row_count = --line_count;
    for(size_t i=0; i<table->col_count; i++){
        table->cols[i].colvals = malloc(sizeof(char*)*table->row_count);
        table->cols[i].row_count = table->row_count;
    }
    
    rewind(f);
    getline(&line, &len, f);
    line[strlen(line)-2] = '\0';
    char** col_names = parse_row(line, table->col_count);
    table->col_names = col_names;
    for(int i=0; i<table->col_count; i++){
        table->cols[i].colname = table->col_names[i];
    }


    rewind(f);
    getline(&line, &len, f);
    for(size_t line_no=0; getline(&line, &len, f) != -1; line_no++){
        line[strlen(line)-2] = '\0';
        char** res = parse_row(line, table->col_count);
        for(size_t i=0; i<table->col_count; i++){
            table->cols[i].colvals[line_no] = res[i];
        }
        free(res);
    }


    free(line);
    fclose(f);
    return table;
}

void distroy_table(Table* table){
    for(size_t row=0; row<table->row_count; row++){
        for(size_t col=0; col<table->col_count; col++){
            free(table->cols[col].colvals[row]);
        }
    }
    for(size_t i=0; i<table->col_count; i++){
        free(table->col_names[i]);
        free(table->cols[i].colvals);
    }
    free(table->col_names);
    free(table->cols);

    free(table);
}

void print_table(Table* table){
    for(size_t i=0; i<table->col_count; i++){
        printf("%s\t", table->col_names[i]);
    }
    for(size_t row=0; row<table->row_count; row++){
        printf("\n");
        for(size_t col=0; col<table->col_count; col++){
            printf("%s\t", table->cols[col].colvals[row]);
        }
    }
    printf("\n");
}

int main(){
    Table* table = init_table("iris.csv");
    /* Table* table = init_table("iris_full.csv"); */
    print_table(table);
    distroy_table(table);
}
