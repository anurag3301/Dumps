#include<gtk/gtk.h>

int main(){
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button;

    gtk_init(NULL, NULL);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 250);

    grid = gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_container_add(GTK_CONTAINER(window), grid);

    button = gtk_button_new_with_label("Click");
    g_object_set(button, "margin", 25, NULL);

    gtk_container_add(GTK_CONTAINER(grid), button);

    gtk_widget_show_all(window);
    gtk_main();

}
