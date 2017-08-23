#ifndef ABSTRACTJOYSTICK_H
#define ABSTRACTJOYSTICK_H

#include "ijoystick.h"

/**
 * @brief Default implementation of a Joystick with 6 positions
 *
 */
class AbstractJoystick : public IJoystick
{
protected:
    AbstractJoystick() {
        _position = Center;
        _pObserver = NULL;
    }

    ~AbstractJoystick() {}

    IJoystickObserver * _pObserver;
    Position _position;

public:

    /**
     * @brief Sets the observer that will receive events upon joystick position changes.
     *
     * @param 	observer Pointer to the observer object.
     * @return 	True if the observer was accepted, false if it was disabled (observer=NULL) or on error.
     */
    virtual bool setObserver( IJoystickObserver * observer ) {
        _pObserver = observer;

        return true;
    }

    /**
     * @brief Returns the actual position of the joystick.
     *
     * @return The actual position of the joystick.
     */
    virtual Position position() const {
        return _position;
    }

};

#endif // ABSTRACTJOYSTICK_H
