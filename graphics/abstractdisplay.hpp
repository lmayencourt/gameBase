#ifndef ABSTRACTDISPLAY
#define ABSTRACTDISPLAY

#include <list>

#include "idisplay.h"
#include "graphicobject.hpp"

class AbstractDisplay : public IDisplay
{
public:
    /**
     * Draw the element on the screen
     *
     * @return void
     */
    virtual void refresh()=0;

    /**
     * Remove all objects to the display
     *
     * @param o  The object to be added
     */
    void removeAllObjectsFromDisplay() {
        _draw_objects.clear();
    }

    /**
     * Adds a new object to the dispaly
     *
     * @param o  The object to be added
     */
    void addObjectToDisplay(IDrawable* o) {
        _draw_objects.push_back(o);
    }

    /**
     * remove an object from display
     */
    void removeObjectFromDisplay(IDrawable* o) {
        _draw_objects.remove(o);
    }

protected:
    /**
     * The objects that require to be drawed
     */
    std::list<IDrawable*> _draw_objects;
};

#endif // ABSTRACTDISPLAY
