#include"ChessPiece.hpp"
#include"ChessBoard.hpp"
#include<iostream>

using namespace std;


int main(){
    ChessBoard chessBoard;
    chessBoard.loadGame();
    chessBoard.printBoard();
    while(!chessBoard.isDone()){
        if(chessBoard.executeCommand()) break;
        chessBoard.nextTurn();
        chessBoard.printBoard();
    }

    return 0;
}
