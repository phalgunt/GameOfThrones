#include <string>

using namespace std;

class City
{
    public:
  
    City();
    City(string leter);
    void setCityLeter(string leter);
    string getCityLeter();
    
    void setCityName(string name);
    string getCityName();
     
    void setMoney(int money);//analyzes the money it provides
    int getMoney();
     
    void setArmySize(int size);//analyzes the army size it provides
    int getArmySize();
       
    void setPoints(int points);//analyzes the points it provides
    int getPoints();
    
    
//variables of heros
    private:
    string CityLeter;
    string CityName;
    int Money;
    int ArmySize;
    int Points;
  


};