#include <string>
#include <vector>
#include "Location.h"

using namespace std;

class Warrior
{
    public:
    Warrior(string sName){
         WarriorName = sName;
    };
    Warrior(string WName, int strg,int loyal, int morale);
    
    string getWarriorName();
    void setWarriorName(string sName);
    
    //determines the qualities if the warriors who are a part of the hero
    int getMorale();
    void setMorale(int morale);
    void setStrength(int strength);
    int getStrength();
    int getLoyalty();
    void setLoyalty(int loyalty);
    string getHeroName();
    void setHeroName(string sName);
    
    bool getIsFree();
    void setIsFree(bool bBol);
    bool getHasShip();
    void setHasShip(bool bBol);
    bool getHasDragonGlass();
    void setHasDragonGlass(bool bBol);
    void setWarriorLocation(Location loc);
    Location getWarriorLocation();
    
    //determines which hero this belongs to by passing hero object
    //also determines if they are free roaming or belong to the class of hero
    
    private:
    string HeroName;
    string WarriorName;
    int morale;
    int strength;
    int loyalty; 
    bool isFree;
    bool hasShip;
    bool hasDragonGlass;
    Location myLoc;
   
};