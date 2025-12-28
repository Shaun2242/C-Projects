#include "ScaleSpace.h"
#include <iostream>

int main(int argc, char* argv[]) {

    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <environment size> <total weights> <number of scales>\n";
        return ScaleSpace::ERROR_ARG_COUNT;
    }

    int envSize = std::stoi(argv[1]);
    int totalWeights = std::stoi(argv[2]);
    int numScales = std::stoi(argv[3]);

    if (envSize <= 0 || totalWeights <= 0 || numScales <= 0 || numScales > envSize * envSize) {
        std::cerr << "Invalid arguments\n";
        return ScaleSpace::ERROR_RANGE;
    }


    ScaleSpace::Environment env;
    ScaleSpace::initializeEnvironment(env, envSize, totalWeights, numScales);

    ScaleSpace::Coordinate playerPos = {envSize / 2, envSize / 2};
    ScaleSpace::Coordinate newPos;

    bool carryingWeight = false;

    while (true) {
        ScaleSpace::printEnvironment(env);

        std::cout << "Enter movement (WASD) or 'D' to drop weight: ";
        char movement;
        std::cin >> movement;

        newPos = playerPos;

        switch (toupper(movement)) {
            case 'W':
                newPos.y--;
                break;
            case 'A':
                newPos.x--;
                break;
            case 'S':
                newPos.y++;
                break;
            case 'D':
                if (carryingWeight) {
                    if (ScaleSpace::dropWeight(env, playerPos)) {
                        std::cout << "Weight dropped.\n";
                        carryingWeight = false;
                    } else {
                        std::cout << "No space to drop weight! Game Over.\n";
                        return ScaleSpace::FAILURE;
                    }
                } else {
                    std::cout << "Player is not carrying any weight.\n";
                }
                continue;
            default:
                std::cout << "Invalid movement!\n";
                continue;
        }

        if (!ScaleSpace::movePlayer(env, playerPos, newPos)) {
            std::cout << "Invalid movement!\n";
            continue;
        }

        // Check if player is standing on a scale
        if (env[playerPos.y][playerPos.x].type == ScaleSpace::Entity::SCALE) {
            if (carryingWeight) {
                env[playerPos.y][playerPos.x].value -= 1;
                if (env[playerPos.y][playerPos.x].value == 0) {
                    env[playerPos.y][playerPos.x].type = ScaleSpace::Entity::EMPTY_SPACE;
                } else {
                    std::cout << "Scale value reduced to " << env[playerPos.y][playerPos.x].value << std::endl;
                }
                carryingWeight = false;
            }
        }

        // Check game state
        ScaleSpace::GameState state = ScaleSpace::checkGameState(env);
        if (state == ScaleSpace::FAIL) {
            std::cout << "Game Over! You failed to meet the conditions.\n";
            break;
        } else if (state == ScaleSpace::VICTORY) {
            std::cout << "Congratulations! You've won the game!\n";
            break;
        }

        // Pick up weight if present at new position
        if (env[playerPos.y][playerPos.x].type == ScaleSpace::Entity::WEIGHT) {
            carryingWeight = true;
            std::cout << "Weight picked up.\n";
        }
    }

    return ScaleSpace::SUCCESS;
}
