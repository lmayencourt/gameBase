#ifndef TILE_H
#define TILE_H

#include "idrawable.h"
#include "gameBase/physics/icollisionnable.h"
#include "gameBase/physics/rectangle.hpp"

class Tile : public IDrawable, public ICollisionnable
{
public:
    Tile(int x, int y, int size, bool border) {
        _p->_x = x;
        _p->_y = y;
        _size = size;
        _border = border;
    }

    bool isABorder() {
        return _border;
    }

    /**
     * Default implementation
     * see {@link IDrawable}
     */
    void draw(IDisplay* display) {
        if (_border)
            display->drawRect(_p->_x,_p->_y,_size,_size,COLOR_BLUE);
        else
            display->drawRect(_p->_x,_p->_y,_size,_size,COLOR_CYAN);
    }

    /**
     * Default implementation
     * see {@link ICollisionnable}
     */
    Rectangle* getBoundingBox() {
        return new Rectangle(_p->_x,_p->_y,_size,_size);
    }

    bool notifyCollision(int energy, Object* otherObject) {
        if(energy >= Constants::DESTRUCTION_ENERGY){
            _destroyed = true;
            return true;
        }
        else
            return false;
    }

    void removedFromSim() {}

private:
    int _size;
    bool _border;
};

#endif // TILE_H
