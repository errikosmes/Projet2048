#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include "entete.h"



gboolean on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data);


int main(int argc, char *argv[]){
    GtkBuilder      *builder;
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

    // get pointers to the labels
    g_lbl_hello = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_hello"));
    g_lbl_count = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_count"));
    g_lbl_grid_0_0 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_0_0"));
    g_lbl_grid_0_1 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_0_1"));
    g_lbl_grid_0_2 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_0_2"));
    g_lbl_grid_0_3 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_0_3"));
	g_lbl_grid_1_0 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_1_0"));
    g_lbl_grid_1_1 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_1_1"));
    g_lbl_grid_1_2 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_1_2"));
    g_lbl_grid_1_3 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_1_3"));
	g_lbl_grid_2_0 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_2_0"));
    g_lbl_grid_2_1 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_2_1"));
    g_lbl_grid_2_2 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_2_2"));
    g_lbl_grid_2_3 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_2_3"));
	g_lbl_grid_3_0 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_3_0"));
    g_lbl_grid_3_1 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_3_1"));
    g_lbl_grid_3_2 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_3_2"));
    g_lbl_grid_3_3 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_3_3"));

    int **GRILLE = init_grille();
    
    g_object_unref(builder);

    g_signal_connect (G_OBJECT (window), "key_press_event", G_CALLBACK (on_key_press), NULL);

    gtk_widget_show(window);

    gtk_main();

    return 0;
}

gboolean on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data){
    char str_label[30] = {0};
    
    switch (event->keyval){
        case GDK_KEY_z:
            printf("key pressed: %s\n", "z");
            affichage_grille(GRILLE);
            break;
        case GDK_KEY_q:
            printf("key pressed: %s\n", "q");
            break;
        case GDK_KEY_s:
            printf("key pressed: %s\n", "s");
            break;
        case GDK_KEY_d:
            printf("key pressed: %s\n", "d");
            break;
        default:
            return FALSE; 
  	}
  	return FALSE;
}




