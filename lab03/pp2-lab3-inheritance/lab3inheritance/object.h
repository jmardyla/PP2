#ifndef OBJECT_H
#define OBJECT_H

#include "position.h"

/**
 * Proszę o zaimplementowanie klasy `Object`, która będzie miała trzymała typ obiektu
 * (zdefiniowany `ObjectType`), oraz pozycje (zdefiniowany `Position`).
 * Zaimplementuj metody:
 * - Konstruktor przyjmujący `ObjectType` i `Position` (pozycja niech ma wartość domyślną)
 * - gettery `type()` i `position()`
 * - następnie można usunąć: `UNIMPLEMENTED_objectWithConstructorAndGetters`
 * - setter `setPosition`, następnie można usunąć `UNIMPLEMENTED_objectSetPosition`
 * - metody do poruszania obiektem o jedną komórkę: `moveUp()`, `moveDown()`, `moveLeft()`, `moveRight()`, następnie można usunąć `UNIMPLEMENTED_movingObject`
 *    1. co zyskali byśmy gdyby `moveX()` zwracało `*this`?
 */

//#define UNIMPLEMENTED_objectWithConstructorAndGetters
//#define UNIMPLEMENTED_objectSetPosition
//#define UNIMPLEMENTED_movingObject

enum class ObjectType
{
    OBJECT_PLAYER,
    OBJECT_SHOOT,
    OBJECT_ENEMY,
    OBJECT_WALL,
    OBJECT_UNKNOWN
};

class Object
{
    ObjectType object_;
    Position pos_;

public:
    explicit Object(ObjectType obj, Position pos=Position()):object_(obj), pos_(pos) {
    }


    ObjectType type() const;
    Position position() const;
    void setPosition(Position new_pos);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};

#endif // OBJECT_H
