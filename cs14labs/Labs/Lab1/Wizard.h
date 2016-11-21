#ifndef WIZARD_H
#define WIZARD_H

#include "Character.h"
#include <iostream>
using namespace std;

class Wizard : public Character {
    private:
        int rank;
    public:
        Wizard(string, double, double, int);
        void attack(Character&);
        int getRank() const;
};

#endif