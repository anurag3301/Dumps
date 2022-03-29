#include<glib-object.h>

static void show_ref_count(GObject *instance){
    if(G_IS_OBJECT(instance))
        g_print("Reference count is %d\n", instance->ref_count);
    else
        g_print("Instance is not GObject\n");
}

int main(){
    GObject *instance;

    instance = g_object_new(G_TYPE_OBJECT, NULL);
    g_print("Called g_object_new\n");

    show_ref_count(instance);
    g_object_ref(instance);
    g_print("Called g_object_ref\n");
    
    show_ref_count(instance);
    g_object_unref(instance);
    g_print("Called g_object_uref\n");

    show_ref_count(instance);
    g_object_unref(instance);
    g_print("Called g_object_uref\n");
}
