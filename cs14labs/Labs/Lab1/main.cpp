// Marvin Cao
// Brandon Tran

#include <list>
#include <iostream>
#include "Character.h"
#include "Elf.h"
#include "Warrior.h"
#include "Wizard.h"

using namespace std;

int main() {
    
    list<Character*> player1, player2;
    
    
    player1.push_back(new Warrior("Arthur", MAX_HEALTH, 7, "King Garon"));
    player1.push_back(new Wizard("Merlin", MAX_HEALTH, 5, 10));
    player1.push_back(new Elf("Cereasstar", MAX_HEALTH, 3, "Sylvarian"));
    player1.push_back(new Wizard("Adali", MAX_HEALTH, 5, 8));
    
    player2.push_back(new Warrior("Bob", MAX_HEALTH, 4, "Queen Emily"));
    player2.push_back(new Elf("Melimion", MAX_HEALTH, 4, "Valinorian"));
    player2.push_back(new Wizard("Vrydore", MAX_HEALTH, 4, 6));
    player2.push_back(new Warrior("Jane", MAX_HEALTH, 6, "King George"));
    
    
    while(!player1.empty() && !player2.empty()) {
        list<Character*>::iterator it1 = player1.begin();
        list<Character*>::iterator it2 = player2.begin();
        int sets = 0;
        
        for(int i = 1; it1 != player1.end() && it2 != player2.end() ;++i) // i = Round
        {
            // cout << "Round " << i << endl;
            bool p1Loss = false;
            bool p2Loss = false;
            if (sets%2 == 0) // if set is even and round is odd
            {
                (*it1) -> attack(*(*it2));
                // check if die
                if (!(*it2)->isAlive()) // if dead
                {
                    it2 = player2.erase(it2);
                    p2Loss = true;
                }
                else
                    (*it2) -> attack(*(*it1));
                    
                if (!(*it1)->isAlive())
                {
                    it1 = player1.erase(it1);
                    p1Loss = true;
                }
            }else
            {
                (*it2) -> attack(*(*it1));
                // check if die
                if(!(*it1)->isAlive())
                {
                    it1 = player1.erase(it1);
                    p1Loss = true;
                }
                else
                    (*it1) -> attack(*(*it2));
                    
                if (!(*it2)->isAlive())
                {
                    it2 = player2.erase(it1);
                    p2Loss = true;
                }
                    
            }
            if(!p1Loss)
                --it1;
            if(!p2Loss)
                --it2;
        }
        ++sets;
    }
    
    if(player1.empty())
    {
        cout << "Player 1 WONE!!!! :) " << endl;
    }
    else
    {
        cout << "Player 2 Won!!!! " << endl;
    }
    return 0;
}




