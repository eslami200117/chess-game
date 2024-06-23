#include"ChessBoard.hpp"
using namespace std;

ChessBoard::ChessBoard()
    : m_board(Board()),
    m_turn(true)
{

}

void ChessBoard::nextTurn(){
    m_turn = ~m_turn;
}

string ChessBoard::getTurn(){
    if(m_turn) return "While";
    else return "Black";
}