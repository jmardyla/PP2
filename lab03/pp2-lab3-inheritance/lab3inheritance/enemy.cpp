#include "enemy.h"

bool Enemy::isAlieve() const {
    if (lifeCurrent_ > 0) {
        return true;
    }
    else {
        return false;
    }
}

float Enemy::lifePercent() const {
    return ((float)lifeCurrent_/lifeMax_)*100;
}

void Enemy::decreaseLife(int damage) {
    this->lifeCurrent_ -= damage;
}

