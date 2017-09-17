#ifndef COLLISIONNABLE_H
#define COLLISIONNABLE_H

#include "gameBase/common/object.hpp"
#include "rectangle.hpp"

class ICollisionnable : virtual public Object
{
public:
    /**
     * Callback used to notify the object that he was removed form the simulation
     */
    virtual void removedFromSim()=0;

    /**
     * When the {@link PhysicalObject} that implements this
     * interfaces collides another object, this callback method
     * is called
     *
     * @param energy
     *            Energy of the collision
     * @return true if the object has to be destroyed
     */
    virtual bool notifyCollision(int energy, Object* other)=0;

    /**
    * When the {@link PhysicalObject} that implements this
    * interfaces collides another object, this callback method
    * is called
    *
    * @param energy
    *            Energy of the collision
    * @return true if the object has to be destroyed
    */
   //virtual bool notifyCollision(int energy, Ground* other)=0;

    /**
     * Gives the bounding box of the object which is used for detecting
     * collisions.
     *
     * @return the bounding box
     */
    virtual Rectangle* getBoundingBox()=0;
};

#endif // COLLISIONNABLE_H
