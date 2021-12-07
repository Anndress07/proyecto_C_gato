#include <gtk/gtk.h> // GTK Library
#include <stdio.h>


GtkWidget *window; // Window
GtkLabel *lab1;
GtkLabel *lab2;
GtkLabel *lab3;
GtkLabel *lab4;
GtkLabel *lab5;
GtkLabel *lab6;
GtkLabel *lab7;
GtkLabel *lab8;
GtkLabel *lab9;

int main(int argc, char *argv[])
{
	GtkBuilder *builder; // GTK Builder variable
	gtk_init(&argc, &argv); // Start GTK

	builder = gtk_builder_new(); // Create GTK UI Builder
	gtk_builder_add_from_file(builder, "game-grid.glade", NULL); // Load our UI file

	// // Assign the Variables
	window = GTK_WIDGET(gtk_builder_get_object(builder, "MyWindow2")); // Load our window named MyWindow
  lab1 = GTK_LABEL(gtk_builder_get_object(builder, "lab1"));
  lab2 = GTK_LABEL(gtk_builder_get_object(builder, "lab2"));
  lab3 = GTK_LABEL(gtk_builder_get_object(builder, "lab3"));
  lab4 = GTK_LABEL(gtk_builder_get_object(builder, "lab4"));
  lab5 = GTK_LABEL(gtk_builder_get_object(builder, "lab5"));
  lab6 = GTK_LABEL(gtk_builder_get_object(builder, "lab6"));
  lab7 = GTK_LABEL(gtk_builder_get_object(builder, "lab7"));
  lab8 = GTK_LABEL(gtk_builder_get_object(builder, "lab8"));
  lab9 = GTK_LABEL(gtk_builder_get_object(builder, "lab9"));

	// Essential for a GTK based program
	gtk_builder_connect_signals(builder, NULL);
	g_object_unref(builder);

	gtk_widget_show_all(window); // Show our window
	gtk_main(); // Run our program

	return 0; // Necessary for a c main function
}

void exit_app()
{
	printf("Exit app \n"); // Not neccesary
	gtk_main_quit(); // Command to quit a GTK program
}

void button1_clicked(){
  printf("1\n");
  gtk_label_set_text(lab1, "X");
}

void button2_clicked(){
  printf("2\n");
  gtk_label_set_text(lab2, "X");
}

void button3_clicked(){
  printf("3\n");
  gtk_label_set_text(lab3, "X");
}

void button4_clicked(){
  printf("4\n");
  gtk_label_set_text(lab4, "X");
}

void button5_clicked(){
  printf("5\n");
  gtk_label_set_text(lab5, "X");
}

void button6_clicked(){
  printf("6\n");
  gtk_label_set_text(lab6, "X");
}

void button7_clicked(){
  printf("7\n");
  gtk_label_set_text(lab7, "X");
}

void button8_clicked(){
  printf("8\n");
  gtk_label_set_text(lab8, "X");
}

void button9_clicked(){
  printf("9\n");
  gtk_label_set_text(lab9, "X");
}
