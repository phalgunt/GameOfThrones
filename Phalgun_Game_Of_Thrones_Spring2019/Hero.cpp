#include <string>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include "Hero.h"
using namespace std;
/*
This is the hero class, in which the function of the hero and its objects, and methods will be stated here
Throughout the game, the hero undergoes significant amount of changes, both the main and the other ones which include the gaining and losing of points
The primary characteristics of the hero includes the carrying of the warriors, along with influence money, and the size of the army
and each of it will be essential in providing the values while the heros are engaged in battle. 
*/

    Hero::Hero(string sName, int iMoney, int iInfluence, int iArmySize )
    {
      HeroName = sName;
      money = iMoney;
      influence = iInfluence;
      ArmySize = iArmySize;
   
    }
    string Hero::getHeroName()//provides name for the hero at a certain index in the vector
    {
        return HeroName;
    }
    void Hero::setHeroName(string sName)//initially establishes the hero's name
    {
        HeroName = sName;
    }
    
    
    //the getters and setters for money, influence, and ArmySize all depict the values established and would be established based on the variables in the default constructor which have been assigned to the objects of hero class
    int Hero::getMoney()
    {
        return money;
    }
    void Hero::setMoney(int iMoney)
    {
        money = iMoney;
    }
    
    int Hero::getArmySize()
    {
        return ArmySize;
    }
    void Hero::setArmySize(int iSize)
    {
        ArmySize = iSize;
    }
    
    int Hero::getInfluence()
    {
        return influence;
    }
    void Hero::setInfluence(int iInf)
    {
        influence = iInf;
    }
   
    int Hero::getPoints()
    {
        return points;
    }
    void Hero::setPoints(int iPoints)
    {
        points = iPoints;
    }
    
    void Hero::setIsShip(bool bBol)
    {
        isShip = bBol;
    }
    bool Hero::getIsShip()//used when they land on water tiles
    {
        if(isShip == true)
          return true;
        
        return false;  
    }
    
    void Hero::setWarrior(Warrior war)
    {
        if(myWarriors.size() >= 4)
           myWarriors.at(4) = war;
         else  
           myWarriors.push_back(war);
    }
    
    void Hero::setStartingLocation(Location loc)
    {
        myLocation = loc;
    }
    
    int Hero::getPowerScore()
    {
        return PowerScore;
    }
    void Hero::setPowerScore(int iScore)
    {
         PowerScore = iScore;
    }
    Location Hero::getMyLocation()
    {
         return myLocation;
     }
    void Hero::setMyLocation(Location loc)
    {
        myLocation = loc;
    }
    bool Hero::setWariorsStrength(int iStrength)
    {
      
       if(myWarriors.size() > 0)
       {
           for(int i=0; i<myWarriors.size(); i++)
           {
              int iStr = myWarriors.at(i).getStrength();
               iStr = iStr + iStrength;
              if (iStr > 200) // Strength cant exceed 200;
                  iStr = iStr;
               myWarriors.at(i).setStrength(iStr);
             
           }
           return true;
       }
       return false;
    }
     bool Hero::setWariorsMorale(int iMorale)
    {
       
       if(myWarriors.size() > 0)
       {
           for(int i=0; i<myWarriors.size(); i++)
           {
              int iStr = myWarriors.at(i).getMorale();
               iStr = iStr + iMorale;
              if (iStr > 100) // Morale cant exceed 100;
                  iStr = iStr;
               myWarriors.at(i).setMorale( iStr);
           }
           return true;
       }
       return false;
    }
   
     bool  Hero::setWarriorsLoyality(int iStrength)
    {
         if(myWarriors.size() > 0)
         {
           for(int i=0; i<myWarriors.size(); i++)
           {
              int iStr = myWarriors.at(i).getLoyalty();
              iStr = iStr + iStrength;
              if (iStr > 100) // Loyality cant exceed 100;
                  iStr = iStr;
               myWarriors.at(i).setLoyalty( iStr);
           }
           return true;
       }
       return false;
    } 
     
     bool Hero::setIsMainHero(bool bol)
     {
         isMainHero = bol;
     }
    bool Hero::getIsMainHero()
    {
        return isMainHero;
    }
    Warrior Hero::getFirstWarrior()//battle used
    {
        if(myWarriors.size() > 0)
           return myWarriors.at(0);
    }
      Warrior Hero::getWarriorAtIndex(int i)
    {
        return myWarriors.at(i);//index for the warriors
    }
     void Hero::addMoney(int i)
     {
         money = money + i;
     }
   void Hero::addInfluence(int i)
   {
       influence = influence + i;
   }
   void Hero::addArmySize(int i)
   {
       ArmySize = ArmySize + i;
   }
   
   vector<Warrior> Hero::getAllWarriors()//provides all of the warriors within that vector
   {
       return myWarriors;
   }
    int Hero::getWarriorsSize()
    {
       return myWarriors.size();
    }
    void Hero::addWarrirorToList(Warrior war)
    {
        myWarriors.push_back(war);
    }
    //the followinf determine the outcome
     bool Hero::getIsRetired()
     {
         return isRetired;
     }
    void Hero::setIsRetired(bool bol)
    {
        isRetired = bol;
    }
     bool Hero::getIsLostGame()
     {
         return isLost;
     }
    void Hero::setIsLostGame(bool bol)
    {
        isLost = bol;
    }
    bool Hero::getIsWonGame()
     {
         return isWon;
     }
    void Hero::setIsWonGame(bool bol)
    {
        isWon = bol;
    }
   bool Hero::makeWarriorsFree()
   {
       if(myWarriors.size() > 0)
         {
           for(int i=0; i<myWarriors.size(); i++)
           {
              myWarriors.at(i).setIsFree(true);
            }
           return true;
       }
       return false;
   }
  void Hero::removeWarrirorFmList(string wName)//removes warrior
  {
      for(int i=0; i<myWarriors.size(); i++)
      {
        string name =  myWarriors.at(i).getWarriorName();
         if(name == wName)
         {
             myWarriors.erase(myWarriors.begin() + i);
         }
      }
  }