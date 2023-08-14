#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "csv.h"

static size_t max_size_t(size_t a, size_t b){
    if(a>b){
        return a;
    }
    return b;
}

static void print_pad(char* str, size_t width){
    size_t length = strlen(str);
    size_t space_count = (length<width)?(width-length):0;
    printf("%s, ", str);
    while(space_count--)printf(" ");
}

static void dos2unix(char *line){
    size_t length = strlen(line); 

    if(line[length-2] == '\r'){
        line[length-2] = '\n';
        line[length-1] = '\0';
    }
}

char* substr(char* raw_str, size_t idx, size_t len){
    for(; raw_str[idx]==' '; idx++,len--);
    for(; raw_str[idx+len-1]==' '; len--);
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
    // Open file and check if its valid
    FILE *f = fopen(file_name, "r");
    char *line = NULL;
    size_t len = 0;

    if(f == NULL){
        printf("Error in reading file");
        return NULL;
    }

    Table* table = malloc(sizeof(Table));

    // Read first line and figure out number of cols
    getline(&line, &len, f);
    size_t comma_count = 0;
    for(int i=0; line[i]!='\0'; i++)if(line[i]==',')comma_count++;
    table->col_count = ++comma_count;
    table->cols = malloc(sizeof(Column) * table->col_count);
    table->col_width = calloc(table->col_count, sizeof(size_t));


    // Go through the file to figureout number of lines ie. number of rows
    rewind(f);
    size_t line_count = 0;
    while(getline(&line, &len, f) != -1)line_count++;
    table->row_count = --line_count;
    if(table->row_count == 0)
        table->max_size =  2;
    else
        table->max_size =  pow(2, ceil(log2(table->row_count)));
    for(size_t i=0; i<table->col_count; i++){
        table->cols[i].colvals = malloc(sizeof(char*)*table->max_size);
        table->cols[i].row_count = table->row_count;
    }
    
    // Read first line againg and initialise the col names
    rewind(f);
    getline(&line, &len, f);
    dos2unix(line);
    char** col_names = parse_row(line, table->col_count);
    table->col_names = col_names;
    for(int i=0; i<table->col_count; i++){
        table->cols[i].colname = table->col_names[i];
        table->col_width[i] = max_size_t(table->col_width[i], strlen(table->col_names[i]));
    }


    // read each line, parse it and create the entire table
    rewind(f);
    getline(&line, &len, f);
    for(size_t line_no=0; getline(&line, &len, f) != -1; line_no++){
        dos2unix(line);
        char** res = parse_row(line, table->col_count);
        for(size_t i=0; i<table->col_count; i++){
            table->cols[i].colvals[line_no] = res[i];
            table->col_width[i] = max_size_t(table->col_width[i], strlen(res[i]));
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
    free(table->col_width);

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


void add_col(char* col_name, char** col_vals, Table* table){
    table->col_count++;
    table->col_names = realloc(table->col_names, sizeof(char*) * table->col_count);
    table->cols = realloc(table->cols, sizeof(Column) * table->col_count);
    table->col_names[table->col_count-1] = strdup(col_name);

    Column* new_col = &table->cols[table->col_count-1];
    new_col->colname = table->col_names[table->col_count-1];
    new_col->row_count = table->row_count;
    new_col->max_size = table->max_size;
    new_col->colvals = malloc(sizeof(char*) * new_col->max_size);
    for(size_t i=0; i<new_col->row_count; i++){
        new_col->colvals[i] = strdup(col_vals[i]);
    }

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
        print_pad(table->col_names[i], table->col_width[i]);
    }
    for(size_t row=0; row<table->row_count; row++){
        printf("\n");
        for(size_t col=0; col<table->col_count; col++){
            print_pad(table->cols[col].colvals[row], table->col_width[col]);
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
    new->col_width = malloc(sizeof(size_t) * new->col_count);
    for(size_t i=0; i<new->col_count; i++){
        new->cols[i].row_count = new->row_count;
        new->cols[i].max_size = new->max_size;
        new->col_width[i] = table->col_width[i];

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


void delete_row(size_t row, Table* table){
    if(row >= table->row_count)return;

    for(size_t i=0; i<table->col_count; i++){
        free(table->cols[i].colvals[row]);
    }

    for(size_t i=0; i<table->col_count; i++){
        for(size_t j=row; j<table->row_count-1; j++){
            table->cols[i].colvals[j] = table->cols[i].colvals[j+1];
        }
        table->cols[i].row_count--;
    }
    table->row_count--;
}


void delete_col(char* col_name, Table* table){
    size_t col_idx;
    for(col_idx=0; col_idx<table->col_count &&
            strcmp(table->col_names[col_idx], col_name) != 0; col_idx++);

    Column col = table->cols[col_idx];
    for(size_t i=0; i<table->row_count; i++){
        free(col.colvals[i]);
    }
    free(col.colvals);
    free(table->col_names[col_idx]);

    for(size_t i=col_idx; i<table->col_count-1; i++){
        table->col_names[i] = table->col_names[i+1];
        table->cols[i] = table->cols[i+1];
    }


    table->col_count--;
    table->col_names = realloc(table->col_names, sizeof(char*) * table->col_count);
    table->cols = realloc(table->cols, sizeof(Column) * table->col_count);
}
