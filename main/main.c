// Libraries
#include <gtk/gtk.h> // GTK Library
// #include <stdio.h> // C IO Library (Not needed)

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
GtkWidget *reset_button;

// Botones
GtkWidget *button1;
GtkWidget *button2;
GtkWidget *button3;
GtkWidget *button4;
GtkWidget *button5;
GtkWidget *button6;
GtkWidget *button7;
GtkWidget *button8;
GtkWidget *button9;

void printBoard();
void playerMove();
void computerMove();
void nuevocheckWinner();
void printWinner(int);
void checkFreeSpaces();
void gtk_widget_set_sensitive(GtkWidget *widget, gboolean sensitive);
void disableButton();
void activateButton();

char board[3][3] = {{0,0,0},
                    {0,0,0},
                    {0,0,0}}; // Tablero de guia que se imprime en la terminal

const char PLAYER = 'X';
const char COMPUTER = 'O';
char winner = ' ';
int spaces;
int winnerExists = 0;

// Main function
int main(int argc, char *argv[])
{
	GtkBuilder *builder; // GTK Builder variable
	gtk_init(&argc, &argv); // Start GTK

	builder = gtk_builder_new(); // Create GTK UI Builder
	gtk_builder_add_from_file(builder, "gato_file.glade", NULL); // Load our UI file

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
  reset_button = GTK_WIDGET(gtk_builder_get_object(builder, "reset_button"));

  // Botones

  button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
  button2 = GTK_WIDGET(gtk_builder_get_object(builder, "button2"));
  button3 = GTK_WIDGET(gtk_builder_get_object(builder, "button3"));
  button4 = GTK_WIDGET(gtk_builder_get_object(builder, "button4"));
  button5 = GTK_WIDGET(gtk_builder_get_object(builder, "button5"));
  button6 = GTK_WIDGET(gtk_builder_get_object(builder, "button6"));
  button7 = GTK_WIDGET(gtk_builder_get_object(builder, "button7"));
  button8 = GTK_WIDGET(gtk_builder_get_object(builder, "button8"));
  button9 = GTK_WIDGET(gtk_builder_get_object(builder, "button9"));

	// Essential for a GTK based program
	gtk_builder_connect_signals(builder, NULL);
	g_object_unref(builder);
  printBoard();

	gtk_widget_show_all(window); // Show our window
	gtk_main(); // Run our program

	return 0; // Necessary for a c main function
}

void gato_main(int x, int y){
  if (winnerExists == 0)  {

  playerMove(x, y);

  checkFreeSpaces();
  nuevocheckWinner();
  printBoard();

  } if (winnerExists == 2) {
  printf("IT'S A TIE!\n");
  gtk_label_set_text(state_label, "IT'S A TIE!");
  disableButton();
  }

  }

// Function to exit our app
void exit_app()
{

	printf("Exit app \n"); // Not neccesary
	gtk_main_quit(); // Command to quit a GTK program
}

// Function when our buttons are clicked

void button1_clicked()
{
	printf("Button1 clicked \n");

  if (board[0][0] == 0) {
  gato_main(0,0);
  gtk_label_set_text(lab1, "X");
  gtk_widget_set_sensitive(button1, FALSE);
  }
}

void button2_clicked()
{
	printf("Button2 clicked \n");

  if (board[0][1] == 0) {
  gato_main(0,1);
  gtk_label_set_text(lab2, "X");
  gtk_widget_set_sensitive(button2, FALSE);
}
}

void button3_clicked()
{
	printf("Button3 clicked \n");

  if (board[0][2] == 0) {
  gato_main(0,2);
  gtk_label_set_text(lab3, "X");
  gtk_widget_set_sensitive(button3, FALSE);
}
}

void button4_clicked()
{
	printf("Button4 clicked \n");

  if (board[1][0] == 0) {
  gato_main(1,0);
  gtk_label_set_text(lab4, "X");
  gtk_widget_set_sensitive(button4, FALSE);
}
}

