#ifndef SCALE_GAME_H
#define SCALE_GAME_H

#include <vector>

namespace ScaleSpace {

    enum ErrorCode {
        ERROR_RANGE = -3,
        ERROR_CONV,
        ERROR_ARG_COUNT,
        SUCCESS,
        FAILURE
    };

    enum Entity {
        EMPTY_SPACE,
        PLAYER,
        WEIGHT,
        SCALE
    };

    enum GameState {
        ONGOING,
        VICTORY,
        FAIL

    };

    const int MAX_WEIGHT = 10;
    const int MAX_SCALE_VALUE = 10;
    const int MAX_ENV_SIZE = 20;

    struct Coordinate {
        int x;
        int y;
    };

    struct EntityData {
        Entity type;
        int value; // For weights, this represents the weight value. For scales, it represents the expected weight.
    };

    using Environment = std::vector<std::vector<EntityData>>;

    void initializeEnvironment(Environment& env, int envSize, int totalWeights, int numScales);
    void printEnvironment(const Environment& env);
    bool movePlayer(Environment& env, Coordinate& playerPos, Coordinate& newPos);
    bool dropWeight(Environment& env, Coordinate& playerPos);
    GameState checkGameState(const Environment& env);
}

#endif // SCALE_GAME_H
