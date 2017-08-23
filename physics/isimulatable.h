#ifndef SIMULATABLE
#define SIMULATABLE

/**
 * Interface for objects that can be simulated via the {@link PhysicsSimulator}.
 *
 * @version 1.0, April 2010
 * @author <a href='mailto:pandre.mudry&#64;hevs.ch'> Pierre-AndrÔøΩ Mudry</a>
 */
class ISimulatable {

public:
    /**
     * Notify implementer that a simulation step has been performed
     */
    virtual void step()=0;

    //void removedFromSimulation();

};

#endif // SIMULATABLE

