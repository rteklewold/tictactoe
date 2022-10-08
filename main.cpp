#include <iostream>
#include <array>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;

const int rows=3;
const int cols=3;

void runGame();
void initializeGame(string board[rows][cols]);
void printCurrentBoard(string board[rows][cols]);
void getuserInput(bool &xTurn, string board[rows][cols]);
bool cellAlreadyOccupied(int rInput, int cInput, string board[rows][cols]);
string getWinner(string board[rows][cols]);
bool isBoardFull(string board[rows][cols]);
int main(){
    runGame();
    return 0;
}

void runGame(){
    string gameBoard[rows][cols];
    bool xTurn = true;
    initializeGame(gameBoard);
    printCurrentBoard(gameBoard);
    while(getWinner(gameBoard)==" "){
        getuserInput(xTurn, gameBoard);
    }
}
void initializeGame(string board[rows][cols]){
    for(int i=0;i<=rows-1;i++){
        for(int j=0;j<=cols-1;j++){
            board[i][j]=" ";
        }
    }
}
void printCurrentBoard(string board[rows][cols]){
    for(int i=0;i<=rows-1;i++){
        for(int j=0;j<=cols-1;j++){
             cout << board[i][j] << " ";
             if(j!=2){
                 cout << "|" << " ";
             }
        }
        cout <<endl;
        if(i!=2){
            cout << "-" << " " << "-" << " " << "-" << " " << "-" << " " << "-" <<endl;
        }
    }
}
void getuserInput(bool &xTurn, string board[rows][cols]){
    if(xTurn){
        cout << "It is X's turn " <<endl;
        cout << "Please enter the row then the column from 0, 1, 2 , separated by a space";
        cout << endl;
    }
    else{
        cout << "It is O's turn " <<endl;
        cout << "Please enter the row then the column from 0, 1, 2 , separated by a space";
        cout << endl;
    }
    vector<char> myInputs;
    char input='0';
    while(input!='\n'){
        cin.get(input);
        myInputs.push_back(input);

    }
    int row = myInputs[0]-48;
    int col = myInputs[2]-48;
    if(xTurn){
        if(row<0 || row >= 3){
            cout << "Please enter a valid row value " <<endl;
            getuserInput(xTurn, board);
        }
        else if(col<0 || col>= 3){
            cout << "Please enter a valid column value " <<endl;
            getuserInput(xTurn, board);
        }
        else if(cellAlreadyOccupied(row, col, board)){
            cout << "You have chosen an already occupied cell, please choose another cell " <<endl;
            getuserInput(xTurn, board);
        }
        else{
             board[row][col] = "X";
             if(getWinner(board)=="X"){
                 cout << " Game is over, X has won " <<endl;
                 printCurrentBoard(board);
             }
             else if(getWinner(board)=="None"){
                 cout << " It is a tie " <<endl;
                 printCurrentBoard(board);
             }
             else {
                 xTurn = false;
                 printCurrentBoard(board);
                 getuserInput(xTurn,board);
             }

        }
    }
    else{
        if(row<0 || row >= 3){
            cout << "Please enter a valid row value " <<endl;
            getuserInput(xTurn, board);
        }
        else if(col<0 || col>= 3){
            cout << "Please enter a valid column value " <<endl;
            getuserInput(xTurn, board);
        }
        else if(cellAlreadyOccupied(row, col, board)){
            cout << "You have chosen an already occupied cell, please choose another cell " <<endl;
            getuserInput(xTurn, board);
        }
        else{
             board[row][col] = "O";
             if(getWinner(board)=="O"){
                 cout << " Game is over, O has won " <<endl;
                 printCurrentBoard(board);
             }
             else if(getWinner(board)=="None"){
                 cout << " It is a tie " <<endl;
                 printCurrentBoard(board);
             }
             else{
                 xTurn = true;
                 printCurrentBoard(board);
             }
        }
    }
}
bool cellAlreadyOccupied(int rInput, int cInput, string board[rows][cols]){
    if(board[rInput][cInput]=="X" || board[rInput][cInput]=="O"){
        return true;
    }
    return false;
}
string getWinner(string board[rows][cols]){
    string winner= " ";
    if((board[0][0] == "X" && board[0][1] == "X"  && board[0][2] == "X" ) || (board[1][0] == "X" && board[1][1] == "X"  && board[1][2]== "X")
            ||(board[2][0] == "X" && board[2][1] == "X"  && board[2][2] == "X" ) ){
        winner = "X"; // horizontally
    }
    else if((board[0][0] == "X" && board[1][0] == "X"  && board[2][0] == "X" ) || (board[0][1] == "X" && board[1][1] == "X"  && board[2][1] == "X" )
            || (board[0][2] == "X" && board[1][2] == "X"  && board[2][2] == "X" )){
        winner = "X"; // vertically
    }
    else if((board[0][0] == "X" && board[1][1] == "X"  && board[2][2] == "X" ) || (board[0][2] == "X" && board[1][1] == "X"  && board[2][0] == "X" )){
        winner = "X"; //diagonally
    }
    else if((board[0][0] == "O" && board[0][1] == "O"  && board[0][2] == "O" ) || (board[1][0] == "O" && board[1][1] == "O"  && board[1][2]== "O")
            ||(board[2][0] == "O" && board[2][1] == "O"  && board[2][2] == "O" ) ){
        winner = "O"; // horizontally
    }
    else if((board[0][0] == "O" && board[1][0] == "O"  && board[2][0] == "O" ) || (board[0][1] == "O" && board[1][1] == "O"  && board[2][1] == "O" )
            || (board[0][2] == "O" && board[1][2] == "O"  && board[2][2] == "O" )){
        winner = "O"; // vertically
    }
    else if((board[0][0] == "O" && board[1][1] == "O"  && board[2][2] == "O" ) || (board[0][2] == "O" && board[1][1] == "O"  && board[2][0] == "O" )){
        winner = "O"; //diagonally
    }
    else if(isBoardFull(board)){
        winner = "None" ;
    }

    return winner;
}
bool isBoardFull(string board[rows][cols]){
    bool result = true;
    for(int i=0;i<=rows-1;i++){
        for(int j=0;j<=cols-1;j++){
            if(board[i][j]==" "){
                result = false;
            }
        }
    }
    return result;
}
