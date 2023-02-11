#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *f = fopen("iris.csv", "r");
    char *line_buf = NULL;
    size_t len = 0;



    if(f == NULL){
        printf("Error in reading file");
        return 1;
    }

    getline(&line_buf, &len, f);

    rewind(f);

    getline(&line_buf, &len, f);

    fclose(f);
    free(line_buf);
}
