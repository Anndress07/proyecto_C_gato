// My Application
//


// Libraries
#include <gtk/gtk.h> // GTK Library
#include <stdio.h> // C IO Library (Not needed)

#include <ctype.h>
#include <time.h>

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

void printBoard();
void playerMove();
void computerMove();
void nuevocheckWinner();
void printWinner(int);
void checkFreeSpaces();

char board[3][3] = {{0,0,0},
                    {0,0,0},
                    {0,0,0}};
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
  printBoard();

	gtk_widget_show_all(window); // Show our window
	gtk_main(); // Run our program

	return 0; // Necessary for a c main function
}

void gato_main(int x, int y){
  if (winnerExists == 0)  {

  playerMove(x, y);
  computerMove();
  //spaces = checkFreeSpaces();
  //printf("\nespacios: %d\n", spaces);
  checkFreeSpaces();
  nuevocheckWinner();
  printBoard();

} if (winnerExists == 2) {
  printf("IT'S A TIE!\n");
}

}
  //printWinner(winner);


// Function to exit our app
void exit_app()
{
	printf("Exit app \n"); // Not neccesary
	gtk_main_quit(); // Command to quit a GTK program
}

// Function when our button is pressed
void button00_clicked()
{
	printf("Button00 clicked \n");
	gtk_label_set_text(label00, "pressed");
  gato_main(0,0);
}

void button01_clicked()
{
	printf("Button01 clicked \n");
	gtk_label_set_text(label01, "pressed");
  gato_main(0,1);
}

void button02_clicked()
{
	printf("Button02 clicked \n");
	gtk_label_set_text(label02, "pressed");
  gato_main(0,2);
}

void button10_clicked()
{
	printf("Button10 clicked \n");
	gtk_label_set_text(label10, "pressed");
  gato_main(1,0);
}

void button11_clicked()
{
	printf("Button11 clicked \n");
	gtk_label_set_text(label11, "pressed");
  gato_main(1,1);
}

void button12_clicked()
{
	printf("Button clicked \n");
	gtk_label_set_text(label12, "pressed");
  gato_main(1,2);
}

void button20_clicked()
{
	printf("Button20 clicked \n");
	gtk_label_set_text(label20, "pressed");
  gato_main(2,0);
}

void button21_clicked()
{
	printf("Button21 clicked \n");
	gtk_label_set_text(label21, "pressed");
  gato_main(2,1);
}

void button22_clicked()
{
	printf("Button22 clicked \n");
	gtk_label_set_text(label22, "pressed");
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

// char checkWinner() {
//    //check rows
//    for(int i = 0; i < 3; i++)
//    {
//         printf("checkwinner rows :board[%d][%d] = %d\n", i, 0, board[i][0]);
//         printf("checkwinner rows :board[%d][%d] = %d\n", i, 1, board[i][1]);
//         printf("checkwinner rows :board[%d][%d] = %d\n", i, 2, board[i][2]);
//         printf("-------%d ciclo------", i);
//       if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
//       {
//
//          return board[i][0];
//       }
//    }
//    //check columns
//    for(int i = 0; i < 3; i++)
//    {
//       if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
//       {
//
//          return board[0][i];
//       }
//    }
//    //check diagonals
//    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
//    {
//
//       return board[0][0];
//    }
//    if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
//    {
//
//       return board[0][2];
//    }
//
//    return ' ';
// }

void printWinner(int z)
{  winnerExists = 1;
   if(z == 1) // 1 ES LA X DEL JUGADOR
   {
      printf("YOU WIN!\n");
   }
   else if(z == 2) // 2 ES EL CIRCULO DEL JUGADOR
   {
      printf("YOU LOSE!\n");
   }
   //else if (checkFreeSpaces() == 1) {
      //printf("IT'S A TIE!");
   }


 void checkFreeSpaces() {
   int freeSpaces = 9;
   { //printf("in checkFreeSpaces");


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
