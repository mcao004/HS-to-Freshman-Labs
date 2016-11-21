#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"
#include <iostream>
using namespace std;

class Warrior : public Character {
    private:
        string allegiance;
    public:
        Warrior(string, double, double, string);
        void attack(Character&);
        string getAllegiance() const;
};

#endif