#include <stdio.h>

typedef struct Column{
    char* colname;
    char** colvals;
    size_t row_count;
    size_t max_size;
}Column;

typedef struct Table{
    Column *cols;
    char** col_names;
    size_t row_count;
    size_t col_count;
    size_t max_size;
}Table;

char* substr(char* raw_str, size_t idx, size_t len);

char** parse_row(char* line, size_t col_num);

Table* init_table(char* file_name);

void distroy_table(Table* table);

void print_table(Table* table);
