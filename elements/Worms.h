/*
 * Worms.h
 *
 *  Created on: 23 sept. 2015
 *      Author: mayencourtlouis
 */

#ifndef GAME_WORMS_H_
#define GAME_WORMS_H_

#include "physicssimulator.hpp"
#include "physicalobject.hpp"
#include "drawable.h"
#include "rectangle.hpp"
#include "Projectile.h"

class Worms : public PhysicalObject , public Drawable
{
private:
	bool sens=true;
	bool onJump = true;

	Projectile* projectile;
	float launchAngle;

	PhysicsSimulator* thePhySim;
	std::list<Drawable*>* theDrawList;

public:
	Worms();
	virtual ~Worms();

	/**
	 * Draw the element on the screen
	 *
	 * @return void
	 */
	void draw() ;

	/**
	 * Default implementation
	 * see {@link Collisionnable}
	 */
   Rectangle* getBoundingBox();


   /**
    * Launch a projectile
    */
   void launch(int energy);


	float getLaunchAngle() const {
		return launchAngle;
	}

	void setLaunchAngle(float launchAngle) {
		this->launchAngle = launchAngle;
	}

	bool isSens() const {
		return sens;
	}

	void setSens(bool sens = true) {
		this->sens = sens;
	}

	 std::list<Drawable*>* getTheDrawList()  {
		return theDrawList;
	}

	void setTheDrawList( std::list<Drawable*>* theDrawList) {
		this->theDrawList = theDrawList;
	}

	 PhysicsSimulator* getThePhySim()  {
		return thePhySim;
	}

	void setThePhySim( PhysicsSimulator* thePhySim) {
		this->thePhySim = thePhySim;
	}
};

#endif /* GAME_WORMS_H_ */
