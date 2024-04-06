/**
 * @brief Implements all classes that are relevant
 *
 * @file class.cpp
 */

#include <string>
#include <unordered_map>

#include "class.h"

using namespace std;

Action::Action(string act) : thisAction(AvailableActions::invalid) {
    static std::unordered_map<std::string, AvailableActions> const table = {
        {"check-egg", AvailableActions::check_for_egg},
        {"feed", AvailableActions::feed},
        {"play", AvailableActions::play},
        {"put-to-sleep", AvailableActions::put_to_sleep},
        {"slaughter", AvailableActions::slaughter},
        {"therapize", AvailableActions::therapize},
        {"train", AvailableActions::train},
        {"wakeup", AvailableActions::wakeup},
    };

    auto it = table.find(act);
    if (it != table.end()) {
        this->thisAction = it->second;
    }
}

enum AvailableActions Action::get() {
    return this->thisAction;
}


Effects::Effects(int born, int sick) : born(born), sleep(0), depressive(0), hatching(0), overworked(0), sick(sick) {};
Effects::Effects(int born, int sleep, int depressive, int hatching, int overworked, int sick) :
    born(born),
    sleep(sleep),
    depressive(depressive),
    hatching(hatching),
    overworked(overworked),
    sick(sick)
{};

Stats::Stats() : fitness(10), happiness(10), motivation(10), resillience(10), restfulness(10), saturation(10) {};
Stats::Stats(
    int_fast8_t fitness,
    int_fast8_t happiness,
    int_fast8_t motivation,
    int_fast8_t resillience,
    int_fast8_t restfulness,
    int_fast8_t saturation
) :
    fitness(fitness),
    happiness(happiness),
    motivation(motivation),
    resillience(resillience),
    restfulness(restfulness),
    saturation(saturation)
{};

void Stats::adjustFitness(int_fast8_t val) {this->adjustValue(&this->fitness, val);};
void Stats::setFitness(int_fast8_t val) {this->setValue(&this->fitness, val);};

void Stats::adjustHappiness(int_fast8_t val) {this->adjustValue(&this->happiness, val);};
void Stats::setHappiness(int_fast8_t val) {this->setValue(&this->happiness, val);};

void Stats::adjustMotivation(int_fast8_t val) {this->adjustValue(&this->motivation, val);};
void Stats::setMotivation(int_fast8_t val) {this->setValue(&this->motivation, val);};

void Stats::adjustResillience(int_fast8_t val) {this->adjustValue(&this->resillience, val);};
void Stats::setResillience(int_fast8_t val) {this->setValue(&this->resillience, val);};

void Stats::adjustRestfulness(int_fast8_t val) {this->adjustValue(&this->restfulness, val);};
void Stats::setRestfulness(int_fast8_t val) {this->setValue(&this->restfulness, val);};

void Stats::adjustSaturation(int_fast8_t val) {this->adjustValue(&this->saturation, val);};
void Stats::setSaturation(int_fast8_t val) {this->setValue(&this->saturation, val);};

void Stats::capValue(int_fast8_t *field) {
    if (*field > 100) {
        *field = 100;
    } else if (*field < 0) {
        *field = 0;
    };
};

void Stats::adjustValue(int_fast8_t *field, int_fast8_t value) {
    *field += value;
    capValue(field);
};

void Stats::setValue(int_fast8_t *field, int_fast8_t value) {
    *field = value;
    capValue(field);
}


void Entity::performAction(AvailableActions action) {
    switch (action) {
        case AvailableActions::check_for_egg  : this->checkForEgg();    break;
        case AvailableActions::feed           : this->feed();           break;
        case AvailableActions::play           : this->play();           break;
        case AvailableActions::put_to_sleep   : this->putToSleep();     break;
        case AvailableActions::slaughter      : this->slaughter();      break;
        case AvailableActions::therapize      : this->therapize();      break;
        case AvailableActions::train          : this->train();          break;
        case AvailableActions::wakeup         : this->wakeup();         break;
        default                               : this->invalidAction();  break;
    }
};