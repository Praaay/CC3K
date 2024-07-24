#include "game.h"


//Game::Game(Floor &floor) : floor{floor} {}

Game::Game() : player(make_unique<Player>(3,5)) {}

Floor Game::getFloor() {
    return floor;
}
void Game::newGame() {
    floor.generateFloor();
}

void Game::render() {
    floor.printFloor();
}

void Game::moveplayer(std::string direction) {

    player->move(floor,direction);
}

void Game::nextFloor() {
    ++currLevel;
    floor.generateFloor();
}