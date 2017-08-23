#ifndef CONSTANTS
#define CONSTANTS

/**
 * Some useful physics constant that are used by the {@link PhysicsSimulator}
 * class.
 *
 * @version 1.0, April 2010
 * @author <a href='mailto:pandre.mudry&#64;hevs.ch'> Pierre-Andre Mudry</a>
 */
class Constants {

public:
    /**
     * Graphics related constants
     */
    static const int WIN_WIDTH = 320;
    static const int WIN_HEIGHT = 240;
    static const int RADIUS = 20;

    /**
     * Physics environment
     */
    static const float GRAVITY;
    static const float DELTA_TIME;
    static const float AIR_FRICTION;
    static const float DAMPING_FACTOR;
//    static const int GRAVITY = 10;
//    static const int DELTA_TIME = 1;
//    static const int AIR_FRICTION = 1;
//    static const int DAMPING_FACTOR = 1;

    /**
     * Game related constants
     */
    // Maximal impact energy triggering a object destruction
    static const int DESTRUCTION_ENERGY = 15000;
    static const int CLOUD_DENSITY = 5;
    static const bool DRAW_BOUNDINGBOXES = false;
    static const int LIFEPOINT = 40000;
};

//const float Constants::DELTA_TIME = 0.1f;
//const float Constants::GRAVITY = 9.8f;
//const float Constants::AIR_FRICTION = 1;
//const float Constants::DAMPING_FACTOR = 1;
#endif // CONSTANTS

