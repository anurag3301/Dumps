#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "csv.h"

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
        for(i=pos; line[i]!='\0'&&line[i]!=','&&line[i]!='\n'; i++); 
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
    table->max_size = pow(2, ceil(log2(table->row_count)));
    for(size_t i=0; i<table->col_count; i++){
        table->cols[i].colvals = malloc(sizeof(char*)*table->max_size);
        table->cols[i].row_count = table->row_count;
    }
    
    rewind(f);
    getline(&line, &len, f);
    char** col_names = parse_row(line, table->col_count);
    table->col_names = col_names;
    for(int i=0; i<table->col_count; i++){
        table->cols[i].colname = table->col_names[i];
    }


    rewind(f);
    getline(&line, &len, f);
    for(size_t line_no=0; getline(&line, &len, f) != -1; line_no++){
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

Column* const get_col(char* col_name, Table* table){
    for(int i=0; i<table->col_count; i++){
        if(strcmp(col_name, table->col_names[i]) == 0){
            return &table->cols[i];
        }
    }
    return NULL;
}


Row* const get_row(size_t rowno, Table* table){
    Row* row = malloc(sizeof(Row));
    row->col_count = table->col_count;
    row->col_names = table->col_names;
    row->row_vals = malloc(sizeof(char*) * table->col_count);
    if(rowno >= table->row_count) return NULL;
    for(size_t i=0; i<table->col_count; i++){
        row->row_vals[i] = table->cols[i].colvals[rowno];
    }
    return row;
}

void add_row(char** row_vals, Table* table){
    if(table->max_size == table->row_count){
        table->max_size *= 2;
        for(size_t i=0; i<table->col_count; i++){
            table->cols[i].colvals = realloc(table->cols[i].colvals, sizeof(char*) * table->max_size);
            table->cols[i].max_size = table->max_size;
        }
    }
    for(size_t i=0; i<table->col_count; i++){
        table->cols[i].colvals[table->row_count] = strdup(row_vals[i]);
        table->cols[i].row_count++;
    }
    table->row_count++;
}

void distroy_row(Row* row){
    free(row->row_vals);
    free(row);
}

char* const get_col_val(Column* col, size_t idx){
    if(col == NULL) return NULL;
    if(idx >= col->row_count) return NULL;
    return col->colvals[idx];
}

char* const get_row_val(Row* row, char* col_name, int to_free){
    if(row == NULL) return NULL;
    for(size_t i=0; i<row->col_count; i++){
        if(strcmp(col_name, row->col_names[i]) == 0){
            char* result;
            if(to_free){
                result = strdup(row->row_vals[i]);
                distroy_row(row);
            }else{
                result = row->row_vals[i];
            }
            return result;
        }
    }
    return NULL;
}

void print_table(Table* table){
    printf("\nNumber of rows: %zu and Number of cols: %zu\n\n", table->row_count, table->col_count);
    for(size_t i=0; i<table->col_count; i++){
        printf("%s,\t", table->col_names[i]);
    }
    for(size_t row=0; row<table->row_count; row++){
        printf("\n");
        for(size_t col=0; col<table->col_count; col++){
            printf("%s,\t", table->cols[col].colvals[row]);
        }
    }
    printf("\n");
}

Table* copy_table(Table* table){
    Table* new = malloc(sizeof(Table));
    new->col_count = table->col_count;
    new->row_count = table->row_count;
    new->max_size = table->max_size;

    new->cols = malloc(sizeof(Column) * new->col_count);

    new->col_names = malloc(sizeof(char*) * new->col_count);
    for(size_t i=0; i<new->col_count; i++){
        new->cols[i].row_count = new->row_count;
        new->cols[i].max_size = new->max_size;

        new->col_names[i] = strdup(table->col_names[i]);
        new->cols[i].colname = new->col_names[i];

        new->cols[i].colvals = malloc(sizeof(char*) * new->max_size);
        for(size_t j=0; j<new->row_count; j++){
            new->cols[i].colvals[j] = strdup(table->cols[i].colvals[j]);
        }
    }

    return new;
}

void cell_update(Table* table, char* col_name, size_t row, char* new_val){
    Column* col = get_col(col_name, table);
    if(col == NULL)return;
    if(row >= col->row_count)return;
    free(col->colvals[row]);
    col->colvals[row] = strdup(new_val); 
}






