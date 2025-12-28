#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <vector>

enum class GameState {
    ONGOING,
    WON,
    LOST
};

enum class StatusCode {
    ERROR_RANGE = -3,
    ERROR_CONV,
    ERROR_ARG_COUNT,
    SUCCESS
};

enum class Action {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    UP_RIGHT,
    UP_LEFT,
    DOWN_RIGHT,
    DOWN_LEFT,
    ATTACK_MONSTER
};

enum class Entity {
    EMPTY_SPACE,
    ENERGY_FIELD,
    WALL,
    EXIT,
    PLAYER,
    MONSTER
};

// Object Structure Definition
struct GameWorld {
    std::vector<std::vector<int>> arrWorld;
    GameState eState;
    int intRows;
    int intCols;
    int intPRow;
    int intPCol;
    int intNumItemsWithPlayer;
    int intNumMonstersInWorld;
    const char ARR_ENTITIES[6] = {' ', 'T', '#', 'E', 'P', 'M'};
    void (*displayWorld)(const GameWorld*);
    void (*performAction)(GameWorld*, Action);
};

// Function Pointer Definitions
void displayWorld(const GameWorld* gameWorld);
void performAction(GameWorld* gameWorld, Action eAction);

//  Object Creation Function
GameWorld* createGameWorld(int rows, int cols, int numMonsters, int numItems, int numObstacles);

//  Object Destruction Function
void destroyGameWorld(GameWorld* gameWorld);

#endif // GAMEWORLD_H
