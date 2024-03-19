//
// Created by janek on 07.04.2023.
//

#include "rectangle.h"

namespace Shapes {
    bool Rectangle::isIn(int x, int y) const {
        return (bottomLeft_.x_ <= x && x <= upperRight_.x_ && bottomLeft_.y_ <= y && y <= upperRight_.y_);
    }

    int Rectangle::x() const {
        return this->bottomLeft_.x_;
    }

    int Rectangle::y() const {
        return this->bottomLeft_.y_;
    }

    int Rectangle::xTo() const {
        return this->upperRight_.x_;
    }
    int Rectangle::yTo() const {
        return this->upperRight_.y_;
    }
} // Shapes