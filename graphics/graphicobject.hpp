#ifndef GRAPHICALOBJECT_H
#define GRAPHICALOBJECT_H

#include "math.h"

#include "gameBase/common/constants.h"
#include "gameBase/common/object.hpp"

#include "idrawable.h"

class GraphicalObject : public Object, public IDrawable
{

public:

    /**
     * Default constructor
     */
    GraphicalObject(){
    }

    ~GraphicalObject(){}

    /***********************************
     * Getters and setters
     ***********************************/
    Vector2D* getPosition(){
        return _p;
    }

    void setPosition(Vector2D* p){
        this->_p = p;
    }

    std::string toString()
    {
        std::string result;
//        result = "Position : \t" + p + "\n";
//        result += "Speed :\t\t" + s + "\n";
//        result += "Acceleration :\t" + a + "\n";
//        std::sprintf(result,"Position : \t %s \n  Speed : \t %s \n Accelereation : \t %s \n",
//               p->toString(),s->toString(),a->toString());
        return result;
    }

    /**
     * From drawable
     */
    void draw(IDisplay* display){
        display->drawCircle(_p->_x,_p->_y,10,10);
    }
};

#endif // GRAPHICALOBJECT_H
