//
// Created by janek on 07.04.2023.
//

#ifndef ZAD4SHAPEDRAWING_DLASTUDENTOW_RECTANGLE_H
#define ZAD4SHAPEDRAWING_DLASTUDENTOW_RECTANGLE_H
#include "shape.h"

namespace Shapes {

class Rectangle : public Shape {
    Point bottomLeft_, upperRight_;
public:
    Rectangle(int xFrom, int yFrom, int xTo, int yTo): bottomLeft_(xFrom, yFrom), upperRight_(xTo, yTo) {};
    bool isIn(int x, int y) const override;
    int x() const;
    int y() const;
    int xTo() const;
    int yTo() const;
};

} // Shapes

#endif //ZAD4SHAPEDRAWING_DLASTUDENTOW_RECTANGLE_H
