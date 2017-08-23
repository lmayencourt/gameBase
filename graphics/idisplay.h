#ifndef IDISPLAY_H
#define IDISPLAY_H

class IDisplay
{
public :
    /**
     * Graphics primitive
     */
    virtual void drawCircle(int16_t x, int16_t y, int16_t r, uint16_t color)=0;
    virtual void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)=0;
    virtual void drawBitmap(int16_t x, int16_t y, int16_t w, int16_t h, void *bitmap)=0;
    virtual void drawText(int16_t x,int16_t y,std::string txt, uint16_t color)=0;
};

#endif // IDISPLAY_H
