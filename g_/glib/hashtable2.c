#include<stdio.h>
#include<glib.h>

int main(){
    GHashTable *table = g_hash_table_new(g_int_hash, g_str_equal); 
    int a=1001, b=1002, c=1003;
    g_hash_table_insert(table, &a, "Anurag"); 
    g_hash_table_insert(table, &b, "Parul");
    g_hash_table_insert(table, &c, "Arindam");

    printf("%d => %s\n", a, g_hash_table_lookup(table, &a)); 
    printf("%d => %s\n", b, g_hash_table_lookup(table, &b)); 
    printf("%d => %s\n", c, g_hash_table_lookup(table, &c)); 

    
}
