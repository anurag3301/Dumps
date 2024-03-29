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
    size_t* col_width;
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

void add_row(char** row_vals, Table* table);
void add_col(char* col_name, char** col_vals, Table* table);

char* const get_col_val(Column* col, size_t idx);

char* const get_row_val(Row* row, char* col_name, int to_free);

void print_table(Table* table);

Table* copy_table(Table* table);

void cell_update(Table* table, char* col_name, size_t row, char* new_val);

void delete_row(size_t row, Table* table);
void delete_col(char* col_name, Table* table);
