// My Application
//


// Libraries
#include <gtk/gtk.h> // GTK Library
#include <stdio.h> // C IO Library (Not needed)

#include <ctype.h>
#include <time.h>

// Variables
GtkWidget *window; // Window
GtkLabel *state_label;
GtkLabel *lab1;
GtkLabel *lab2;
GtkLabel *lab3;
GtkLabel *lab4;
GtkLabel *lab5;
GtkLabel *lab6;
GtkLabel *lab7;
GtkLabel *lab8;
GtkLabel *lab9;

void printBoard();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);
int checkFreeSpaces();

char board[3][3] = {{0,0,0},
                    {0,0,0},
                    {0,0,0}};
const char PLAYER = 'X';
const char COMPUTER = 'O';
char winner = ' ';

// Main function
int main(int argc, char *argv[])
{
	GtkBuilder *builder; // GTK Builder variable
	gtk_init(&argc, &argv); // Start GTK



	builder = gtk_builder_new(); // Create GTK UI Builder
	gtk_builder_add_from_file(builder, "game-grid.glade", NULL); // Load our UI file

	// Assign the Variables
  window = GTK_WIDGET(gtk_builder_get_object(builder, "MyWindow2")); // Load our window named MyWindow
  state_label = GTK_LABEL(gtk_builder_get_object(builder, "state"));
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
  printBoard();

	gtk_widget_show_all(window); // Show our window
	gtk_main(); // Run our program

	return 0; // Necessary for a c main function
}

void gato_main(int x, int y){


  playerMove(x, y);
  computerMove();
  printBoard();
  winner = checkWinner();
  printWinner(winner);

}
// Function to exit our app
void exit_app()
{
	printf("Exit app \n"); // Not neccesary
	gtk_main_quit(); // Command to quit a GTK program
}

// Function when our button is pressed
void button1_clicked()
{
	printf("Button1 clicked \n");
	gtk_label_set_text(lab1, "X");
  gato_main(0,0);
}

void button2_clicked()
{
	printf("Button2 clicked \n");
	gtk_label_set_text(lab2, "X");
  gato_main(0,1);
}

void button3_clicked()
{
	printf("Button3 clicked \n");
	gtk_label_set_text(lab3, "X");
  gato_main(0,2);
}

void button4_clicked()
{
	printf("Button4 clicked \n");
	gtk_label_set_text(lab4, "X");
  gato_main(1,0);
}

void button5_clicked()
{
	printf("Button5 clicked \n");
	gtk_label_set_text(lab5, "X");
  gato_main(1,1);
}

void button6_clicked()
{
	printf("Button6 clicked \n");
	gtk_label_set_text(lab6, "X");
  gato_main(1,2);
}

void button7_clicked()
{
	printf("Button7 clicked \n");
	gtk_label_set_text(lab7, "X");
  gato_main(2,0);
}

void button8_clicked()
{
	printf("Button8 clicked \n");
	gtk_label_set_text(lab8, "X");
  gato_main(2,1);
}

void button9_clicked()
{
	printf("Button9 clicked \n");
	gtk_label_set_text(lab9, "X");
  gato_main(2,2);
}

void printBoard()
{
   printf(" %d | %d | %d ", board[0][0], board[0][1], board[0][2]);
   printf("\n---|---|---\n");
   printf(" %d | %d | %d ", board[1][0], board[1][1], board[1][2]);
   printf("\n---|---|---\n");
   printf(" %d | %d | %d ", board[2][0], board[2][1], board[2][2]);
   printf("\n");
}
void playerMove(int x, int y) {
    if (board[x][y] == 0) {
        board[x][y] = 1; // 1 es igual a la X en el gato
        printf("board[%d][%d] = %d\n", x, y, board[x][y]);
    }
}
void computerMove() {
    srand(time(0));
    int a;
    int b;
    do {
    a = rand() % 3;
    b = rand() % 3;

  }while (board[a][b] == 1 || board[a][b] == 2);
        board[a][b] = 2; // 2 es igual al O en el gato
        printf("computermove :board[%d][%d] = %d\n", a, b, board[a][b]);
    }
char checkWinner() {
   //check rows
   for(int i = 0; i < 3; i++)
   {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
      {

         return board[i][0];
      }
   }
   //check columns
   for(int i = 0; i < 3; i++)
   {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
      {

         return board[0][i];
      }
   }
   //check diagonals
   if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
   {

      return board[0][0];
   }
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
   {

      return board[0][2];
   }

   return ' ';
}

void printWinner(char winner)
{
   if(winner == 1) // 1 ES LA X DEL JUGADOR
   {
      printf("YOU WIN!");
      gtk_label_set_text(state_label, "YOU WIN!");
   }
   else if(winner == 2) // 2 ES EL CIRCULO DEL JUGADOR
   {
      printf("YOU LOSE!");
      gtk_label_set_text(state_label, "YOU LOSE!");
   }
   else if (checkFreeSpaces() == 1) {
      printf("IT'S A TIE!");
      gtk_label_set_text(state_label, "IT'S A TIE!");
   }
 }

 int checkFreeSpaces() {
   {
      int freeSpaces = 9;

      for(int i = 0; i < 3; i++)
      {
         for(int j = 0; j < 3; j++)
         {
            if(board[i][j] != ' ')
            {
               freeSpaces--;
            }
         }
      }
      return freeSpaces;
   }
 }
