//
// Created by janek on 07.04.2023.
//

#include "circle.h"

namespace Shapes {
    bool Circle::isIn(int x, int y) const {
        Point secondPoint(x, y);
        return this->center_.calculateDistance(secondPoint) <= this->radius_;
    }
} // Shapes