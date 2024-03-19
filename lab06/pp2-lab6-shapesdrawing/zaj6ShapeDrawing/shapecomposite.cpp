//
// Created by janek on 07.04.2023.
//

#include "shapecomposite.h"

namespace Shapes {
    bool ShapeComposite::isIn(int x, int y) const {
        switch (this->shapeOperation_) {
            case ShapeOperation::SUM:
                return (firstShape_->isIn(x, y) || secondShape_->isIn(x, y));
            case ShapeOperation::INTERSECTION:
                return (firstShape_->isIn(x, y) && secondShape_->isIn(x, y));
            case ShapeOperation::DIFFERENCE:
                return (firstShape_->isIn(x, y) && not secondShape_->isIn(x, y));
            default:
                return false;
        }
    }
} // Shapes