void button5_clicked()
{
	printf("Button5 clicked \n");

  if (board[1][1] == 0) {
  gato_main(1,1);
  gtk_label_set_text(lab5, "X");
  gtk_widget_set_sensitive(button5, FALSE);
}
}

void button6_clicked()
{
	printf("Button6 clicked \n");

  if (board[1][2] == 0) {
  gtk_label_set_text(lab6, "X");
  gato_main(1,2);
  gtk_widget_set_sensitive(button6, FALSE);
}
}

void button7_clicked()
{
	printf("Button7 clicked \n");

  if (board[2][0] == 0) {
  gato_main(2,0);
  gtk_label_set_text(lab7, "X");
  gtk_widget_set_sensitive(button7, FALSE);
}
}

void button8_clicked()
{
	printf("Button8 clicked \n");

  if (board[2][1] == 0) {
  gato_main(2,1);
  gtk_label_set_text(lab8, "X");
  gtk_widget_set_sensitive(button8, FALSE);
}
}

void button9_clicked()
{
	printf("Button9 clicked \n");

  if (board[2][2] == 0) {
  gato_main(2,2);
  gtk_label_set_text(lab9, "X");
  gtk_widget_set_sensitive(button9, FALSE);
}
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
        computerMove();
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
        if (board[a][b] == board[0][0]) {
          gtk_label_set_text(lab1, "O");
          gtk_widget_set_sensitive(button1, FALSE);
        }
        if (board[a][b] == board[0][1]) {
          gtk_label_set_text(lab2, "O");
          gtk_widget_set_sensitive(button2, FALSE);
        }
        if (board[a][b] == board[0][2]) {
          gtk_label_set_text(lab3, "O");
          gtk_widget_set_sensitive(button3, FALSE);
        }
        if (board[a][b] == board[1][0]) {
          gtk_label_set_text(lab4, "O");
          gtk_widget_set_sensitive(button4, FALSE);
        }
        if (board[a][b] == board[1][1]) {
          gtk_label_set_text(lab5, "O");
          gtk_widget_set_sensitive(button5, FALSE);
        }
        if (board[a][b] == board[1][2]) {
          gtk_label_set_text(lab6, "O");
          gtk_widget_set_sensitive(button6, FALSE);
        }
        if (board[a][b] == board[2][0]) {
          gtk_label_set_text(lab7, "O");
          gtk_widget_set_sensitive(button7, FALSE);
        }
        if (board[a][b] == board[2][1]) {
          gtk_label_set_text(lab8, "O");
          gtk_widget_set_sensitive(button8, FALSE);
        }
        if (board[a][b] == board[2][2]) {
          gtk_label_set_text(lab9, "O");
          gtk_widget_set_sensitive(button9, FALSE);
        }

        }

void nuevocheckWinner() {
  // REVISANDO FILAS
  // FILA 1
  if (board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] != 0) {
    printf("hay ganador por fila\n");
    if (board[0][0] == 1) {
    printWinner(1);
  } else if (board[0][0] == 2) {
    printWinner(2);
  }
}
// FILA 2
if (board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] != 0) {
  printf("hay ganador por fila\n");
  if (board[1][0] == 1) {
  printWinner(1);
} else if (board[1][0] == 2) {
  printWinner(2);
}
}
// FILA 3
if (board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != 0) {
  printf("hay ganador por fila\n");
  if (board[2][0] == 1) {
  printWinner(1);
} else if (board[2][0] == 2) {
  printWinner(2);
}
}

// REVISANDO COLUMNAS
// REVISANDO COL 0
  if (board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[1][0] != 0) {
    printf("hay ganador por cols\n");
    if (board[1][0] == 1) {
    printWinner(1);
  } else if (board[1][0] == 2) {
    printWinner(2);
  }
}
// REVISANDO COL 1
if (board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != 0) {
  printf("hay ganador por cols\n");
  if (board[0][1] == 1) {
  printWinner(1);
} else if (board[0][1] == 2) {
  printWinner(2);
  }
}

