/**
 * @brief Declares all classes and objects that are relevant
 *
 * @file class.h
 */

#include <string.h>

/**
 * @brief Available actions to interact with the entity
 */
enum Action {
    check_for_egg,
    feed,
    play,
    put_to_sleep,
    slaughter,
    therapize,
    train,
    wakeup,
};

/**
 * @brief Effects that can be applied to the entity
 */
class Effects {
    public:
        int born;
        int sleep;
        int depressive;
        int hatching;
        int overworked;
        int sick;

        Effects(int born, int sick);
        Effects(int born, int sleep, int depressive, int hatching, int overworked, int sick);
};

/**
 * @brief Stats that the entity has
 */
class Stats {
    public:
        int fitness;
        int happiness;
        int motivation;
        int resillience;
        int restfulness;
        int saturation;

        Stats();
        Stats(int fitness, int happiness, int motivation, int resillience, int restfulness, int saturation);
};

/**
 * @brief The Entity itself
 */
class Entity {
    public:
        Stats *thisStats;
        Effects *thisEffects;
        String thisName;
        u32 lastUpdate;
        u32 inStateUntil;

        Entity();
};