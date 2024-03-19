#include <algorithm>
#include "engine.h"
#include "player.h"
#include "stage.h"
#include "shoot.h"
#include "enemy.h"


namespace {
inline auto signum(int x)
{
    return (x > 0) - (x < 0);
}

Direction randDirection()
{
    auto randEdge = rand() % static_cast<uint8_t>(Direction::UPPER_LEFT);
    return static_cast<Direction>(randEdge);
}
} // namespace


Position generateNewEnemyPosition(int width, int height)
{
    Position position2Generate = Position(rand() % width, rand() % height);

    switch (randDirection()) {
        case Direction::UP:
            position2Generate.y_ = height-1;
            break;
        case Direction::DOWN:
            position2Generate.y_ = 0;
            break;
        case Direction::LEFT:
            position2Generate.x_ = 0;
            break;
        case Direction::RIGHT:
            position2Generate.x_ = width-1;
            break;
        default:
            break;
    }
    return position2Generate;
}


Engine::~Engine() = default;



Engine::Engine(std::size_t stageWidth, std::size_t stageHeight):
    player_(new Player(Position(stageWidth/2, stageHeight/2))), stage_(new Stage(stageWidth, stageHeight))
{
    // TODO...

}

void Engine::update()
{
    updateBullets();
    updateEnemies();
    randEnemies();
}

void Engine::updateBullets()
{
    // TODO...
}

void Engine::updateEnemies()
{
    // TODO...
}

void Engine::movePlayerUp()
{
    // TODO...
    this->player_->moveUp();
}

void Engine::movePlayerDown()
{
    // TODO...
    this->player_->moveDown();
}

void Engine::movePlayerLeft()
{
    // TODO...
    this->player_->moveLeft();
}
void Engine::movePlayerRight()
{
    // TODO...
    this->player_->moveRight();
}

void Engine::playerShoots()
{
    // TODO...
    Shoot shoot(this->player_->direction(), this->player_->position().moveRight());
    shoots_.push_back(shoot);

}

Position Engine::playerPosition() const
{
    // TODO...
    return this->player_->position();
}

Direction Engine::playerDirection() const
{
    // TODO...
    return this->player_->direction();
}

bool Engine::isPlayerAlieve() const
{
    // TODO...
    return this->player_->isAlieve();
}

std::size_t Engine::stageWidthCells() const
{
    // TODO...
    return this->stage_->width();
}
std::size_t Engine::stageHeightCells() const
{
    // TODO...
    return this->stage_->height();
}

void Engine::randEnemies(Position (*positionGenerator)(int,int))
{
    if (enemies_.size() < maxEnemies_)
    {
        // TODO...
        Position new_position = positionGenerator(this->stageWidthCells(), this->stageHeightCells());
        auto* new_enemy_ptr = new Enemy(new_position);
        enemies_.emplace_back(new_enemy_ptr);
    }
}

