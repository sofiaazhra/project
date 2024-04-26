#include <ncurses/ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
int currentPlayer = 1;

void drawBoard() {
    system("clear"); 
    cout << "Silverogue\n";
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool isMoveValid(int move) {
    return (move >= 1 && move <= 9 && board[(move - 1) / 3][(move - 1) % 3] == ' ');
}

bool checkWin() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true; // Check baris
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true; // Check kolom
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true; // Check diagonal 1
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true; // Check diagonal 2
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

void botMove() {
    srand(time(0));
    int move;
    do {
        move = rand() % 9 + 1;
    } while (!isMoveValid(move));

    char playerSymbol = (currentPlayer == 1) ? 'X' : 'O';
    board[(move - 1) / 3][(move - 1) % 3] = playerSymbol;
}

void startGame() {
    int move;
    bool gameRunning = true;

    while (gameRunning) {
        drawBoard();

        if (currentPlayer == 1) {
            cout << "Knight, enter your move (1-9): ";
            cin >> move;

            if (isMoveValid(move)) {
                char playerSymbol = (currentPlayer == 1) ? 'X' : 'O';
                board[(move - 1) / 3][(move - 1) % 3] = playerSymbol;

                if (checkWin()) {
                    drawBoard();
                    cout << "Knight wins!\n";
                    gameRunning = false;
                } else if (isBoardFull()) {
                    drawBoard();
                    cout << "It's a tie!\n";
                    gameRunning = false;
                } else {
                    switchPlayer();
                }
            } else {
                cout << "Invalid move. Please try again.\n";
            }
        } else {
            botMove();

            if (checkWin()) {
                drawBoard();
                cout << "Dragon wins!\n";
                gameRunning = false;
            } else if (isBoardFull()) {
                drawBoard();
                cout << "It's a tie!\n";
                gameRunning = false;
            } else {
                switchPlayer();
            }
        }
    }
}

void showAboutPage(WINDOW*menuwin) {
    int rows, cols;

    
    getmaxyx(stdscr, rows, cols); // Get the terminal size

    
    int yPos = rows / 2 - 6;
    int xPos = (cols - 48) / 2; //text centering
	
	clear();
	refresh();

    mvprintw(yPos, xPos,         "==============================================");
    mvprintw(yPos + 1, xPos,     "                   ABOUT US                  ");
    mvprintw(yPos + 2, xPos,     "==============================================");
	
	mvprintw(yPos + 4, xPos + 2, "		      Created by:             ");    
	mvprintw(yPos + 5, xPos + 2, "        Silverogue Development Team             ");
    mvprintw(yPos + 7, xPos + 2, "             Top contributors:                  ");
    mvprintw(yPos + 8, xPos + 2, "              #1 Hafizh (99%)              ");
    mvprintw(yPos + 9, xPos, ""														);
	mvprintw(yPos + 10, xPos,     "==============================================");


	refresh();	
	getch();
	wclear(menuwin);
	box(menuwin, 1, 1);
	wrefresh(menuwin);
	
}



using namespace std;

int main(int argc, char ** argv){
	
		string choices[3] = {"Start", "About", "Exit"};
	int choice;
	int highlight = 0;
		
	
	// NCURSES START 
	initscr();
	noecho();
	cbreak();
	
	// COLOR CODE
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);   
	init_pair(2, COLOR_YELLOW, COLOR_BLACK); 
	init_pair(3, COLOR_BLUE, COLOR_BLACK);   
	
	do{
	

	// SCREEN SIZE
	int yMax, xMax;
	getmaxyx (stdscr, yMax, xMax);
	
	//PRINTING GAME TITLE
    mvprintw(3, (xMax - 83)/ 2, "   xxxxx    x   xxxx    x     xxxx               x    x      xxxx    x       xxx    x    ");
	mvprintw(4, (xMax - 83)/ 2, "  xxxxxxxxxx   xxxxxxxxxx    xx xxxx    x       xxx        xxxxxxx  x     xxxxxxxxx     ");  
	mvprintw(5, (xMax - 83)/ 2, " x   xxxxxx   x    xxxxx     x   xxxx  x xx    xxxxx     xxxx   xxx      xx xxxxxx      ");
	mvprintw(6, (xMax - 83)/ 2, "xx     xx              x    xx    xxx x  xx      xxx      xxx      xxx   xx    xx        ");
	mvprintw(7, (xMax - 83)/ 2, "xx                    xx    xx    xx     xxx     xxx   xxxx     xxx   xx              ");
	mvprintw(8, (xMax - 83)/ 2, " xx     xxx          xxx    xx   xx       xxx    xxx  xx xx    xxx    xx   xxxxxxx    ");
	mvprintw(9, (xMax - 83)/ 2, " xxxxxxxxxxx         xxx    xx            xxx    xxx     xx   xxx    xx   xx    xxx   ");
	mvprintw(10, (xMax - 83)/ 2, "  xxxxx  xxxx        xxx    xx             xx    xx      xx xxx      xx   xxx   xxxx  ");
	mvprintw(11, (xMax - 83)/ 2, "   xxx    xxx        xxx    xx             xx    xx      xx  xxx     xx   xx     xxx  ");
	mvprintw(12, (xMax - 83)/ 2, " xx  xxx   xx        xxx   xx              xx   xx       xx   xxx     xx  x      xx   ");
	mvprintw(13, (xMax - 83)/ 2, "xx    xxx  xx        xxx   x                xx  x        xx    xx     xxx        xx   ");
	mvprintw(14, (xMax - 83)/ 2, "xx    xx   xx    x   xx   xxxxx     x       xx x         xx    xx      xxx       x    ");
	mvprintw(15, (xMax - 83)/ 2, " xx   x   xx    xx   xx   xxxxxx  xx         xxx         xxx   xxx  x  xxxxxx   xx    ");
	mvprintw(16, (xMax - 83)/ 2, "  xxxx   xx    xxx  xx   x   xxxxxx    x     xx          xx     xxxx    xxxxxxxxx     ");
	mvprintw(17, (xMax - 83)/ 2, "    xxxxxx      xxxx           xxx           x           x       xx       xxxxx       ");
	
	     
	refresh(); //SAME OUTPUT TIME
	
	// WINDOW INPUT
	WINDOW * menuwin = newwin(6, xMax-12, yMax-8, 5);
	box(menuwin, 0, 0);
	wrefresh(menuwin);
	
	// CHOICES 
	keypad(menuwin, true);
	

	while (1) {
    for (int i = 0; i < 3; i++) {
        if (i == highlight) {
            if (i == 1) {
                wattron(menuwin, COLOR_PAIR(2) | A_REVERSE); // HIGHLIGHT COLORING
            } else if (i == 2) {
                wattron(menuwin, COLOR_PAIR(3) | A_REVERSE);
            } else {
                wattron(menuwin, COLOR_PAIR(1) | A_REVERSE);
            }
        }
        mvwprintw(menuwin, i + 1, 1, choices[i].c_str());
        wattroff(menuwin, COLOR_PAIR(1) | COLOR_PAIR(2) | COLOR_PAIR(3) | A_REVERSE);
    }
    choice = wgetch(menuwin);

    switch (choice) { //KEY CONTROL
        case KEY_UP:
            highlight--;
            break;

        case KEY_DOWN:
            highlight++;
            break;
        case 10:
        if (highlight == 0) {  // "Start" option selected
                startGame();  // Call the function to start the game
            } else if (highlight == 1) {
                showAboutPage(menuwin);  // "About" option selected
                wclear(stdscr);
                box(menuwin, 0, 0);
                refresh();
            } else if (highlight == 2) {
                endwin();  // "Exit" option selected
                return 0;
            }
            break;
			
        default:
            break;
    }
	
    if (highlight < 0) {
        highlight = 2;  
    } else if (highlight > 2) {
        highlight = 0;  
    }

    if (choice == 10)
        break;
        
        wrefresh(menuwin);
}
	
}while(choice !=0);
	
	// PROGRAM WAIT TIME 
	getch();
	endwin();


	return 0;
}
