//
// Created by janek on 07.04.2023.
//

#ifndef ZAD4SHAPEDRAWING_DLASTUDENTOW_CIRCLE_H
#define ZAD4SHAPEDRAWING_DLASTUDENTOW_CIRCLE_H
#include "shape.h"

namespace Shapes {

    class Circle : public Shape {
        Point center_;
        int radius_;
    public:
        Circle(int x, int y, int radius): center_(x, y), radius_(radius) {};
        bool isIn(int x, int y) const override;
        int x() const {return this->center_.x_;};
        int y() const {return this->center_.y_;};
        int getRadius() const {return this->radius_;}

    };

} // Shapes

#endif //ZAD4SHAPEDRAWING_DLASTUDENTOW_CIRCLE_H
