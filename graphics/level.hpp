#ifndef LEVEL_H
#define LEVEL_H

#include <vector>

#include "idrawable.h"
#include "tile.hpp"
#include "gameBase/physics/physicssimulator.hpp"

class Level : public IDrawable
{
public:
    Level(int row, int column) : Level(row, column, 500, 500) {
    }

    Level(int row, int column, int height, int width) {
        _row = row;
        _column = column;
        _height = height;
        _width = width;
        _level = new Tile*[row * column];
        for (int i=0; i<row; i++) {
            //std::vector<Tile*> row;
            for (int y=0; y<column; y++) {
                //row.push_back();
                int tileSize = height/row;
                if (y == 0 || y == column-1 || i == 0 || i == row-1)
                    _level[y*row+i] = new Tile(i*tileSize,y*tileSize,tileSize,true);
                else
                    _level[y*row+i] = new Tile(i*tileSize,y*tileSize,tileSize,false);
            }
        }
    }

    void addTilesToSim(PhysicsSimulator* physim) {
        for (int i=0; i<_row*_column; i++) {
            if (_level[i]->isABorder())
                physim->addColObjectToSim(_level[i]);
        }
    }

    void draw(IDisplay* display) {
        for (int i=0; i<_row*_column; i++) {
            _level[i]->draw(display);
        }
    }

private:
    int _row;
    int _column;
    int _height;
    int _width;

    Tile** _level;
//    std::vector< std::vector<Tile*> > _level;
};

#endif // LEVEL_H
