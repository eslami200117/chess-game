#pragma once

struct Coordinate {
    int x;
    int y;
    
    Coordinate  (int x=0, int y=0) 
        : x(x), y(y)
    {}

    Coordinate& operator=(const Coordinate& a){
        x=a.x;
        y=a.y;
        return *this;
    }

    Coordinate operator+(const Coordinate& a) const{
        return Coordinate(a.x+x, a.y+y);
    }

    bool operator==(const Coordinate& a) const {
        return x == a.x && y == a.y;
    }
};

