#include <string>
#include <vector>
//#include "Location.h"
#include "Warrior.h"

using namespace std;

class Hero
{
    //determines the army 
    public:
    Hero()
    {
        HeroName = "";
    };
    Hero(string name, int money, int influence, int ArmySize);
    string getHeroName();
    void setHeroName(string sName);
    
    int getMoney();
    void setMoney(int iMoney);
    
    int getArmySize();
    void setArmySize(int iSize);
    
    int getInfluence();
    void setInfluence(int iInf);
   
    int getPoints();
    void setPoints(int iPoints);
    
    void setIsShip(bool bBol);
    bool getIsShip();
    
   
    
    void setWarrior(Warrior war);
    
    void setStartingLocation(Location loc);//will use a location object of location as a paremeter
    Location getMyLocation();
    void setMyLocation(Location loc);
    
    //The warrior is used in order to determine the outcome of the battles, and it is used to gain many of the hero's qualities as well
    string getWarriorNames();
    int getPowerScore();
    void setPowerScore(int iScore);
    bool setWariorsStrength(int i);
    bool setWariorsMorale(int i);
    bool setIsMainHero(bool bol);
    
    bool getIsMainHero();//gets its particular hero
    Warrior getFirstWarrior();
    Warrior getWarriorAtIndex(int i);//index at which the warrior is found amongst the hero
    void addMoney(int i);
    void addInfluence(int i);
    void addArmySize(int i);
    vector<Warrior> getAllWarriors();//accesses the warriors vector via the object made through warriors
    int getWarriorsSize();
    void addWarrirorToList(Warrior w);
    void removeWarrirorFmList(string wName);
    bool getIsRetired();
    void setIsRetired(bool bol);//determines if the enemy hero has been retired
    bool getIsLostGame();
    void setIsLostGame(bool bol);//determines if the game has been lost
    bool getIsWonGame();
    void setIsWonGame(bool bol);
    bool setWarriorsLoyality(int i);
    bool makeWarriorsFree();

    private:
    //private classes which depict the hero qualities which will have an impact on the function of the warrior
    //boolean is used in order to change these conditions to true when necessary, or in other words, when they are used
   // <Name>,<$>,<influence>,<army_size>,<w1>,<w2>,<w3>,<w4>,<r>,<c>,<ship>
    string HeroName;
    int PowerScore;
    int money;
    int influence;
    int ArmySize;
    int points;
    bool isShip = false;
    bool isMainHero = false;
    bool isFree = false;
    bool isRetired = false;
    bool isLost = false;
    bool isWon = false;
    Location myLocation;
    vector<Warrior> myWarriors;
};