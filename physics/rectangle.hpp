/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia. For licensing terms and
** conditions see http://qt.digia.com/licensing. For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights. These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef RECT_H
#define RECT_H

class Rectangle
{
public:
    Rectangle() : _x1(0), _y1(0), _x2(-1), _y2(-1) {}
	Rectangle(int left, int top, int width, int height);

    inline bool isNull() const;
    inline bool isEmpty() const;
    inline bool isValid() const;

    inline int left() const;
    inline int top() const;
    inline int right() const;
    inline int bottom() const;

    inline int x() const;
    inline int y() const;
    inline void setLeft(int pos);
    inline void setTop(int pos);
    inline void setRight(int pos);
    inline void setBottom(int pos);
    inline void setX(int x);
    inline void setY(int y);

    inline void moveLeft(int pos);
    inline void moveTop(int pos);
    inline void moveRight(int pos);
    inline void moveBottom(int pos);

    inline void translate(int dx, int dy);

    inline void moveTo(int x, int t);

    inline void setRect(int x, int y, int w, int h);
    inline void getRect(int *x, int *y, int *w, int *h) const;

    inline void setCoords(int _x1, int _y1, int _x2, int _y2);
    inline void getCoords(int *_x1, int *_y1, int *_x2, int *_y2) const;

    inline void adjust(int _x1, int _y1, int _x2, int _y2);
    inline Rectangle adjusted(int _x1, int _y1, int _x2, int _y2) const;

    inline int width() const;
    inline int height() const;
    inline void setWidth(int w);
    inline void setHeight(int h);

    Rectangle operator|(const Rectangle &r) const;
    Rectangle operator&(const Rectangle &r) const;
    inline Rectangle& operator|=(const Rectangle &r);
    inline Rectangle& operator&=(const Rectangle &r);

    bool contains(const Rectangle &r, bool proper = false) const;
    inline bool contains(int x, int y) const;
    inline bool contains(int x, int y, bool proper) const;
    inline Rectangle united(const Rectangle &other) const ;
    inline Rectangle intersected(const Rectangle &other) const;
    bool intersects(Rectangle* r);
    bool valueInRange(int value, int min, int max);

    friend inline bool operator==(const Rectangle &, const Rectangle &);
    friend inline bool operator!=(const Rectangle &, const Rectangle &);

private:
    int _x1;
    int _y1;
    int _x2;
    int _y2;
};
 inline bool operator==(const Rectangle &, const Rectangle &);
 inline bool operator!=(const Rectangle &, const Rectangle &);


/*****************************************************************************
  QRect inline member functions
 *****************************************************************************/
 inline Rectangle::Rectangle(int aleft, int atop, int awidth, int aheight)
    : _x1(aleft), _y1(atop), _x2(aleft + awidth - 1), _y2(atop + aheight - 1) {}

 inline bool Rectangle::isNull() const
{ return _x2 == _x1 - 1 && _y2 == _y1 - 1; }

 inline bool Rectangle::isEmpty() const
{ return _x1 > _x2 || _y1 > _y2; }

  inline bool Rectangle::isValid() const
{ return _x1 <= _x2 && _y1 <= _y2; }

 inline int Rectangle::left() const
{ return _x1; }

 inline int Rectangle::top() const
{ return _y1; }

 inline int Rectangle::right() const
{ return _x2; }

 inline int Rectangle::bottom() const
{ return _y2; }

 inline int Rectangle::x() const
{ return _x1; }

 inline int Rectangle::y() const
{ return _y1; }

inline void Rectangle::setLeft(int pos)
{ _x1 = pos; }

inline void Rectangle::setTop(int pos)
{ _y1 = pos; }

inline void Rectangle::setRight(int pos)
{ _x2 = pos; }

inline void Rectangle::setBottom(int pos)
{ _y2 = pos; }

inline void Rectangle::setX(int ax)
{ _x1 = ax; }

inline void Rectangle::setY(int ay)
{ _y1 = ay; }

 inline int Rectangle::width() const
{ return  _x2 - _x1 + 1; }

 inline int Rectangle::height() const
{ return  _y2 - _y1 + 1; }


inline void Rectangle::translate(int dx, int dy)
{
    _x1 += dx;
    _y1 += dy;
    _x2 += dx;
    _y2 += dy;
}

inline void Rectangle::moveTo(int ax, int ay)
{
    _x2 += ax - _x1;
    _y2 += ay - _y1;
    _x1 = ax;
    _y1 = ay;
}

inline void Rectangle::moveLeft(int pos)
{ _x2 += (pos - _x1); _x1 = pos; }

inline void Rectangle::moveTop(int pos)
{ _y2 += (pos - _y1); _y1 = pos; }

inline void Rectangle::moveRight(int pos)
{
    _x1 += (pos - _x2);
    _x2 = pos;
}

inline void Rectangle::moveBottom(int pos)
{
    _y1 += (pos - _y2);
    _y2 = pos;
}


inline void Rectangle::getRect(int *ax, int *ay, int *aw, int *ah) const
{
    *ax = _x1;
    *ay = _y1;
    *aw = _x2 - _x1 + 1;
    *ah = _y2 - _y1 + 1;
}

inline void Rectangle::setRect(int ax, int ay, int aw, int ah)
{
    _x1 = ax;
    _y1 = ay;
    _x2 = (ax + aw - 1);
    _y2 = (ay + ah - 1);
}

inline void Rectangle::getCoords(int *xp1, int *yp1, int *xp2, int *yp2) const
{
    *xp1 = _x1;
    *yp1 = _y1;
    *xp2 = _x2;
    *yp2 = _y2;
}

inline void Rectangle::setCoords(int xp1, int yp1, int xp2, int yp2)
{
    _x1 = xp1;
    _y1 = yp1;
    _x2 = xp2;
    _y2 = yp2;
}


inline void Rectangle::adjust(int dx1, int dy1, int dx2, int dy2)
{
    _x1 += dx1;
    _y1 += dy1;
    _x2 += dx2;
    _y2 += dy2;
}

inline void Rectangle::setWidth(int w)
{ _x2 = (_x1 + w - 1); }

inline void Rectangle::setHeight(int h)
{ _y2 = (_y1 + h - 1); }

inline Rectangle& Rectangle::operator|=(const Rectangle &r)
{
    *this = *this | r;
    return *this;
}

inline Rectangle& Rectangle::operator&=(const Rectangle &r)
{
    *this = *this & r;
    return *this;
}

inline Rectangle Rectangle::intersected(const Rectangle &other) const
{
    return *this & other;
}

inline bool Rectangle::valueInRange(int value, int min, int max)
{
	return (value >= min) && (value <= max);
}

inline bool Rectangle::intersects(Rectangle* r)
{
	return
        (_x1 < r->_x2
      && _x2 > r->_x1
      && _y1 < r->_y2
      && _y2 > r->_y1);
}

inline Rectangle Rectangle::united(const Rectangle &r) const
{
    return *this | r;
}

 inline bool operator==(const Rectangle &r1, const Rectangle &r2)
{
    return r1._x1==r2._x1 && r1._x2==r2._x2 && r1._y1==r2._y1 && r1._y2==r2._y2;
}

 inline bool operator!=(const Rectangle &r1, const Rectangle &r2)
{
    return r1._x1!=r2._x1 || r1._x2!=r2._x2 || r1._y1!=r2._y1 || r1._y2!=r2._y2;
}

#endif // RECT_H
