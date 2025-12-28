#include "ScaleSpace.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace ScaleSpace {

    void initializeEnvironment(Environment& env, int envSize, int totalWeights, int numScales) {
        // Initialize random seed
        srand(static_cast<unsigned>(time(nullptr)));

        // Resize the environment
        env.resize(envSize, std::vector<EntityData>(envSize, {Entity::EMPTY_SPACE, 0}));

        // Place player
        Coordinate playerPos = {envSize / 2, envSize / 2};
        env[playerPos.y][playerPos.x].type = Entity::PLAYER;

        // Place scales
        for (int i = 0; i < numScales; ++i) {
            Coordinate scalePos = {rand() % envSize, rand() % envSize};
            env[scalePos.y][scalePos.x].type = Entity::SCALE;
            env[scalePos.y][scalePos.x].value = rand() % (MAX_SCALE_VALUE + 1);
            totalWeights -= env[scalePos.y][scalePos.x].value;
        }

        // Place weights
        while (totalWeights > 0) {
            Coordinate weightPos = {rand() % envSize, rand() % envSize};
            if (env[weightPos.y][weightPos.x].type == Entity::EMPTY_SPACE) {
                env[weightPos.y][weightPos.x].type = Entity::WEIGHT;
                env[weightPos.y][weightPos.x].value = 1;
                totalWeights--;
            }
        }
    }

    void printEnvironment(const Environment& env) {
        for (const auto& row : env) {
            for (const auto& entity : row) {
                switch (entity.type) {
                    case Entity::EMPTY_SPACE:
                        std::cout << ".";
                        break;
                    case Entity::PLAYER:
                        std::cout << "P";
                        break;
                    case Entity::WEIGHT:
                        std::cout << "W";
                        break;
                    case Entity::SCALE:
                        std::cout << "S";
                        break;
                }
                std::cout << " ";
            }
            std::cout << std::endl;
        }
    }

  bool movePlayer(Environment& env, Coordinate& playerPos, Coordinate& newPos) {
    // Check if the new position is within bounds
    if (newPos.x < 0 || newPos.x >= env.size() || newPos.y < 0 || newPos.y >= env.size())
        return false;

    // Move player if the new position is empty or contains a weight
    if (env[newPos.y][newPos.x].type == Entity::EMPTY_SPACE || env[newPos.y][newPos.x].type == Entity::WEIGHT) {
        env[playerPos.y][playerPos.x].type = Entity::EMPTY_SPACE;

        // Check if the new position contains a scale
        if (env[newPos.y][newPos.x].type == Entity::SCALE) {
            // If the player is carrying weights
            if (env[playerPos.y][playerPos.x].value > 0) {
                // Subtract the weights from the scale's value
                env[newPos.y][newPos.x].value -= env[playerPos.y][playerPos.x].value;
                // If the scale's value becomes 0, remove the scale from the world
                if (env[newPos.y][newPos.x].value == 0) {
                    env[newPos.y][newPos.x].type = Entity::EMPTY_SPACE;
                } else {
                    // If the scale's value is not 0, end the game in failure
                    return false;
                }
            }
        }

        // Move the player to the new position
        env[newPos.y][newPos.x].type = Entity::PLAYER;
        playerPos = newPos;
        return true;
    }
    return false;
}


    bool dropWeight(Environment& env, Coordinate& playerPos) {
        // Implementation for dropping weight
        int envSize = env.size();
        Coordinate newPos;
        while (true) {
            newPos = {playerPos.x + rand() % 3 - 1, playerPos.y + rand() % 3 - 1};
            if (newPos.x >= 0 && newPos.x < envSize && newPos.y >= 0 && newPos.y < envSize &&
                env[newPos.y][newPos.x].type == Entity::EMPTY_SPACE) {
                env[newPos.y][newPos.x].type = Entity::WEIGHT;
                return true;
            }
        }
        return false; // Should never reach here
    }

    GameState checkGameState(const Environment& env) {
        // Implementation for checking game state
        bool allScalesRemoved = true;
        bool scaleValueMismatch = false;
        for (const auto& row : env) {
            for (const auto& entity : row) {
                if (entity.type == Entity::SCALE) {
                    if (entity.value != 0) {
                        scaleValueMismatch = true;
                    }
                    allScalesRemoved = false;
                }
            }
        }
        if (scaleValueMismatch) {
            return GameState::FAIL;
        } else if (allScalesRemoved) {
            return GameState::VICTORY;
        } else {
            return GameState::ONGOING;
        }
    }
}
