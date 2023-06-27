#include<gtk/gtk.h>

int main(){
    GtkWidget *window, *button;
    gtk_init(NULL, NULL);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 250);

    button = gtk_button_new_with_label("Click");
    g_object_set(button, "margin", 25, NULL);
    gtk_container_add(GTK_CONTAINER(window), button);

    GValue value = G_VALUE_INIT;
    g_value_init(&value, G_TYPE_STRING);
    g_assert(G_VALUE_HOLDS_STRING(&value));
    g_value_set_static_string(&value, "Exit");

    if(G_VALUE_HOLDS(&value, G_TYPE_STRING)){
        g_print("True\n");
        g_object_set_property(G_OBJECT(button), "label", &value);
    }

    gtk_widget_show_all(window);
    gtk_main();
}
