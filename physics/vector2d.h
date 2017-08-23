#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <string>
#include "math.h"

class Vector2D
{
public:
    Vector2D() {
        this->_x = 0;
        this->_y = 0;
    }

    Vector2D(float x, float y) {
        this->_x = x;
        this->_y = y;
    }

    ~Vector2D(){}

    double distanceTo(Vector2D v1, Vector2D v2) {
       return sqrt((v2._x - v1._x) * (v2._x - v1._x) + (v2._y - v1._y)*(v2._y - v1._y));
    }

    double norm() {
       return sqrt(_x*_x + _y*_y);
    }

    double angle() {
        return atan2(_y,_x);
    }

    void set(double norm, double angle) {
        _x = cos(angle) * norm;
        _y = sin(angle) * norm;
    }

    std::string toString() {
        std::string output = "x=";
        output += std::to_string(_x);
        output += " ; y=";
        output += std::to_string(_y);
       return output;
    }

    float _x;
    float _y;

};

#endif // VECTOR2D_H
