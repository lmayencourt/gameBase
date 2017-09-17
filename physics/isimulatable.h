#ifndef SIMULATABLE
#define SIMULATABLE

#include "gameBase/common/object.hpp"

/**
 * Interface for objects that can be simulated via the {@link PhysicsSimulator}.
 *
 * @version 1.0, April 2010
 * @author <a href='mailto:pandre.mudry&#64;hevs.ch'> Pierre-AndrÔøΩ Mudry</a>
 */
class ISimulatable : virtual public Object {

public:
    /**
     * Notify implementer that a simulation step has been performed
     */
    virtual void step()=0;

    //void removedFromSimulation();

};

#endif // SIMULATABLE

