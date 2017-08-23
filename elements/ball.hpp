#ifndef BALL_H
#define BALL_H


#include "gameBase/graphics/idrawable.h"
#include "gameBase/physics/physicalobject.hpp"

class Ball : public PhysicalObject, public IDrawable
{
protected:
    int _radius;

public:
    Ball() {
        _radius = 50;
    }

    Ball(int radius) {
        _radius = radius;
    }

    Ball(int x, int y) {
        _p->_x = x;
        _p->_y = y;
        Ball();
    }

    Ball(int x, int y, int radius) {
        _p->_x = x;
        _p->_y = y;
        _radius = radius;
    }

    ~Ball(){}

    /**
     * set the radius of the ball
     *
     * @return void
     */
    void setRadius(int r) {
        _radius = r;
    }

    /**
     * get the radius of the ball
     *
     * @return void
     */
    int getRadius() {
        return _radius;
    }

    /**
     * Draw the element on the screen
     *
     * @return void
     */
    void draw(IDisplay* display) {
//#ifdef DEBUG
        std::string txt;
        txt = "ball " + _p->toString();
        display->drawText(_p->_x,_p->_y,txt,COLOR_BLUE);
        txt = " |-s " + _s->toString();
        display->drawText(_p->_x,_p->_y+15,txt,COLOR_BLUE);
//#endif
        display->drawCircle(_p->_x,_p->_y,_radius,COLOR_BLUE);
    }

    /**
     * Default implementation
     * see {@link Collisionnable}
     */
    Rectangle* getBoundingBox() {

        _boundingBox->setX(_p->_x);
        _boundingBox->setY(_p->_y);
        _boundingBox->setWidth(_radius);
        _boundingBox->setHeight(_radius);

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

#endif // BALL_H
