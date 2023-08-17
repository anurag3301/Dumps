#include<glib-2.0/glib.h>
#include<stdio.h>

int main(){

    GSList *list = NULL;
    list = g_slist_append(list, "first");
    list = g_slist_append(list, "Second");
    list = g_slist_append(list, "Third");
    printf("The list is not %d items long\n", g_slist_length(list));
    printf("THe last item is %s\n", g_slist_last(list)->data);
    printf("The item at index 1 is %s\n", g_slist_nth(list, 1)->data);
    printf("Now the item at index 1 the easy way: %s\n", g_slist_nth_data(list, 1));
    printf("And the next item after first is %s\n", g_slist_next(list)->data);
    g_slist_free(list);

}
