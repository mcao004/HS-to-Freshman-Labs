#ifndef ELF_H
#define ELF_H

#include "Character.h"
#include <iostream>
using namespace std;

class Elf : public Character {
    private:
        string family;
    public:
        Elf(string, double, double, string);
        void attack(Character&);
        string getFamily() const;
};

#endif