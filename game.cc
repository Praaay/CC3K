#include "game.h"


// Game::Game(Floor &floor) : floor{floor} {}

void Game::newGame() {
    floor.generateFloor();
}

void Game::render() {
    floor.printFloor();
}