//REVISANDO COL 2
if (board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != 0) {
  printf("hay ganador por cols\n");
  if (board[0][2] == 1) {
  printWinner(1);
} else if (board[0][2] == 2) {
  printWinner(2);
  }
}

//REVISANDO COL 3

if (board[0][3] == board[1][3] && board[0][3] == board[2][3] && board[0][3] != 0) {
  printf("hay ganador por cols\n");
  if (board[0][3] == 1) {
  printWinner(1);
  } else if (board[0][3] == 2) {
  printWinner(2);
  }
}
// REVISANDO DIAGONALES
// DIAGONAL 00 -> 22
 if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0) {
   printf("hay ganador por diagon\n");
   if (board[0][0] == 1) {
   printWinner(1);
   } else if (board[0][0] == 2) {
   printWinner(2);
   }
 }
 // DIAGONAL 20 -> 02
 if (board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] != 0) {
   printf("hay ganador por diagon\n");
   if (board[2][0] == 1) {
   printWinner(1);
 } else if (board[2][0] == 2) {
   printWinner(2);
   }
 }

}


void printWinner(int z)
{  winnerExists = 1;
   if(z == 1) // 1 ES LA X DEL JUGADOR
   {
      printf("YOU WIN!\n");
      gtk_label_set_text(state_label, "YOU WIN!");
      disableButton();
   }
   else if(z == 2) // 2 ES EL CIRCULO DEL JUGADOR
   {
      printf("YOU LOSE!\n");
      gtk_label_set_text(state_label, "YOU LOSE!");
   }
}


 void checkFreeSpaces() {
   int freeSpaces = 9;
   {
      for(int i = 0; i < 3; i++)
      {
         for(int j = 0; j < 3; j++)
         {
            if(board[i][j] != 0)
            {
               freeSpaces--;
            }
         }
      }
      if (freeSpaces == 1) {
        printf("freespaces: %d\n", freeSpaces);
        winnerExists = 2;
     }
   } printf("freespaces: %d\n", freeSpaces);
 }

void reset_button_clicked() {
  spaces = 9;
  winnerExists = 0;

  printf("RESET GRID\n");

  for(int i = 0; i < 3; i++)
  {
     for(int j = 0; j < 3; j++)
     { board[i][j] = 0;
       printf("reset board[%d][%d] = %d\n", i, j, board[i][j]);
     }
   }

  gtk_label_set_text(lab1, " ");
  gtk_label_set_text(lab2, " ");
  gtk_label_set_text(lab3, " ");
  gtk_label_set_text(lab4, " ");
  gtk_label_set_text(lab5, " ");
  gtk_label_set_text(lab6, " ");
  gtk_label_set_text(lab7, " ");
  gtk_label_set_text(lab8, " ");
  gtk_label_set_text(lab9, " ");
  gtk_label_set_text(state_label, " ");

  activateButton();
}

void disableButton()
{
  gtk_widget_set_sensitive(button1, FALSE);
  gtk_widget_set_sensitive(button2, FALSE);
  gtk_widget_set_sensitive(button3, FALSE);
  gtk_widget_set_sensitive(button4, FALSE);
  gtk_widget_set_sensitive(button5, FALSE);
  gtk_widget_set_sensitive(button6, FALSE);
  gtk_widget_set_sensitive(button7, FALSE);
  gtk_widget_set_sensitive(button8, FALSE);
  gtk_widget_set_sensitive(button9, FALSE);
}

void activateButton()
{
  gtk_widget_set_sensitive(button1, TRUE);
  gtk_widget_set_sensitive(button2, TRUE);
  gtk_widget_set_sensitive(button3, TRUE);
  gtk_widget_set_sensitive(button4, TRUE);
  gtk_widget_set_sensitive(button5, TRUE);
  gtk_widget_set_sensitive(button6, TRUE);
  gtk_widget_set_sensitive(button7, TRUE);
  gtk_widget_set_sensitive(button8, TRUE);
  gtk_widget_set_sensitive(button9, TRUE);
}
