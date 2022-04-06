#include<stdio.h>

/* typedef struct{ */
/*     char* name; */
/*     int age; */
/* }person; */

typedef struct _person person;
struct _person{
    char* name;
    int age;
};

int main(){
    person p1;
    p1.name = "Anurag";
    p1.age = 12;
    printf("%s %d\n", p1.name, p1.age);

    person p2;
    p2.name = "Parul";
    p2.age = 18;
    printf("%s %d\n", p2.name, p2.age);
}

