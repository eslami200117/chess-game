#include"Board.hpp"

Board::Board(){
    for(int i=0; i < EIGHT; i++) {
        m_boxes[1][i] = {false, false, {1, i}, _Pawn};
        m_boxes[6][i] = {false, true, {1, i}, _Pawn};
    }

    for(int i=0; i < EIGHT; i++) {
        for(int j=2; j<6; j++){
            m_boxes[j][i] = {false, false, {j, i}, _Empty};
        }
    }

}

bool Board::isEmpty(Coordinate c){
    return m_boxes[c.x][c.y].m_pieces == _Empty;
}
