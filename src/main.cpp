#include"ChessPiece.hpp"
#include"ChessBoard.hpp"
#include<iostream>

using namespace std;

int main(){
    string command;
    ChessBoard chessBoard;
    chessBoard.loadGame("/resource/board.txt");
    chessBoard.printBoard();
    while(!chessBoard.isDone()){
        cout<<"Player: " << chessBoard.getTurn() << " move: ";
        cin>>command;
        chessBoard.executeCommand(command);
        chessBoard.nextTurn();
        chessBoard.printBoard();
    }

    return 0;
}
