#include"ChessPiece.hpp"
#include"ChessBoard.hpp"
#include<iostream>

using namespace std;

const string GAME_FILE_ADDRESS = "resource/board.txt";

int main(){
    string command;
    ChessBoard chessBoard;
    chessBoard.loadGame(GAME_FILE_ADDRESS);
    chessBoard.printBoard();
    while(!chessBoard.isDone()){
        cout<<"Player " << chessBoard.getTurn() << " move: ";
        cin>>command;
        chessBoard.executeCommand(command);
        chessBoard.nextTurn();
        chessBoard.printBoard();
    }
    chessBoard.saveGame(GAME_FILE_ADDRESS);

    return 0;
}
