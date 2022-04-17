#include<gtk/gtk.h>

void button_clicked(GtkWidget* widget, gpointer data){
    GSList *iterator=NULL;
    g_print("Button is pressed \n");
    for(iterator = data; iterator; iterator = iterator->next){
        printf("Current item is %s and the ptr: %p next: %p\n", iterator->data, iterator, iterator->next);
    }
}

int main(int argc, char *argv[]){
    gtk_init(&argc, &argv);
    GSList *list = NULL;
    list = g_slist_append(list, "first");
    list = g_slist_append(list, "Second");
    list = g_slist_append(list, "Third");

    GtkWidget *window, *button;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    button = gtk_button_new_with_label("Click me");
    g_signal_connect(window, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(button,  "clicked", G_CALLBACK(button_clicked), list);
    gtk_container_add(GTK_CONTAINER(window), button);
    gtk_widget_show_all(window);
    gtk_main();
}
