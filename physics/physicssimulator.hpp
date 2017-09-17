#ifndef PHYSICSSIMULATOR_H
#define PHYSICSSIMULATOR_H

#include <list>

#include "gameBase/common/constants.h"
#include "gameBase/common/object.hpp"
#include "gameBase/physics/physicalobject.hpp"
#include "gameBase/physics/rectangle.hpp"

/**
 * A simple physics simulator for the inf1 project.
 *
 * @version 1.0, January 2010
 * @author <a href='mailto:pandre.mudry&#64;hevs.ch'> Pierre-Andr√© Mudry</a>
 */
class PhysicsSimulator {

public :
    PhysicsSimulator() {
        this->_width = Constants::WIN_WIDTH;
        this->_height = Constants::WIN_HEIGHT;
    }

    /**
     * @param width
     *            The width of the space for the physics simulation
     * @param height
     *            The height of the space for the physics simulation
     */
    PhysicsSimulator(double width, double height) {
        this->_width = width;
        this->_height = height;
    }

//    PhysicsSimulator(double width, double height, Ground* background){
//        PhysicsSimulator(width, height);
//        this->background = background;
//    }

    void removeAllSimObjectsFromSim() {
        _sim_objects.clear();
    }

    /**
     * Adds a new object to the simulation framework
     *
     * @param o  The object to be added
     */
    void addSimObjectToSim(PhysicalObject* o) {
        _sim_objects.push_back(o);
    }

    /**
     * remove an object from simulation
     */
    void removeSimObjectFromSim(PhysicalObject* o) {
        o->removedFromSim();
        _sim_objects.remove(o);
    }

    void removeAllColObjectsFromSim() {
        _col_objects.clear();
    }

    /**
     * Adds a new object to the simulation framework
     *
     * @param o  The object to be added
     */
    void addColObjectToSim(ICollisionnable* o) {
        _col_objects.push_back(o);
    }

    /**
     * remove an object from simulation
     */
    void removeColObjectFromSim(ICollisionnable* o) {
        o->removedFromSim();
        _col_objects.remove(o);
    }

    /**
     * Simulates all the objects that ought to be simulated
     *
     * @return
     */
    void simulate_step() {
        if (_sim_objects.size() == 0)
            return;

        for (std::list<PhysicalObject*>::iterator it = _sim_objects.begin(); it != _sim_objects.end(); it++) {
//            Simulatable* s = *it;

//            s->step();

//            if (s instanceof PhysicalObject) {
//                PhysicalObject p = (PhysicalObject) s;

            PhysicalObject* p = (PhysicalObject*)(*it);

                if (p->isAffectedByGravity()) {
                    // calcul de l'acceleration de l'objet et mise a jour
                    p->_a->_x = (Constants::AIR_FRICTION * -1 * p->_s->_x ) / p->_mass;
    //                p->a->y = Constants::GRAVITY - Constants::AIR_FRICTION * p->s->y / p->mass ;
                    p->_a->_y = Constants::GRAVITY / p->_mass;
                }
                // calcul de la vitesse et mise a jour
                p->_s->_x = p->_s->_x + p->_a->_x * Constants::DELTA_TIME;
                p->_s->_y = p->_s->_y + p->_a->_y * Constants::DELTA_TIME;

                // calcul de la position et mise a jour
                p->_p->_x = p->_p->_x + p->_s->_x * Constants::DELTA_TIME;
                p->_p->_y = p->_p->_y + p->_s->_y * Constants::DELTA_TIME;

                /**
                 * Handle collisions
                 */

                handleCollisions(p);

//                // collide bottom
//                Rectangle* box = p->getBoundingBox();
//                Vector2D* vec = new Vector2D(box->left() + box->width()/2 ,box->bottom());
//                double collidebottom = background->collidesGround(vec);

//                if(collidebottom != -1){
//                    if(p->s->y > 1)
//                        p->s->y = -1*p->s->y*Constants::DAMPING_FACTOR;
//                    else
//                       p->p->y = WIN_HEIGHT - box->height()/2;

//                    if(p->notifyCollision((int) (0.5 * p->getMass() * p->getSpeed()->norm() * p->getSpeed()->norm()), background))
//                        removeObjectFromSim(p);
//                }
//                // collide right and left
//                Vector2D* vecRight = new Vector2D(box->right() ,box->bottom());
//                Vector2D* vecLeft = new Vector2D(box->left() ,box->bottom());
//                double collideRight = background->collidesGround(vecRight);
//                double collideLeft = background->collidesGround(vecLeft);

//                if(collideLeft == M_PI_2)
//                {
//                	p->s->x = -1*p->s->x*Constants::DAMPING_FACTOR;

//					if(p->notifyCollision((int) (0.5 * p->getMass() * p->getSpeed()->norm() * p->getSpeed()->norm()), background))
//						removeObjectFromSim(p);
//                }

//                if(collideRight == M_PI_2)
//                {
//                	p->s->x = -1*p->s->x*Constants::DAMPING_FACTOR;

//					if(p->notifyCollision((int) (0.5 * p->getMass() * p->getSpeed()->norm() * p->getSpeed()->norm()), background))
//						removeObjectFromSim(p);
//                }

//                delete vec;
//                delete vecRight;
//                delete vecLeft;
            }
     }

private:
    /**
     * This represents the borders of the simulated area (for collisions)
     */
    double _width;
    double _height;
    //Ground* background;

    /**
     * The objects that require physics simulation (objects that move)
     */
    std::list<PhysicalObject*> _sim_objects;
    std::list<ICollisionnable*> _col_objects;

