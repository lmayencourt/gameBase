#ifndef DRAWABLE
#define DRAWABLE

#include "idisplay.h"
#include "colors.h"

class IDrawable
{
public:

    /**
     * Draw the element on the screen
     *
     * @return void
     */
    virtual void draw(IDisplay* display)=0;

};

#endif // DRAWABLE

