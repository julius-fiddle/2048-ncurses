#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "moves.c"

void loadColors(){
    start_color();       //sets colorpairs
    init_pair(7, 1,0);   //Farbschema
    init_pair(3, 2,0);
    init_pair(2, 3,0);
    init_pair(5, 4,0);
    init_pair(6, 5,0);
    init_pair(4, 6,0);
    init_pair(1, 7,0);
}


int pickColor (int num){
    switch(num){
        case 8192:return 7; break;    
        case 4096:return 7; break;
        case 2048:return 7; break;
        case 1024:return 6; break;
        case 512: return 5; break;
        case 256: return 4; break;
        case 128: return 3; break;
        case 64:  return 2; break;
        default:  return 1;
    } 
} 


void showGame (int arr[][SIZE], WINDOW * win){

    wclear(win);                                    //NEU
    box(win,0,0);                                   //NEU
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(arr[i][j]){
                wattron(win,COLOR_PAIR(pickColor(arr[i][j])));
                mvwprintw(win,i*2+1,j*5+2,"%d", arr[i][j]);
                wattroff(win,COLOR_PAIR(pickColor(arr[i][j])));
            }
        }
    }
    wrefresh(win);
    move(15,1);
}




int gameOver(int arr[][SIZE]){
    for(int i=0; i<SIZE; i++ ){
        for(int j=1; j<SIZE; j++ ){                              
            if(arr[j][i] == arr[j-1][i]) return 0; //Search for pairs in columns
            if(arr[i][j] == arr[i][j-1]) return 0; //Search for pairs in rows
        }
    }
    return 1;
}

void updateScore(WINDOW * win, int * score){
    if(*score == 0){
        wclear(win);
        box(win,0,0);
    }
    mvwprintw(win, 1, 1, "Score: %d", *score);
    wrefresh(win);
}





int main() {


    int game[SIZE][SIZE];   //Init game.
    int score;              //init score variable
    srand(time(0));         //Generate time seed for rand()

    newGame(game, &score); //Generate new game

    game[0][0] = 512; //Demo
    game[0][1] = 256;
    game[0][2] = 128;
    game[0][3] = 2048;
    game[1][1] = 1024;
    game[1][0] = 64;

    initscr(); cbreak(); noecho(); curs_set(0);  //Start ncurses with no cursor and text.
    loadColors(); //Load colors

    mvprintw(5,5*SIZE+8, "Controls: Q: Quit  R: Restart");
    mvprintw(6,5*SIZE+8, "W,A,S,D: Game Movement");


    WINDOW * win = newwin((2*SIZE+2), (5*SIZE+2), 0, 5); // Create window
    refresh(); //Register window in main window
    showGame(game, win);

    WINDOW * scoreboard = newwin(3, 20, 1, (5*SIZE+8));
    box(scoreboard, 0,0);
    updateScore(scoreboard, &score); //Load scoreboard
    refresh();


    
    int cont = 1;
    char input;
    while(cont){ //Game Loop

        input = getch();
        switch(input){
            case 'r': {
                newGame(game, &score);
                showGame(game, win);
                updateScore(scoreboard, &score);
                mvaddstr(2*SIZE+6,10, "            "); //Ghetto delete string.
                break;
            }
            case 'w': {
                moveUp(game, &score);
                showGame(game, win);
                updateScore(scoreboard, &score);
            } break;
            case 's': {
                moveDown(game, &score);
                showGame(game, win);
                updateScore(scoreboard, &score);
            } break;
            case 'a': {
                moveLeft(game, &score);
                showGame(game, win);
                updateScore(scoreboard, &score);
            } break;
            case 'd': {
                moveRight(game, &score);
                showGame(game, win);
                updateScore(scoreboard, &score);
            } break;
            case 'q': {         //quit
                endwin();
                cont = 0;
            } break;
        }
        if(!freeField(game)&&gameOver(game)) {            //Lazy evaluation according to C documentation
            
            mvaddstr(2*SIZE+6,10, "GAME OVER!");
            //beep();                                     //?flash beep
            //flash();
            //getch();
            
        }
    }
    return 0;
}
