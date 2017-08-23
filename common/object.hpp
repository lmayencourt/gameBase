#ifndef OBJECT_H
#define OBJECT_H

#include "gameBase/physics/vector2d.h"

class Object
{

public:
    bool _destroyed = false;

    Object() {
        this->_p = new Vector2D(0, 0);
    }

    ~Object() {
        delete _p;
    }

    Vector2D* _p;

};

#endif // OBJECT_H
