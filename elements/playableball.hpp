#ifndef PLAYABLEBALL_H
#define PLAYABLEBALL_H


#include "gameBase/elements/ball.hpp"
#include "gameBase/control/ijoystickobserver.h"

class PlayableBall : public Ball, public IJoystickObserver
{

public:
    PlayableBall() {
        _radius = 50;
    }

    PlayableBall(int radius) {
        _radius = radius;
    }

    PlayableBall(int x, int y) {
        _p->_x = x;
        _p->_y = y;
        PlayableBall();
    }

    PlayableBall(int x, int y, int radius) {
        _p->_x = x;
        _p->_y = y;
        _radius = radius;
    }

    ~PlayableBall(){}

    void onPositionChange( IJoystick::Position position ) {
        switch (position) {
        case IJoystick::Center :
            //_s->_x = 0;
            break;
        case IJoystick::Left :
            _s->_x += -20;
            break;
        case IJoystick::Right :
            _s->_x += 20;
            break;
        case IJoystick::Up :
            _s->_y += -20;
            _p->_y += -5;
            break;
        }
    }
};

#endif // PLAYABLEBALL_H
