#include"ChessPiece.hpp"
#include"ChessBoard.hpp"
#include<iostream>

using namespace std;

int main(){
    ChessBoard chessBoard;
    chessBoard.loadGame("/resource/board.txt");
    chessBoard.show();
    while(!chessBoard.isDone()){
        cout<<"Player: " << chessBoard.getTurn() << " move: ";
        string command;
        cin>>command;
        chessBoard.executeCommand(command);
        chessBoard.nextTurn();
        chessBoard.show();
    }

    return 0;
}
