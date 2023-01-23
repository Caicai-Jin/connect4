#include <stdio.h>
#include <assert.h>
#include <stdbool.h>


// Connect 4 is a game played by 2 players on a 6 by 7 grid. 
//Players take turns placing a piece in a column and that piece then descends to the lowest unoccupied space in the column. 
//A player wins once four of their pieces form a straight line—either horizontally, vertically, or diagonally. 
//In this question you will provide an implementation of Connect 4 in C. The game board will be represented by a 6 by 7 multi-dimensional char array with 
//the first player being represented by 'X', 
//the second player represented by 'O', and any other character representing an open space.

bool make_move(char board[6][7], int column, char player);
bool check_win(char board[6][7], char player);

int main(){
    
    char player1='X';
    char player2='O';
    
    //e represents empty in all the boards
    char board1[6][7]={{'e','e','e','e','e','e','e'}, 
                       {'e','e','e','e','e','e','e'},
                       {'e','O','e','e','e','e','e'},
                       {'e','O','e','e','e','e','e'},
                       {'e','O','X','e','e','e','e'},
                       {'X','O','X','X','e','e','e'}};
    assert(check_win(board1, player2)==1);//player2 wins vertically

    char board2[6][7]={{'e','e','e','e','e','e','e'}, 
                       {'e','e','e','e','e','e','e'},
                       {'e','O','e','e','e','e','e'},
                       {'e','O','e','e','e','e','e'},
                       {'e','O','e','e','e','e','e'},
                       {'X','X','X','X','e','e','e'}};
    assert(check_win(board2, player1)==1);//player1 wins horizontally
   
   
    char board3[6][7]={{'e','e','e','e','e','e','e'}, 
                       {'e','e','e','e','e','e','e'},
                       {'e','e','e','O','e','e','e'},
                       {'e','e','O','X','e','e','e'},
                       {'e','O','X','X','e','e','e'},
                       {'O','X','X','X','O','O','e'}}; 
    assert(check_win(board3, player2)==1);//player2 wins diagonally (goes up)
    
    char board4[6][7]={{'e','e','e','e','e','e','e'}, 
                       {'e','e','e','e','e','e','e'},
                       {'O','e','e','e','e','e','e'},
                       {'X','O','e','e','e','e','e'},
                       {'X','X','O','e','e','e','e'},
                       {'X','X','O','O','e','e','e'}}; 
    assert(check_win(board4, player2)==1);//player2 wins diagonally (goes down)
    
    char board5[6][7]={{'e','e','e','e','e','e','e'}, 
                       {'e','e','e','e','e','e','e'},
                       {'e','e','e','e','e','e','e'},
                       {'e','e','e','e','e','e','e'},
                       {'e','e','e','e','e','e','e'},
                       {'e','e','e','e','e','e','e'}}; 
    assert(check_win(board5, player1)==0); //empty board, no one wins
    assert(check_win(board5, player2)==0);
    
    printf("All tests are passed!\n");

    
    char board[6][7];
    int column=0;
    int stop=0;
    char a;
    
    while(stop==0){
        printf("Please enter the column(from 0 to 6) as the first player\n"); //first player
        if(scanf("%d",&column)==0){  //enter a non int (char or float) as column: stop program
            scanf(" %c",&a);
            printf("Error: Invalid integer----quit\n");
            stop=1;
        }
        else if(column<0 || column>6){ //enter column not in the range: stop the program
            printf("Error: Invalid integer----quit\n");
            stop=1;
        }
        else if(column>=0 && column<7){ // 0<=column<7
            while(make_move(board,column, player1)==0){ //the column is full 
                printf("This column is full, enter a new column please\n");
                scanf("%d",&column);
            }
            make_move(board,column, player1);//store the move of the first user
            for(int i=5;i>=0;i--){
                for(int j=0;j<7;j++){
                    printf(" %c\n",board[i][j]); //print the board
                }
            }
            if(check_win(board,player1)==1){ //if the first user wins
                stop=1;                      //stop here
            }
            stop=0;
        }
        if(stop==0){ //if the input for the first user is valid and first user didn't win
            printf("Please enter the column(from 0 to 6) as the second player\n");
            if((scanf("%d",&column)==0)){
                scanf(" %c",&a);
                printf("Error: Invalid integer----quit\n");
                stop=1;
            }
            else if(column<0 || column>6){
                printf("Error: Invalid integer----quit\n");
                stop=1;
            }
            else if(column>=0 && column<7){
                while(make_move(board,column, player2)==0){
                    printf("This column is full, enter a new column please\n");
                    scanf("%d",&column);
                }
                make_move(board,column, player2);
                for(int i=5;i>=0;i--){
                    for(int j=0;j<7;j++){
                    printf(" %c\n",board[i][j]);
                    }
                }
                if(check_win(board,player2)==1){
                    stop=1;
                }
                stop=0;
        }
    }


  }

}
    


bool make_move(char board[6][7], int column, char player){
    
    for(int i=5;i>=0;i--){
            if((board[i][column]!='X') && (board[i][column]!='O')){
                if(player=='X'){
                    board[i][column]='X';
                }
                if(player=='O'){
                    board[i][column]='O';
                }
                return 1;
            }

    }
    return 0;
}


bool check_win(char board[6][7],char player){
    
    //vertically
    for(int i=0;i<3;i++){
        for(int j=0;j<7;j++){
            if(board[i][j]==player && board[i+1][j]== player && board[i+2][j]==player &&board[i+3][j]==player){
                return 1;
            }
        }
    }
    
    //horizontally
    for(int i=0;i<6;i++){
        for(int j=0;j<4;j++){
            if(board[i][j]==player && board[i][j+1]==player && board[i][j+2]==player && board[i][j+3]==player){
                return 1;
            }
        }
    }
    
    //diagonally goes up
    for(int i=5;i>2;i--){
        for(int j=0;j<2;j++){
            if(board[i][j]==player && board[i-1][j+1]==player && board[i-2][j+2]==player && board[i-3][j+3]==player){
                return 1;
            }
        }
    }
    
    //diagonally goes down
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(board[i][j]==player && board[i+1][j+1]==player && board[i+2][j+2]==player && board[i+3][j+3]==player){
                return 1;
            }
        }
    }
    
    return 0;

}



