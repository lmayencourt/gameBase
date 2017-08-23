#ifndef LEVEL_H
#define LEVEL_H

#include "idrawable.h"
#include <vector>
#include "tile.hpp"

class Level
{
public:
    Level(int row, int column) {
        _row = row;
        _column = column;
//        for (int i=0; i<row; i++) {
//            std::vector<Tile*> row;
//            for (int y=0; y<column; y++) {
//                row.push_back();
//            }
//        }
        _level = new Tile*[row][column];
    }

    void draw(IDisplay* display) {
        for (int i=0; i<_row; i++) {
            for (int y=0; y<_column; y++) {
                _level[_row][_column]->draw(display);
            }
        }
    }

private:
    int _row;
    int _column;

    Tile _level[10][10];
//    std::vector< std::vector<Tile*> > _level;
};

#endif // LEVEL_H
