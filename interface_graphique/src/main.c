#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

gboolean on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data);


GtkWidget *g_lbl_hello;
GtkWidget *g_lbl_count;
GtkWidget *g_lbl_grid_0_0;
GtkWidget *g_lbl_grid_0_4;

int main(int argc, char *argv[])
{
    char str_label[30] = {0};

    GtkBuilder      *builder; 
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);
    
    // get pointers to the two labels
    g_lbl_hello = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_hello"));
    g_lbl_count = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_count"));
    g_lbl_grid_0_0 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_0_0"));
    g_lbl_grid_0_4 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_0_4"));

    g_object_unref(builder);

    g_signal_connect (G_OBJECT (window), "key_press_event", G_CALLBACK (on_key_press), NULL);

    gtk_widget_show(window);

    sprintf(str_label, "%d", 12);
    gtk_label_set_text(GTK_LABEL(g_lbl_grid_0_4), str_label);


    gtk_main();

    return 0;
}

// called when button is clicked
void on_btn_hello_clicked()
{
    static unsigned int count = 0;
    char str_count[30] = {0};
    
    gtk_label_set_text(GTK_LABEL(g_lbl_hello), "Hello, world!");
    count++;
    sprintf(str_count, "%d", count);
    gtk_label_set_text(GTK_LABEL(g_lbl_count), str_count);

    gtk_label_set_text(GTK_LABEL(g_lbl_grid_0_0), str_count);
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}

gboolean on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data){
  switch (event->keyval){
    case GDK_KEY_z:
      printf("key pressed: %s\n", "z");
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