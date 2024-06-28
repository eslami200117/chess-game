#include"ChessPiece.hpp"
#include"ChessBoard.hpp"
#include<iostream>

using namespace std;

const string GAME_FILE_ADDRESS = "resource/defualt.txt";

int main(){
    ChessBoard chessBoard(GAME_FILE_ADDRESS);
    chessBoard.loadGame();
    chessBoard.printBoard();
    while(!chessBoard.isDone()){
        chessBoard.executeCommand();
        chessBoard.nextTurn();
        chessBoard.printBoard();
    }

    return 0;
}
