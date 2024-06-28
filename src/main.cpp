#include"ChessPiece.hpp"
#include"ChessBoard.hpp"
#include<iostream>

using namespace std;

const string GAME_FILE_ADDRESS = "resource/board.txt";

int main(){
    ChessBoard chessBoard;
    chessBoard.loadGame(GAME_FILE_ADDRESS);
    chessBoard.printBoard();
    while(!chessBoard.isDone()){
        chessBoard.executeCommand();
        chessBoard.nextTurn();
        chessBoard.printBoard();
    }
    chessBoard.saveGame(GAME_FILE_ADDRESS);

    return 0;
}
