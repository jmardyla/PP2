//
// Created by janek on 07.04.2023.
//

#ifndef ZAD4SHAPEDRAWING_DLASTUDENTOW_SHAPECOMPOSITE_H
#define ZAD4SHAPEDRAWING_DLASTUDENTOW_SHAPECOMPOSITE_H
#include <memory>
#include "shape.h"
using namespace std;


namespace Shapes {
    enum class ShapeOperation {
        INTERSECTION,
        SUM,
        DIFFERENCE
    };

    class ShapeComposite : public Shape {
        shared_ptr<Shape> firstShape_, secondShape_;
        ShapeOperation shapeOperation_;
    public:
        ShapeComposite(shared_ptr<Shape> firstShape, shared_ptr<Shape> secondShape_, ShapeOperation shapeOperation): firstShape_(firstShape), secondShape_(secondShape_), shapeOperation_(shapeOperation) {};
        bool isIn(int x, int y) const override;
    };

} // Shapes

#endif //ZAD4SHAPEDRAWING_DLASTUDENTOW_SHAPECOMPOSITE_H
