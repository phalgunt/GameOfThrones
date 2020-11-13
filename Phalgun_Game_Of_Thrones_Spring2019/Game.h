#include <string>
#include <vector>
// #include "Location.h"
// #include "Warrior.h"
#include "Hero.h"
#include "City.h"
#include "Utility.h"

using namespace std;

class Game
{
   
   public:
   Game(){
   gameName = "Game1";
   };
   Game(string sName);
   int loadMap(string sFileName);
   int loadCities(string sFileName);
   int loadWarriors(string sFileName);
   int loadHeros(string sFileName);
   int printHeros();
   int getCityIndex(string CityLetter);
   int getWarriorIndex(string WarriorName);
   int getHeroIndex(string HeroName);
   bool checkHeroLocExists(Location loc);
   void displayUserMap(Location loc);
   bool isLocationExists(int row, int col);
   Hero userTravelMove(Game g1, Hero h1);
   Hero playerSelectMainHero(Game game1);
   Hero createOwnHero(Game game1, string pName);
   bool setMainHeroAtIndex(int i);
   Game nonMainHeroMoves(Game g1);
   void setMainHeroToList(Hero MainHero);
   Warrior freeWarriorTravelMove(Game g1, Warrior w1);
   Location getRandomLocation(int row, bool isWater);
   string anyHeroEncounterWithMainHero(Hero MainHero);
   Hero encounterWithHero(Hero MainHero, string EncHero);
   Hero getHeroFromList(string EncHero);
   Warrior getWarriorWithName(string WarriorName);
   Hero heroWinsAddPower(Hero MainHero, Hero eHero);
   void preConditionedEvent();
   void romoveWarriorFromGame(string warrirorName);
  
   
   
   void displayMap();
   Location getLocationIndex(int row, int col);
   Hero getHeroAtIndex(int i);
   
   private:
   string gameName;
   vector<Location> locations;
   vector<City> cities;
   vector<Warrior> warriors;
   vector<Hero> heros;
   
    
    
    
    
};