    void handleCollisions(PhysicalObject* p)
    {

        // For each object, find potential obstacles among other objects
        for (std::list<PhysicalObject*>::iterator it = _sim_objects.begin(); it != _sim_objects.end(); it++) {
            PhysicalObject* q = (PhysicalObject*)(*it);
            if (p != q && collides(p,q)){
                // Remove interpenetration
                p->getPosition()->_x -= Constants::DELTA_TIME * p->getSpeed()->_x;
                p->getPosition()->_y -= Constants::DELTA_TIME * p->getSpeed()->_y;

                // 2d elastic collision
                collision2D(p, q);

                // Impact total kinetic energy
                int energy;
                energy = (int) (0.5 * p->getMass() * p->getSpeed()->norm() * p->getSpeed()->norm());
                energy += (int) (0.5 * q->getMass()* q->getSpeed()->norm() * q->getSpeed()->norm());

                // Notify the objects of the impact and destroy them if needed
                if (p->notifyCollision(energy,q)) {
                    //removeObjectFromSim(p);
                }

                if (q->notifyCollision(energy,p)) {
                    //removeObjectFromSim(q);
                }
            }
        }

        // For each object, find potential obstacles among level
        for (std::list<ICollisionnable*>::iterator it = _col_objects.begin(); it != _col_objects.end(); it++) {
            PhysicalObject* q = (PhysicalObject*)(*it);
            if (p != q && collides(p,q)){
                // Remove interpenetration
                p->getPosition()->_x -= Constants::DELTA_TIME * p->getSpeed()->_x;
                p->getPosition()->_y -= Constants::DELTA_TIME * p->getSpeed()->_y;

                // 2d elastic collision
                // Damping factor
                p->_s->_x = -1 * p->_s->_x* Constants::DAMPING_FACTOR;
                p->_s->_y = -1 * p->_s->_y* Constants::DAMPING_FACTOR;

                // Impact total kinetic energy
                int energy;
                energy = (int) (0.5 * p->getMass() * p->getSpeed()->norm() * p->getSpeed()->norm());

                // Notify the objects of the impact and destroy them if needed
                if (p->notifyCollision(energy,q)) {
                    //removeObjectFromSim(p);
                }

                if (q->notifyCollision(energy,p)) {
                    //removeObjectFromSim(q);
                }
            }
        }
    }

    void collision2D(PhysicalObject* p, PhysicalObject* q) {
        float m1 = p->getMass();
        float m2 = q->getMass();
        float v1x = p->getSpeed()->_x;
        float v1y = p->getSpeed()->_y;
        float v2x = q->getSpeed()->_x;
        float v2y = q->getSpeed()->_y;

        p->getSpeed()->_x = (v1x * (m1 - m2) / (m1 + m2))
                + (2 * m2 * v2x / (m1 + m2));
        p->getSpeed()->_y = (v1y * (m1 - m2) / (m1 + m2))
                + (2 * m2 * v2y / (m1 + m2));

        q->getSpeed()->_x = (2 * m1 * v1x / (m1 + m2))
                + (v2x * (m2 - m1) / (m1 + m2));
        q->getSpeed()->_y = (2 * m1 * v1y / (m1 + m2))
                + (v2y * (m2 - m1) / (m1 + m2));

//                float phi1, phi2, r1, r2;
//                float v1 = p->getSpeed()->norm();
//                float psi1 = p->getSpeed()->angle();
//                float v2 = q->getSpeed()->norm();
//                float psi2 = q->getSpeed()->angle();

//                phi1 = atan((m1 - m2)/(m1 + m2) * tan(psi1)
//                             + (2 * m2 * v2 * sin(psi2))/((m1 + m2) * v1 * cos(psi1)));
//                r1 = sqrt(pow(2, (m1 - m2)/(m1 + m2) * v1 * sin(psi1) + 2*m2/(m1 + m2) * v2 * sin(psi2))
//                           + pow(2, v1 * cos(psi1)));

//                phi2 = atan((m2 - m1)/(m2 + m1) * tan(psi2)
//                             + (2 * m1* v1 * sin(psi1))/((m2 + m1) * v2 * cos(psi2)));
//                r2 = sqrt(pow(2, (m2 - m1)/(m2 + m1) * v2 * sin(psi2) + 2*m1/(m2 + m1) * v1 * sin(psi1))
//                           + pow(2, v2 * cos(psi2)));

//                p->getSpeed()->set(r1,phi1);
//                q->getSpeed()->set(r2,phi2);

        // Damping factor
        p->_s->_x = p->_s->_x* Constants::DAMPING_FACTOR;
        p->_s->_y = p->_s->_y* Constants::DAMPING_FACTOR;

        q->_s->_x = q->_s->_x* Constants::DAMPING_FACTOR;
        q->_s->_y = q->_s->_y* Constants::DAMPING_FACTOR;

    }

    /**
     * This methods can be used to check if the bounding boxes of two {@link PhysicalObject}
     * are intersecting
     * @param a The first object
     * @param b The second object
     * @return If the objects are colliding
     */
    bool collides(PhysicalObject* a, PhysicalObject* b) {
        // Object should NOT collide with themselves
        if (a != b) {
            Rectangle* bb1 = a->getBoundingBox();
            Rectangle* bb2 = b->getBoundingBox();

//            try{
//                if(bb1 == null)
//                    throw new NullPointerException("Bouding box not defined for " + a.getClass());

//                if(bb2 == null)
//                    throw new NullPointerException("Bouding box not defined for " + b.getClass());
//            }
//            catch(Exception e){
//                e.printStackTrace();
//                System.exit(-1);
//            }

            return bb1->intersects(bb2);
        } else
            return false;
    }
};


#endif // PHYSICSSIMULATOR_H

