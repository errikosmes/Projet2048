#include "entete.h"








int main(int argc, char *argv[]){
    GtkBuilder      *builder;
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

    // get pointers to the labels
	g_lbl_score = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_score"));
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

	srand(time(0));
    GRILLE = init_grille();
    affichage_grille(GRILLE);
    SCORE = 0;

    g_object_unref(builder);

    g_signal_connect (G_OBJECT (window), "key_press_event", G_CALLBACK (on_key_press), NULL);

    gtk_widget_show(window);

    gtk_main();

    return 0;
}
