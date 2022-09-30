#include <gtk/gtk.h>
#include <string.h>


GtkWidget *root;
GtkWidget *fixed;
int window_height;
int window_width;
char window_title[];

void add_widget_to_window(GtkWidget *widget, int x, int y) {
	gtk_fixed_put(GTK_FIXED(fixed), widget, x, y);
}

void add_button(char label[], int x, int y) {
	GtkWidget *button = gtk_button_new_with_label(label);
	add_widget_to_window(button, x, y);
}

void add_check_button(char label[], int x, int y) {
	GtkWidget *check_btn = gtk_check_button_new_with_label(label);
	add_widget_to_window(check_btn, x, y);
}

void add_entry(char default_text[], int x, int y) {
	GtkWidget *entry = gtk_entry_new();
	if(!strcmp(default_text, "")) {
		gtk_entry_set_text(GTK_ENTRY(entry), default_text);
	}
	add_widget_to_window(entry, x, y);
}

void show_message_dialog(char title[], char message[]) {
	// TODO
}

void add_menu_bar() {
	// TODO
}

void add_radio() {
	// TODO
}

void add_link_button(char link[], char label[], int x, int y) {
	GtkWidget *link_btn = gtk_link_button_new_with_label(link, label);
	add_widget_to_window(link_btn, x, y);
}

void add_switch(int active, int x, int y) {
	GtkWidget *switch_btn = gtk_switch_new();
	gtk_switch_set_state(GTK_SWITCH(switch_btn), active);
	add_widget_to_window(switch_btn, x, y);
}

void add_label(char text[], int x, int y) {
	GtkWidget *label = gtk_label_new(text);
	add_widget_to_window(label, x, y);
}

void add_image(char file[], int x, int y) {
	GtkWidget *image = gtk_image_new_from_file(file);
	add_widget_to_window(image, x, y);
}

static void activate(GtkApplication *app, gpointer user_data) {
	root = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(root), window_title);
	gtk_window_set_default_size(GTK_WINDOW(root), window_width, window_height);
	fixed = gtk_fixed_new();

	g_signal_connect(root, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_container_add(GTK_CONTAINER(root), fixed);
	gtk_widget_show_all(root);
}

int start(char title[], int width, int height) {
	window_height = height;
	window_width = width;
	strcpy(window_title, title);

	GtkApplication *app;
	app = gtk_application_new("grephq.phpdesktop", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	int status = g_application_run(G_APPLICATION(app), 0, NULL);
	g_object_unref(app);

	return status;
}
