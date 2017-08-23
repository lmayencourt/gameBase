#ifndef PLATFORM_H
#define PLATFORM_H

#include "gameBase/graphics/idrawable.h"
#include "gameBase/physics/physicalobject.hpp"

class Platform : public PhysicalObject, public IDrawable
{
private:
    int _width;
    int _height;

public:
    Platform() {
        Platform(0,0,50,10);
    }

    Platform(int x, int y) {
        Platform(x,y,50,10);
    }

    Platform(int x, int y, int width, int height) {
        _p->_x = x;
        _p->_y = y;
        _width = width;
        _height = height;

        _mass = 1e8;
        _affectedByGravity = false;
    }

    void draw(IDisplay* display) {
//#ifdef DEBUG
        std::string txt;
        txt = "platform " + _p->toString();
        display->drawText(_p->_x,_p->_y,txt,COLOR_BLUE);
//#endif
        display->drawRect(_p->_x,_p->_y,_width,_height,COLOR_BLUE);
    }

    /**
     * Default implementation
     * see {@link Collisionnable}
     */
    Rectangle* getBoundingBox() {

        _boundingBox->setX(_p->_x);
        _boundingBox->setY(_p->_y);
        _boundingBox->setWidth(_width);
        _boundingBox->setHeight(_height);

        return _boundingBox;
    }

    bool notifyCollision(int energy, Object* otherObject) {
        if(energy >= Constants::DESTRUCTION_ENERGY){
            _destroyed = true;
            return true;
        }
        else
            return false;
    }
};

#endif // PLATFORM_H
