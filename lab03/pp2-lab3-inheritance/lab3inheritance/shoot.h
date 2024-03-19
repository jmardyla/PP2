#ifndef SHOOT_H
#define SHOOT_H

#include "object.h"
#include "direction.h"


/**
 * Proszę o utworzenie klasy `Shoot`, która będzie dziedziczyć po klasie `Object`, następnie proszę zakomentować `UNIMPLEMENTED_shootIsObject`
 * - Klasa ta powinna mieć mieć składową `direction_`, a także operujący na niej getter i setter
 * - Klasa powinna mieć konstruktor przyjmujący kierunek i pozycje początkową
 * - Po zaimplementowania tego proszę zakomentować `UNIMPLEMENTED_shootHasDirectionAndPosition`
 * - Klasa powinna zawierać statyczny atrybut odpowiadający prędkości o wartości `2`, oraz getter `speed()`
 */

//#define UNIMPLEMENTED_shootIsObject
//#define UNIMPLEMENTED_shootHasDirectionAndPosition


class Shoot : public Object
{
// TODO...
    Direction direction_;
    inline static int speed_ = 2;

public:
    Shoot(Direction direction, Position position): Object(ObjectType::OBJECT_SHOOT, position), direction_(direction){};
    Direction direction() const { return this->direction_; };
    void setDirection(Direction new_direction) { this->direction_=new_direction; };
    static int speed() { return speed_; };
};

#endif // SHOOT_H
