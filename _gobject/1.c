#include<glib-object.h>

int main(){
    GObject *in1, *in2;
    GObjectClass *class1, *class2;

    in1 = g_object_new(G_TYPE_OBJECT, NULL);
    in2 = g_object_new(G_TYPE_OBJECT, NULL);
    g_print("The address of instance1 is %p\n", in1);
    g_print("The address of instance2 is %p\n", in2);

    class1 = G_OBJECT_GET_CLASS(in1);
    class2 = G_OBJECT_GET_CLASS(in2);
    g_print("The address of the class of instance1 is %p\n", class1);
    g_print("The address of the class of instance2 is %p\n", class2);

    g_object_unref(in1);
    g_object_unref(in2);

}
