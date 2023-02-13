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

typedef struct Row{
    char** col_names;
    char** row_vals;
    size_t col_count;
}Row;

char* substr(char* raw_str, size_t idx, size_t len);

char** parse_row(char* line, size_t col_num);

Table* init_table(char* file_name);

void distroy_table(Table* table);

Column* const get_col(char* col_name, Table* table);

Row* const get_row(size_t rowno, Table* table);
void distroy_row(Row* row);

void print_table(Table* table);
