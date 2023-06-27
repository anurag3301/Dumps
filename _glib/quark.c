#include<glib.h>

int main(){
    GQuark new = g_quark_from_static_string("Hello");
    GQuark new1 = g_quark_from_static_string("Welcome");
    GQuark new2 = g_quark_from_static_string("String");
    g_print("%d, %d, %d\n", new, new1, new2);
    g_print("%d, %d, %d\n", g_quark_try_string("Hello"), 
            g_quark_try_string("Welcome"), 
            g_quark_try_string("String"));

    g_print("%d: %s, %d: %s, %d: %s\n", 
            new, g_quark_to_string(new), 
            new1, g_quark_to_string(new1), 
            new2, g_quark_to_string(new2));

    g_print("%d: %s: %s, %d: %s: %s, %d: %s: %s\n", 
            new, g_quark_to_string(new), g_intern_string(g_quark_to_string(new)), 
            new1, g_quark_to_string(new1),g_intern_string(g_quark_to_string(new1)), 
            new2, g_quark_to_string(new2), g_intern_string(g_quark_to_string(new2)));
    g_print("%s\n", g_intern_string("Fuck"));
}
