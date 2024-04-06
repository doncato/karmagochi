/**
 * @brief Declares all classes and objects that are relevant
 *
 * @file class.h
 */

#include <string>
#include <cstdint>

/**
 * @brief Available actions to interact with the entity
 */
enum AvailableActions {
    check_for_egg,
    feed,
    play,
    put_to_sleep,
    slaughter,
    therapize,
    train,
    wakeup,
    invalid
};

class Action {
    private:
        enum AvailableActions thisAction;   

    public:
        Action(std::string act);

        /**
         * @brief Gets the chosen action
         * 
         * @return enum AvailableActions 
         */
        enum AvailableActions get();
};

/**
 * @brief Effects that can be applied to the entity
 */
class Effects {
    private:
        int born;
        int sleep;
        int depressive;
        int hatching;
        int overworked;
        int sick;

    public:
        Effects(int born, int sick);
        Effects(int born, int sleep, int depressive, int hatching, int overworked, int sick);
};

/**
 * @brief Stats that the entity has
 */
class Stats {
    private:
        int_fast8_t fitness;
        int_fast8_t happiness;
        int_fast8_t motivation;
        int_fast8_t resillience;
        int_fast8_t restfulness;
        int_fast8_t saturation;

    public:
        Stats();
        Stats(
            int_fast8_t fitness,
            int_fast8_t happiness,
            int_fast8_t motivation,
            int_fast8_t resillience,
            int_fast8_t restfulness,
            int_fast8_t saturation
        );

        void adjustFitness(int_fast8_t val);
        void setFitness(int_fast8_t val);

        void adjustHappiness(int_fast8_t val);
        void setHappiness(int_fast8_t val);

        void adjustMotivation(int_fast8_t val);
        void setMotivation(int_fast8_t val);

        void adjustResillience(int_fast8_t val);
        void setResillience(int_fast8_t val);

        void adjustRestfulness(int_fast8_t val);
        void setRestfulness(int_fast8_t val);

        void adjustSaturation(int_fast8_t val);
        void setSaturation(int_fast8_t val);


    private:
        /**
         * @brief Ensures the value of the given attribute is within limits
         * 
         * @param field the value to check
         */
        void capValue(int_fast8_t *field);

        /**
         * @brief Adjust the given field with the given value
         * 
         * @param field The field to adjust
         * @param val the value to adjust with
         */
        void adjustValue(int_fast8_t *field, int_fast8_t val);

        /**
         * @brief Set the Value of the given field
         * 
         * @param field the field to set
         * @param val the value to set on the field
         */
        void setValue(int_fast8_t *field, int_fast8_t val);
};

/**
 * @brief The Entity itself
 */
class Entity {
    private:
        Stats *thisStats;
        Effects *thisEffects;
        std::string thisName;
        uint32_t lastUpdate;
        uint32_t inStateUntil;

    public:

        Entity();
        
        /**
         * @brief Performs the supplied action on the Entity
         * @param action the action that is to be performed
         */
        void performAction(AvailableActions action);

        void checkForEgg();
        void feed();
        void play();
        void putToSleep();
        void slaughter();
        void therapize();
        void train();
        void wakeup();
        void invalidAction();

    private:
        /**
         * @brief Updates the 'lastUpdate' variable to now
        */
        void updateTime();
};