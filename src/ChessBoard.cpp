#include"ChessBoard.hpp"
using namespace std;

ChessBoard::ChessBoard()
    : m_turn(true){
    for(int i = 0; i < 8; i++){
        vector<ChessPiece*> row(8);
        for(int j = 0; j < 8; j++){
            m_board.push_back(row);
        }
    }
}

ChessBoard::ChessBoard(enum Pieces[8][8]){
    
}

void ChessBoard::nextTurn(){
    m_turn = ~m_turn;
}

string ChessBoard::getTurn(){
    if(m_turn) return "While";
    else return "Black";
}