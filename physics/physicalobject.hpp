#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H

#include "math.h"

#include "gameBase/common/constants.h"
#include "gameBase/common/object.hpp"

#include "rectangle.hpp"
#include "vector2d.h"
#include "icollisionnable.h"
#include "isimulatable.h"

class PhysicalObject : public ISimulatable, public ICollisionnable
{

public:
    Vector2D* _s;
    Vector2D* _a;
    float _mass;
    bool _affectedByGravity;

    Rectangle* _boundingBox;

    /**
     * Constructor for an object with a mass
     * @param mass of the object
     */
    PhysicalObject(float mass) {
        this->_mass = mass;

        _boundingBox= new Rectangle();
    }

    /**
     * Default constructor
     */
    PhysicalObject() {
        this->_s = new Vector2D(0, 0);
        this->_a = new Vector2D(0, 0);
        this->_mass = 10;
        this->_affectedByGravity = true;

        _boundingBox= new Rectangle();
    }

    ~PhysicalObject() {
        delete _boundingBox;
    }

    /***********************************
     * Getters and setters
     ***********************************/
    Vector2D* getPosition(){
        return _p;
    }

    void setPosition(Vector2D* p){
        this->_p = p;
    }

    void setAcceleration(Vector2D* a) {
        this->_a = a;
    }

    Vector2D* getAcceleration(){
        return _a;
    }

    void setSpeed(Vector2D* s){
        this->_s = s;
    }

    void setMass(float m){
        this->_mass = m;
    }

    Vector2D* getSpeed(){
        return _s;
    }

    float getMass() {
        return _mass;
    }

    bool isAffectedByGravity(){
        return _affectedByGravity;
    }

    /*
     * (non-Javadoc)
     * @see java.lang.Object#toString()
     */
    std::string toString() {
        std::string result;
//        result = "Position : \t" + p + "\n";
//        result += "Speed :\t\t" + s + "\n";
//        result += "Acceleration :\t" + a + "\n";
//        std::sprintf(result,"Position : \t %s \n  Speed : \t %s \n Accelereation : \t %s \n",
//               p->toString(),s->toString(),a->toString());
        return result;
    }

    /**
     * From simulatable
     */
    void step(){

    }

    /**
     * Default implementation
     * see {@link Collisionnable}
     */
    Rectangle* getBoundingBox() {

        _boundingBox->setX(_p->_x);
        _boundingBox->setY(_p->_y);
        _boundingBox->setWidth(10);
        _boundingBox->setHeight(10);

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

//    bool notifyCollision(int energy, Ground* other) {
//        if(energy >= Constants::DESTRUCTION_ENERGY){
//            destroyed = true;
//            return true;
//        }
//        else
//            return false;
//    }

    void removedFromSim() {}
};

#endif // PHYSICALOBJECT_H
