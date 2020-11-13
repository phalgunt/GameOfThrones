#include <string>
#include "City.h"

using namespace std;
//determines the city name, and the function and benefits offered at each city 

   City::City(string leter)
   {
       CityLeter = leter;
   }
   void City::setCityLeter(string leter)
   {
     CityLeter = leter;
    }
    string City::getCityLeter()
    {
        return CityLeter;
    }
    void City::setCityName(string name)//depicts the name of the city
    {
        CityName = name;
    }
    string City::getCityName()//enables the recieving of the name of the city
    {
        return CityName;
    }
     
    void City::setMoney(int iMoney)//the money which is presented for the hero when they land on this particular spot
    {
        Money = iMoney;
    }
    int City::getMoney()
    {
        return Money;
    }
     
    void City::setArmySize(int size)
    {
        ArmySize = size;
    }
    int City::getArmySize()
    {
        return ArmySize;
    }
       
    void City::setPoints(int iPoints)
    {
        Points = iPoints;
    }
    int City::getPoints()//gets the certain number of points when the hero lands on a particular city
    {
        return Points;
    }