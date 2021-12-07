// My Application
//


// Libraries
#include <gtk/gtk.h> // GTK Library
#include <stdio.h> // C IO Library (Not needed)

// Variables
GtkWidget *window; // Window
GtkLabel *mylabel; // Label
GtkLabel *label00;
GtkLabel *label01;
GtkLabel *label02;
GtkLabel *label10;
GtkLabel *label11;
GtkLabel *label12;
GtkLabel *label20;
GtkLabel *label21;
GtkLabel *label22;

// Main function
int main(int argc, char *argv[])
{
	GtkBuilder *builder; // GTK Builder variable
	gtk_init(&argc, &argv); // Start GTK

	builder = gtk_builder_new(); // Create GTK UI Builder
	gtk_builder_add_from_file(builder, "myui2.glade", NULL); // Load our UI file

	// Assign the Variables
	window = GTK_WIDGET(gtk_builder_get_object(builder, "MyWindow")); // Load our window named MyWindow
	mylabel = GTK_LABEL(gtk_builder_get_object(builder, "MyLabel")); // Load our label named MyLabel
	label00 = GTK_LABEL(gtk_builder_get_object(builder, "label00"));
	label01 = GTK_LABEL(gtk_builder_get_object(builder, "label01"));
	label02 = GTK_LABEL(gtk_builder_get_object(builder, "label02"));
	label10 = GTK_LABEL(gtk_builder_get_object(builder, "label10"));
	label11 = GTK_LABEL(gtk_builder_get_object(builder, "label11"));
	label12 = GTK_LABEL(gtk_builder_get_object(builder, "label12"));
	label20 = GTK_LABEL(gtk_builder_get_object(builder, "label20"));
	label21 = GTK_LABEL(gtk_builder_get_object(builder, "label21"));
	label22 = GTK_LABEL(gtk_builder_get_object(builder, "label22"));
	// Essential for a GTK based program
	gtk_builder_connect_signals(builder, NULL);
	g_object_unref(builder);

	gtk_widget_show_all(window); // Show our window
	gtk_main(); // Run our program

	return 0; // Necessary for a c main function
}

// Function to exit our app
void exit_app()
{
	printf("Exit app \n"); // Not neccesary
	gtk_main_quit(); // Command to quit a GTK program
}

// Function when our button is pressed
void button00_clicked()
{
	printf("Button clicked \n");
	gtk_label_set_text(label00, "pressed");
}

void button01_clicked()
{
	printf("Button clicked \n");
	gtk_label_set_text(label01, "pressed");
}

void button02_clicked()
{
	printf("Button clicked \n");
	gtk_label_set_text(label02, "pressed");
}

void button10_clicked()
{
	printf("Button clicked \n");
	gtk_label_set_text(label10, "pressed");
}

void button11_clicked()
{
	printf("Button clicked \n");
	gtk_label_set_text(label11, "pressed");
}

void button12_clicked()
{
	printf("Button clicked \n");
	gtk_label_set_text(label12, "pressed");
}

void button20_clicked()
{
	printf("Button clicked \n");
	gtk_label_set_text(label20, "pressed");
}

void button21_clicked()
{
	printf("Button clicked \n");
	gtk_label_set_text(label21, "pressed");
}

void button22_clicked()
{
	printf("Button clicked \n");
	gtk_label_set_text(label22, "pressed");
}
