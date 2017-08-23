/*
 * Projectile.h
 *
 *  Created on: 5 oct. 2015
 *      Author: mayencourtlouis
 */

#ifndef GAME_PROJECTILE_H_
#define GAME_PROJECTILE_H_

#include "drawable.h"
#include "physicalobject.hpp"

class Projectile : public PhysicalObject, public Drawable
{
private:
    int radius;
public:
	Projectile();
	virtual ~Projectile();

	int getRadius() const {
		return radius;
	}

	void setRadius(int radius) {
		this->radius = radius;
	}

    /**
     * Draw the element on the screen
     *
     * @return void
     */
    void draw();

    /**
     * Default implementation
     * see {@link Collisionnable}
     */
    Rectangle* getBoundingBox();

};

#endif /* GAME_PROJECTILE_H_ */
