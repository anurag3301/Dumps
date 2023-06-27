#include<glib.h>
#include<stdio.h>

void print_itr(gpointer item, gpointer prefix){
    printf("%s %s\n", prefix, item);
}

void print_itr_short(gpointer item){
    printf("%s\n", item);
}

int main(){
    GCompareFunc
    GSList *list = g_slist_append(NULL, g_strdup("First"));
    list = g_slist_append(list, g_strdup("second"));
    list = g_slist_append(list, g_strdup("third"));
    printf("Iterating with a funcion \n");
    g_slist_foreach(list, (GFunc)print_itr_short, NULL);
    printf("Now freeing each item\n");
    g_slist_foreach(list, (GFunc)g_free, NULL);
    g_slist_free(list);
}
