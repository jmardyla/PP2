#include "object.h"

ObjectType Object::type() const{
    return this->object_;
}

Position Object::position() const{
    return this->pos_;
}

void Object::setPosition(Position new_pos) {
    this->pos_ = new_pos;
}

void Object::moveUp() {
    this->pos_.moveUp();
}

void Object::moveDown() {
    this->pos_.moveDown();
}

void Object::moveLeft() {
    this->pos_.moveLeft();
}

void Object::moveRight() {
    this->pos_.moveRight();
}

