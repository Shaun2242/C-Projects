#include "GameWorld.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

//Implementations
int rangedRandom(int intLB, int intUB) {
    return rand() % (intUB - intLB + 1) + intLB;
}

bool isInWorld(const GameWorld* gameWorld, int intRow, int intCol) {
    return intRow >= 0 && intRow < gameWorld->intRows && intCol >= 0 && intCol < gameWorld->intCols;
}

void placeEntity(GameWorld* gameWorld, Entity eEntity, int intCount) {
    if (eEntity == Entity::EXIT) {
        int intCol = gameWorld->intCols - 1;
        int intRow = rangedRandom(0, gameWorld->intRows - 1);
        while (gameWorld->arrWorld[intRow][intCol] != static_cast<int>(Entity::EMPTY_SPACE)) {
            intRow = rangedRandom(0, gameWorld->intRows - 1);
        }
        gameWorld->arrWorld[intRow][intCol] = static_cast<int>(eEntity);
    } else if (eEntity == Entity::PLAYER) {
        int intCol = 0;
        int intRow = rangedRandom(0, gameWorld->intRows - 1);
        while (gameWorld->arrWorld[intRow][intCol] != static_cast<int>(Entity::EMPTY_SPACE)) {
            intRow = rangedRandom(0, gameWorld->intRows - 1);
        }
        gameWorld->arrWorld[intRow][intCol] = static_cast<int>(eEntity);
        gameWorld->intPRow = intRow;
        gameWorld->intPCol = intCol;
    } else {
        for (int i = 0; i < intCount; ++i) {
            int intRow = rangedRandom(0, gameWorld->intRows - 1);
            int intCol = rangedRandom(0, gameWorld->intCols - 1);
            while (gameWorld->arrWorld[intRow][intCol] != static_cast<int>(Entity::EMPTY_SPACE)) {
                intRow = rangedRandom(0, gameWorld->intRows - 1);
                intCol = rangedRandom(0, gameWorld->intCols - 1);
            }
            gameWorld->arrWorld[intRow][intCol] = static_cast<int>(eEntity);
        }
    }
}

void attackMonsters(GameWorld* gameWorld) {
    for (int r = gameWorld->intPRow - 1; r <= gameWorld->intPRow + 1; ++r) {
        for (int c = gameWorld->intPCol - 1; c <= gameWorld->intPCol + 1; ++c) {
            if (isInWorld(gameWorld, r, c) && gameWorld->arrWorld[r][c] == static_cast<int>(Entity::MONSTER)) {
                gameWorld->arrWorld[r][c] = static_cast<int>(Entity::EMPTY_SPACE);
                gameWorld->intNumMonstersInWorld--;
            }
        }
    }
}

void displayWorld(const GameWorld* gameWorld) {
    for (int r = 0; r < gameWorld->intRows; ++r) {
        for (int c = 0; c < gameWorld->intCols; ++c) {
            std::cout << gameWorld->ARR_ENTITIES[gameWorld->arrWorld[r][c]] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << "Energy Field Units: " << gameWorld->intNumItemsWithPlayer * 5 << std::endl
              << "Monsters Remaining: " << gameWorld->intNumMonstersInWorld << std::endl
              << "Movement: W, S, A, D, Q, E, Z, X" << std::endl
              << "Attack Monsters: C" << std::endl;
}

void performAction(GameWorld* gameWorld, Action eAction) {
    int intDRow = gameWorld->intPRow;
    int intDCol = gameWorld->intPCol;
    bool blnMoved = true;

    switch (eAction) {
        case Action::UP:
            intDRow--;
            break;
        case Action::DOWN:
            intDRow++;
            break;
        case Action::LEFT:
            intDCol--;
            break;
        case Action::RIGHT:
            intDCol++;
            break;
        case Action::UP_LEFT:
            intDRow--;
            intDCol--;
            break;
        case Action::UP_RIGHT:
            intDRow--;
            intDCol++;
            break;
        case Action::DOWN_LEFT:
            intDRow++;
            intDCol--;
            break;
        case Action::DOWN_RIGHT:
            intDRow++;
            intDCol++;
            break;
        case Action::ATTACK_MONSTER:
            blnMoved = false;
            if (gameWorld->intNumItemsWithPlayer > 0) {
                gameWorld->intNumItemsWithPlayer--;
                attackMonsters(gameWorld);
                if (gameWorld->intNumMonstersInWorld == 0) {
                    placeEntity(gameWorld, Entity::EXIT, 1);
                }
            }
            break;
    }

    if (blnMoved && isInWorld(gameWorld, intDRow, intDCol) && gameWorld->arrWorld[intDRow][intDCol] != static_cast<int>(Entity::WALL)) {
        if (gameWorld->arrWorld[intDRow][intDCol] == static_cast<int>(Entity::ENERGY_FIELD)) {
            gameWorld->intNumItemsWithPlayer++;
        } else if (gameWorld->arrWorld[intDRow][intDCol] == static_cast<int>(Entity::MONSTER)) {
            gameWorld->eState = GameState::LOST;
        } else if (gameWorld->arrWorld[intDRow][intDCol] == static_cast<int>(Entity::EXIT)) {
            gameWorld->eState = GameState::WON;
        }
        gameWorld->arrWorld[intDRow][intDCol] = static_cast<int>(Entity::PLAYER);
        gameWorld->arrWorld[gameWorld->intPRow][gameWorld->intPCol] = static_cast<int>(Entity::EMPTY_SPACE);
        gameWorld->intPRow = intDRow;
        gameWorld->intPCol = intDCol;
    }
}

GameWorld* createGameWorld(int rows, int cols, int numMonsters, int numItems, int numObstacles) {
    GameWorld* gameWorld = new GameWorld;
    gameWorld->intRows = rows;
    gameWorld->intCols = cols;
    gameWorld->eState = GameState::ONGOING;
    gameWorld->intNumItemsWithPlayer = 0;
    gameWorld->intNumMonstersInWorld = numMonsters;
    gameWorld->arrWorld.resize(rows, std::vector<int>(cols, static_cast<int>(Entity::EMPTY_SPACE)));
    gameWorld->displayWorld = displayWorld;
    gameWorld->performAction = performAction;
    placeEntity(gameWorld, Entity::ENERGY_FIELD, numItems);
    placeEntity(gameWorld, Entity::WALL, numObstacles);
    placeEntity(gameWorld, Entity::MONSTER, numMonsters);
    placeEntity(gameWorld, Entity::PLAYER, 1);
    return gameWorld;
}

void destroyGameWorld(GameWorld* gameWorld) {
    delete gameWorld;
}
