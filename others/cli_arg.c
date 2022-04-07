#include<stdio.h>

int main(int argc, char** argv){
    printf("You Enter following args:n\n");
    for(int i=0; i<argc; i++){
        printf("%s\n", argv[i]);
    }
}
