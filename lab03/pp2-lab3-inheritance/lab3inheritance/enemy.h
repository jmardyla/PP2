#ifndef ENEMY_H
#define ENEMY_H

#include "object.h"

/**
 * Proszę o utworzenie klasy `Enemy`, która będzie dziedziczyć po klasie `Object`
 * - Klasa ta powinna mieć mieć składową odpowiadającą ilości punktów życia, oraz getter: `lifePercent()`
 * - Klasa powinna mieć konstruktor przyjmujący aktualną pozycje oraz maksymalne życie z wartością domyślną.
 * - Klasa powinna mieć metodę `isAlieve()` która zwraca prawdę jeśli wróg ma życie powyżej zera
 * - Klasa powinna mieć metodę `decreaseLife()` przyjmującą jako argument liczbę obrażeń
 * - Po zaimplementowaniu powyższego proszę zakomentować makro `UNIMPLEMENTED_enemy`
 */

//#define UNIMPLEMENTED_enemy

class Enemy : public Object
{
    int lifeMax_;
    int lifeCurrent_;

public:
    // TODO:
    explicit Enemy(Position position, int lifePoints=100): Object(ObjectType::OBJECT_ENEMY, position), lifeMax_(lifePoints), lifeCurrent_(lifePoints){};
    float lifePercent() const;
    bool isAlieve() const;
    void decreaseLife(int damage);


};

#endif // ENEMY_H
