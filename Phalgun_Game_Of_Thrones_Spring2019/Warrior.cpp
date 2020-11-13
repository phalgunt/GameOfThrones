#include <string>

#include "Warrior.h"

using namespace std;

//establishes the qualities of the warrior
// <Name>,<strength>,<loyalty>,<morale>,<free>,<ship>,<has_dragonglass>
Warrior::Warrior(string sName, int iStrength,int iLoyal, int iMorale)
{
     WarriorName = sName;
     strength = iStrength;
     loyalty = iLoyal;
     morale = iMorale;
   
}
string Warrior::getWarriorName()
{
    return WarriorName;
}

void Warrior::setWarriorName(string sName)
{
    WarriorName = sName;
}
int Warrior::getMorale()
{
    return morale;
}
void Warrior::setMorale(int iMorale)
{
    morale = iMorale;
}
void Warrior::setStrength(int iStrength)
{
    strength = iStrength;
}
int Warrior::getStrength()
{
    return strength;
}
int Warrior::getLoyalty()
{
    return loyalty;
}
void Warrior::setLoyalty(int iLoyalty)
{
    loyalty = iLoyalty;
}
string Warrior::getHeroName()
{
    return HeroName;
}
void Warrior::setHeroName(string sName)
{
     HeroName = sName;
}

bool Warrior::getIsFree()
{
    return isFree;
}
void Warrior::setIsFree(bool bFree)
{
    isFree = bFree;
}

bool Warrior::getHasShip()
{
    return hasShip;
}
void Warrior::setHasShip(bool bBol)
{
    hasShip = bBol;
}

bool Warrior::getHasDragonGlass()
{
    return hasDragonGlass;
}
void Warrior::setHasDragonGlass(bool bBol)
{
    hasDragonGlass = bBol;
}
 void Warrior::setWarriorLocation(Location loc)
 {
     myLoc = loc;
 }
Location Warrior::getWarriorLocation()
{
    return myLoc;
}
 