#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include "Game.h"
#include <string>
using namespace std;


// User selection on Heros
int selectOptions()
{
 float option; 
 bool isTrue = true;
  while(isTrue)
  {
   cout << "Select a numerical option:" << endl;
  
    cin >> option;
    cin.clear();
  
    if(option <1 || option - floor(option) != 0)//states the bounds of the allowed input value
    {
     cout << "invalid input" << endl;
     cout << "  " << endl;     
    // exit(0);
    }else
      isTrue = false;
    
   }
 return int(option);    
}

Game loadGame(Game game1)
{
   int noTiles = game1.loadMap("mapGOT.txt");
//   cout << "No of Tiles loaded = " << noTiles << endl;
   
   int noCities = game1.loadCities("citiesGOT.txt");
//   cout << "No of cities loaded = " << noCities << endl;
   
   int noWar = game1.loadWarriors("warriorsGOT.txt");
//   cout << "No of Warriors loaded = " << noWar << endl;
   
   int noHeros = game1.loadHeros("heroesGOT.txt");
//   cout << "No of Heros loaded = " << noHeros << endl;
   
//   cout << "Displaying Whole Map "  << endl;
//   game1.displayMap();
   cout << " "  << endl;

  return game1;
}

Hero mainHeroMoves(Game g1, Hero h1)
{
     Utility util;
     while(true)
     {
          cout << "Select the following options. " << endl;  
          cout << " " << endl;   
          cout << "1. Travel " << endl;   
          cout << "2. Rest " << endl;   
          cout << "3. Consult with the gods " << endl;   
          int opt = util.selectMyOptionsMax(3);
          if(opt == 1)
          {
             h1 =  g1.userTravelMove(g1, h1);
             return h1;
          }
          else if(opt == 2)//rest
          {
                bool isVal = h1.setWariorsStrength(1);   
                 if(isVal)
                   cout << "Each warrior in the hero’s party increases their strength by 1" << endl;
                 else
                   cout << "No warrior found in the hero’s party to increases their strength by 1" << endl;
              return h1;
          }
          else if(opt == 3)
          {
             bool isVal = h1.setWariorsMorale(1);   
              if(isVal)
                 cout << "Each warrior in the hero’s party increases their strength by 1" << endl;
               else
                 cout << "No warrior found in the hero’s party to increases their strength by 1" << endl;
              
              return h1;
          }
     }// while
 return h1; 
}
// Randon Event
Hero randomEvent(Hero MainHero)
{
    Utility util;
    
    util.printDebug("randomEvent 1 ");
    int opt = util.randomNum(1,4); // Getting Random rumber.
    util.printDebug("randomEvent 2 ");
    
    if(opt == 1) // Drought
    {
        // morale and strength of each of the warriors associated with the main hero (theuser) decrease by 10.
        cout << "Drought " << endl;
       util.printDebug("randomEvent 3 ");
       MainHero.setWariorsMorale(-10); 
       MainHero.setWariorsStrength(-10);
      
       
       return MainHero;
    }
    else if(opt == 2) // Deserters
    {
        cout << "Deserters " << endl;
        util.printDebug("randomEvent 4 ");
        // Army size for the main hero (the user) goes down by 10. 
        // loyalty for each the warriors associated with the main hero (the user) goes down by 10.
        
        int mArmy = MainHero.getArmySize();
        mArmy = mArmy - 10;
        if(mArmy < 0)
          mArmy = 0;
          MainHero.setArmySize(mArmy);
          
        MainHero.setWarriorsLoyality(-10);  
        
        return MainHero;
    }
    else if(opt == 3) // Jackpot
    {
        cout << "Jackpot " << endl;
        util.printDebug("randomEvent 5 ");
        // The main hero’s money value will double
        
       int mMoney = MainHero.getMoney();
         util.printDebug("randomEvent 6 ");
       MainHero.setMoney(mMoney * 2);
          util.printDebug("randomEvent 7 ");
         return MainHero;  
    }
    else if(opt == 4) // Kindness
    {
        cout << "Kindness " << endl;
         util.printDebug("randomEvent 8 ");
            //  th army size for the main hero (the user) goes up by 10.
            // the loyalty of each the warriors associated with the main hero (the user) increasesby 10.
        int mArmy = MainHero.getArmySize(); 
        MainHero.setArmySize(mArmy + 10);
            
        MainHero.setWarriorsLoyality(10);
        return MainHero;
    }
}


int main()//test cases
{
    Utility util;
     Game game1;    
     game1 = loadGame(game1); // loading all txt files.

     cout << "Welcome to the G A M E of T H R O N E S! " << endl;
     cout << " " << endl;
     
     Hero MainHero = game1.playerSelectMainHero(game1); // User selecting the Hero 
     game1.setMainHeroToList(MainHero);
     cout << " " << endl;
     game1.printHeros();
      cout << " " << endl; 
     cout << "Let's Play the Game Now .."  << endl; 
    
     game1.displayUserMap(MainHero.getMyLocation()); // User Specific MAP
     
     cout << "Fear Cuts Deeper Than Swords."<< endl; 
     cout << " " << endl;
    int count = 1;
   
    while(true) // Hero and non-Hero's continue turns until game over.
    {
         cout << " " <<endl; 
         cout << "ROUND.."  << count <<endl; 
          cout << " " <<endl; 
         cout << "Main Hero move .."  << endl; 
         
         MainHero = mainHeroMoves(game1, MainHero); // Main Hero Moves.
         cout << "Displaying new location map.."  << endl; 
         cout << " " << endl;
         
         game1.displayUserMap(MainHero.getMyLocation());
         cout << " " << endl;
         game1.printHeros();
         
         cout << "Non-Hero move .."  << endl;     
         game1 = game1.nonMainHeroMoves(game1);  // NonMain Hero Moves.
          
         cout << "One Round completed .. " << endl;
         cout << "Enter For Next Round .. " << endl;
         cout << " " << endl;
         cout <<" A Lannister Always Pays His Debts."  << endl;
         
         string EncHero = game1.anyHeroEncounterWithMainHero(MainHero);
         
         if(EncHero != "")
         {
            cout <<" Encounter Hero is "  << EncHero <<  endl;
            MainHero = game1.encounterWithHero(MainHero, EncHero); // Main Hero encountering with other Hero.
             cout <<" Encounter Ends.." <<  endl;
            
         }else{
             cout <<" No Encounter Occured "  << EncHero <<  endl;
         }  
          cout <<" playDriver 1.." <<  endl;
         if(MainHero.getIsLostGame() == true)
              break;
          cout <<" playDriver 2.." <<  endl;          
         if(MainHero.getIsWonGame() == true)
              break;     
         if(count % 3 == 0 ) // Winter Is Coming, every 3rd round this event occurs.
         {
            util.printDebug("Winter Is Coming 1 ");
            MainHero = randomEvent(MainHero);
         }
            
         if(count == 10) // evevry 10th rounds pre-condition event
         {
            util.printDebug(" In count == 10"); 
            game1.preConditionedEvent();
         }
           
          util.printDebug(" end of turn ..");   

        count += 1;
        
      //  util.continueOption();
      
    }// while  
    
    return 0;
}