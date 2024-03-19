#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"
#include "direction.h"

/**
 * Proszę o utworzenie klasy `Player`, która będzie dziedziczyć po klasie `Object`, następnie proszę zakomentować `UNIMPLEMENTED_playerIsObject`
 * - Klasa ta powinna mieć mieć składową `direction_`, a także operujący na niej getter i setter. Domyślna wartość to `Direction::RIGHT`
 *    - po zdefiniowaniu proszę usunąć `UNIMPLEMENTED_playerHasDirection`
 * - Klasa powinna mieć składową oznaczającą czy gracz żyje, oraz getter i setter: `isAlieve()`, `setIsAlieve()`
 *    - po zdefiniowaniu proszę usunąć `UNIMPLEMENTED_playerCanDie`
 */

//#define UNIMPLEMENTED_playerIsObject
//#define UNIMPLEMENTED_playerHasDirection
//#define UNIMPLEMENTED_playerCanDie

class Player : public Object
{
// TODO...
    Direction direction_;
    bool isAlive_;

public:
    explicit Player(Position position=Position(), Direction direction=Direction::RIGHT): Object(ObjectType::OBJECT_PLAYER, position), direction_(direction), isAlive_(true){};
    Direction direction() const { return this->direction_; };
    void setDirection(Direction new_direction) { this->direction_=new_direction; };
    bool isAlieve() const { return this->isAlive_; };
    void setIsAlieve(bool new_state) { this->isAlive_=new_state; };
};

#endif // PLAYER_H
