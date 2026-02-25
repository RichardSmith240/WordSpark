#include <gtk/gtk.h>

GtkApplication *app = NULL;

static void print_hello_world(GtkWidget *widget, gpointer data) {
	g_print("Hello World");
}

static void playback_pause(GtkWidget *widget, gpointer data) {
	g_print("󰏤");
}

static void playback_play(GtkWidget *widget, gpointer data) {
	g_print("󰐊");
}



static void activate (GtkApplication *app, gpointer user_data) {
	GtkWidget *window;
	GtkWidget *grid;
	GtkWidget *entry;

	//reminder to use one button pointer in the future
	GtkWidget *hw_button;
	GtkWidget *play_button;
	GtkWidget *pause_button;

	window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "UI Testing Window");
	gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

	//create grid
	grid = gtk_grid_new();
	gtk_window_set_child(GTK_WINDOW(window), grid);
	
	// Hello World Button 
	hw_button = gtk_button_new_with_label("Standard Start");
	g_signal_connect(hw_button, "clicked", G_CALLBACK(print_hello_world), NULL);
	
	// play button
	play_button = gtk_button_new_with_label("Play");
	g_signal_connect(play_button, "clicked", G_CALLBACK(playback_play), NULL);

	// Pause button 
	pause_button = gtk_button_new_with_label("Pause");
	g_signal_connect(pause_button, "clicked", G_CALLBACK(playback_pause), NULL);

	//place buttons on grid 	
	// gtk_grid_attach(*grid, *child, column, row, width, height)	
	gtk_grid_attach(GTK_GRID(grid), hw_button, 1, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(grid), pause_button, 1, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), play_button, 2, 1, 1, 1);

	gtk_window_present (GTK_WINDOW (window));
}

int cleanup(void) {
	if (app != NULL) {
		g_object_unref(app);
		app = NULL;
		printf("CLEANUP\n");
	}
}

int main (int argc, char **argv) {
	int status;

	app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
	atexit(cleanup);
	status = g_application_run (G_APPLICATION (app), argc, argv);
	if (app != NULL) {
		g_object_unref (app);
		app = NULL;
	}

	return status;
}
