#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include "Game.h"
using namespace std;
/*
The location in which a vast majority of the game's actual function will be written in
    - this includes the beginning when the hero is asked to play the game
    - whether or not he/she would like to choose their own hero or create a new one
    - ask the user the specific directions they want to go
        - provide warriors with the specific necessities to go on certain tiles only
        - ie provide them with ships when they are on water tiles
    - display the map with the specific 
*/

Game::Game(string sName)
{
    gameName = sName;
}

//provides the map for the user, as this is used to get the type of tiles which are being used 
int Game::loadMap(string sFileName)
{
    cout << "Loading the Map from text file.. " << endl;
    Utility util;
    ifstream file (sFileName);
     int count =0;
     if(file.is_open())
     {
        string line = "";
        int row =1;
         count =1;
        while(getline(file,line))
        {
           if(line == "")
           continue;
          string sWords[16];
          util.split( line, ',', sWords);
          for(int i=0; i<16; i++)
          {
              string title = sWords[i];
              Location loc(row, i+1);
              loc.setTileMark(sWords[i]);
              if(title == "w")
                loc.setIsWaterTile(true);
              else 
                loc.setIsLandTile(true);
              
              loc.setTileNo(count);    
              locations.push_back(loc);
              
              count += 1;
          }
          row += 1;
          }
        return count-1;
     }
     else
       return -2;
    
}
// Displaying Whole Map
void Game::displayMap()
{
 //  cout << locations.size() << endl;
   int count =0;
   for(int i=0; i<25; i++)
   {
       for(int j=0; j<16; j++)
       {
           Location loc = locations.at(count);
           cout << loc.getTileMark() << " ";
           count += 1;
       }
      cout  << endl;
   }
}

// Displaying User Spesifc 7 * 7 size Map
void Game::displayUserMap(Location loc)
{
 //  cout << locations.size() << endl;
   int uRow = loc.getRow();
   int uCol = loc.getColumn();
   for(int i= uRow-3; i<uRow+4; i++)
   {
       for(int j=uCol-3; j<uCol+4; j++)
       {
           if(i <= 0 || j <= 0)
           {
                cout <<  "[ # ]";
           }
            else{
                 Location loc = getLocationIndex(i, j);
                 if((i == uRow ) && (j == uCol) )
                   cout <<"[[" << loc.getDisplayTileMark() << "]]";
                   else
                     cout <<"[ " << loc.getDisplayTileMark() << " ]";
            }  
       }
      cout  << endl;
   }
}

Location Game::getLocationIndex(int row, int col)
{
    int index = ((row - 1) * 16) + col;
    Location loc =  locations.at(index-1);
    return loc;
}

// find a randon Tile
Location Game::getRandomLocation(int row, bool isWater)
{
      Utility util;
      Location loc;
    int col = util.randomNum(1,15);
    int index = ((row - 1) * 16) + col;
    if(isWater)
    {
        while(true)
        {
          loc =  locations.at(index-1);
         if(loc.getIsWaterTile())
            return loc;
          
          index=index+1; 
          
          if(index == 400)
             index = 1; 
        }
    }
    else
       loc =  locations.at(index-1);
    
    return loc;
}
// checking if the row-col exists in the board.
bool Game::isLocationExists(int row, int col)
{
    if((row > 0 && row <= 25) && (col > 0 && col <=16))
    {
        return true;
    }
    else 
      return false;
}

int Game::loadCities(string sFileName)
{
     cout << "Loading the Cities from text file.. " << endl;
    Utility util;
    ifstream file (sFileName);
    
     if(file.is_open())//reading the file
     {
        string line = "";
       int count =0;
        while(getline(file,line))
        {
           if(line == "")
           continue;
          string sWords[5];
          util.split( line, ',', sWords);
        //following will be based on the vector for the Hero derived from the .txt file and assigning it to the City
          City city(sWords[0]);
          city.setCityName(sWords[1]);//name is the second in the vector
          city.setMoney(stoi(sWords[2]));//money is the third in the vector
          city.setArmySize(stoi(sWords[3]));//ArmySize is the 4th in the vector
          city.setPoints(stoi(sWords[4]));//Points is the 5th in the vector
          cities.push_back(city);
   
         count += 1;
        }
      return  count;  
     }
     else
     {
      return -2;
     }
    
}

int Game::getCityIndex(string CityLetter)
{
    int size = cities.size();
  
    for(int i=0; i< size; i++)
    {
       string let = cities.at(i).getCityLeter();//provides the city 
       if(let == CityLetter)
          return i;
          
       return -2;      
    }
}
int Game::loadWarriors(string sFileName)
{
    cout << "Loading Warriors from txt file" << endl;
     Utility util;
    ifstream file (sFileName);
    
     if(file.is_open())
     {
        string line = "";
       int count =0;
        while(getline(file,line))
        {
           if(line == "")
           continue;
          string sWords[7];//total number witin the sWords array which procides the warrior and the "qualities"(variables) which define them
          util.split( line, ',', sWords);
        //  <Name>,<strength>,<loyalty>,<morale>,<free>,<ship>,<has_dragonglass>
          Warrior warrior(sWords[0], stoi(sWords[1]), stoi(sWords[2]), stoi(sWords[3]));//creating an instance of the warrior
          string sFree = sWords[4];
          if(sFree == "yes")//boolean
             warrior.setIsFree(true);//warrior is free
             else
               warrior.setIsFree(false);
               
          string sShip = sWords[5];
           if(sShip == "yes")
             warrior.setHasShip(true);//warrior gets the ship to go on the water locations
             else
               warrior.setHasShip(false);
           
          string sDrag = sWords[6];
           if(sDrag == "yes")
            warrior.setHasDragonGlass(true);//dragonGlass initialzied
            else
              warrior.setHasDragonGlass(false);
           
            if((sFree == "yes") && (sShip == "yes"))
            {
               Location loc = getRandomLocation(count+1, true);//ship to a random location
               warrior.setWarriorLocation(loc);
            }
            if((sFree == "yes") && (sShip == "no"))
            {
               Location loc = getRandomLocation(count+2, false);
               warrior.setWarriorLocation(loc);
            }
           
   //        cout << " Warriors Name = " << warrior.getWarriorName() << "," << warrior.getIsFree() << endl; 
           
          warriors.push_back(warrior);//gives the warriors class 
   
         count += 1;
        }
      return  count;  
     }
     else
      return -2;
    
}

int Game::getWarriorIndex(string WarriorName)
{
   // cout << "getWarriorIndex " << endl;
    
    for(int i=0; i< warriors.size(); i++)
     {
        
       if(WarriorName == warriors.at(i).getWarriorName())
        {
    //     cout <<  WarriorName << " Warrior Name macthing.. "<< warriors.at(i).getWarriorName() << endl;
          return i;
        }
     }
     return -2;
}

int Game::getHeroIndex(string heroName)
{

    for(int i=0; i< heros.size(); i++)
     {
        
       if(heroName == heros.at(i).getHeroName())//provides the hero at this particular index
        {
          return i;
        }
     }
     return -2;
}

Warrior Game::getWarriorWithName(string WarriorName)
{
   // cout << "getWarriorIndex " << endl;
   // Warrior war();
    for(int i=0; i< warriors.size(); i++)
     {
        
       if(WarriorName == warriors.at(i).getWarriorName())
        {
     //    cout <<  WarriorName << " Warrior Name macthing.. "<< warriors.at(i).getWarriorName() << endl;
           Warrior war =  warriors.at(i);
            return war;
        }
     }
    
}

//used to determine the 
int Game::loadHeros(string sFileName)
{
    cout << "Loading the Heros from text file.. " << endl;
     Utility util;
    ifstream file (sFileName);
    //opens the file, and proceeds to read the entire file
     if(file.is_open())
     {
        string line = "";
       int count =0;
        while(getline(file,line))
        {
           if(line == "")
           continue;
          string sWords[11];
          util.split( line, ',', sWords);
        // <Name>,<$>,<influence>,<army_size>,<w1>,<w2>,<w3>,<w4>,<r>,<c>,<ship>
        //  Hero::Hero(string sName, int iMoney, int iInfluence, int iArmySize )
          Hero myHero(sWords[0], stoi(sWords[1]), stoi(sWords[2]), stoi(sWords[3])  );
          string w1 = sWords[4];
          int iRow = stoi(sWords[8]);
          int iCol = stoi(sWords[9]);
          Location loc(iRow, iCol);
          if(w1 != "NULL")
          {
             Warrior war = getWarriorWithName(w1);
             war.setHeroName(sWords[0]);
             war.setWarriorLocation(loc);
             myHero.setWarrior(war);
     //          cout << "Hero - w1 Warrior Name : " << war.getWarriorName() << endl;
     //         cout << "Hero - w1 Hero Name : " << war.getHeroName() << endl;
          }
          string w2 = sWords[5];
          if(w2 != "NULL")
          {
             Warrior war = getWarriorWithName(w2);
             war.setHeroName(sWords[0]);
              war.setWarriorLocation(loc);
             myHero.setWarrior(war);
          }
          string w3 = sWords[6];
          if(w3 != "NULL")
          {
             Warrior war = getWarriorWithName(w3);
             war.setHeroName(sWords[0]);
              war.setWarriorLocation(loc);
             myHero.setWarrior(war);
          }
          string w4 = sWords[7];
          if(w4 != "NULL")
          {
             Warrior war = getWarriorWithName(w4);
             war.setHeroName(sWords[0]);
             war.setWarriorLocation(loc);
             myHero.setWarrior(war);
          }
          
         
          myHero.setMyLocation(loc);
          heros.push_back(myHero);
   
         count += 1;
        }
      return  count;  
     }
     else
      return -2;
    
}

int Game::printHeros()
{
    int iSize = heros.size();
    if(iSize > 0)
    {
     cout << "Here are the Heros .." << endl;    
     
      for(int j=0; j< iSize; j++)
      {
          Hero h = heros.at(j);
          cout << j+1 << ". " << h.getHeroName() << endl;
     //    cout << j+1 << ". " << h.getIsMainHero() << endl;
      }
       cout << " " << endl;
    }
    else{
         cout << "No Heros are available in system now. " << endl;
    }
    return iSize;
}

Hero Game::getHeroAtIndex(int i)
{
    Hero h;
    if(heros.size() > 0)
    {
     return heros.at(i);
    }
    return h;
}
bool Game::setMainHeroAtIndex(int i)
{
    
    if(heros.size() > 0)
    {
      heros.at(i).setIsMainHero(true);
       return true;
    }
    return false;
}

// Checking other Heros are starting from this location.
bool Game::checkHeroLocExists(Location loc)
{
    int iSize = heros.size();
  
    if(iSize > 0)
    {
      for(int j=0; j< iSize; j++)
      {
          Hero h = heros.at(j);
          Location loc1 = h.getMyLocation();
          if(loc.getRow() == loc1.getRow())
          {
              if(loc.getColumn() == loc1.getColumn())
                return true;
          }
      }
      return false;
    }
    else{
       return false;
    }
}


// users selects travle move
Hero Game::userTravelMove(Game g1, Hero h1)
{
   // cout << " userTravelMove ..." << endl;   
     Location l1 = h1.getMyLocation();
     Utility util;
     
     bool isMainHero = h1.getIsMainHero();
     bool isShip = h1.getIsShip();
     bool isTravel = true;
     int count = 0;
     while(isTravel)
     {
         count = count + 1;
      //    cout << "count =" << count << endl; 
          if(count == 4)
          {
             isTravel = false;
             continue;
          }
        
         int row = l1.getRow();
         int col = l1.getColumn(); 
     //    cout << "row-col : " << row << " : "<< col << endl;
         int opt;
         
         if(isMainHero == true)
         {
             cout << "Please select travel direction.. " << endl;   
             cout << "1. North " << endl;   
             cout << "2. South " << endl;   
             cout << "3. East " << endl;   
             cout << "4. West " << endl;    
             
             opt = util.selectMyOptions();
         }
         else
         {
             opt = util.randomNum(1,4);
       //      cout << " opt = " << opt << endl;   
         }
          if(opt == 1) // North
          {
             // cout << "You selected North Direction." << endl; 
              row = row -1;
          }
          else if(opt == 2)
          {
              // cout << "You selected South Direction." << endl; 
              row = row +1;
              
          }
          else if(opt == 3)
          {
           //   cout << "You selected East Direction." << endl; 
              col = col +1;
          }
          else if(opt == 4)
          {
           //   cout << "You selected West Direction." << endl; 
              col = col-1;
          }
          
          bool iLoc = g1.isLocationExists(row, col);
          if(iLoc == true)
           {
                 Location l3 =  g1.getLocationIndex(row, col);
                 bool iWater =  l3.getIsWaterTile(); // checking for water tile
                 if(iWater == true)
                 {
                     if(isShip == false)
                     {
                         cout << "You selected water tile and you dont have ship." << endl; 
                         continue;
                     }
                 }
                 h1.setMyLocation(l3);
                 cout << "New location updated." << endl;  
                 return h1; 
              }else{
                  cout << "Out of boundary selection.." << endl; 
             }
          
             
      }//while      
      
      return h1;
}

// users selects travle move
Warrior Game::freeWarriorTravelMove(Game g1, Warrior w1)
{
  //  cout << " Free Warrior Move ..." << endl;   
     Location l1 = w1.getWarriorLocation();
     Utility util;
     
     bool isShip = w1.getHasShip();
     bool isTravel = true;
     int count = 0;
     while(isTravel)
     {
         count = count + 1;
          if(count == 4)
          {
             isTravel = false;
             continue;
          }
        
         int row = l1.getRow();
         int col = l1.getColumn(); 
      //   cout << "row-col : " << row << " : "<< col << endl;
         int opt = util.randomNum(1,4);
    //     cout << " opt = " << opt << endl;   
     
          if(opt == 1) // North
          {
             // cout << "You selected North Direction." << endl; 
              row = row -1;
          }
          else if(opt == 2) //south
          {
            //  cout << "You selected South Direction." << endl; 
              row = row +1;
              
          }
          else if(opt == 3)//east
          {
           //   cout << "You selected East Direction." << endl; 
              col = col +1;
          }
          else if(opt == 4)//west
          {
           //   cout << "You selected West Direction." << endl; 
              col = col-1;
          }
          
          bool iLoc = g1.isLocationExists(row, col); //sets the location based on the rows and columns
          if(iLoc == true)//iLoc is the boolean value
           {
                 Location l3 =  g1.getLocationIndex(row, col);
                 bool iWater =  l3.getIsWaterTile(); // checking for water tile
                 if(iWater == true)
                 {
                     if(isShip == false)
                     {
                         cout << "You selected water tile and you dont have ship." << endl; 
                         continue;
                     }
                 }
                 w1.setWarriorLocation(l3);
                 cout << "New location updated." << endl;  
                 return w1; 
              }else{
                  cout << "Out of boundary selection.." << endl; 
             }
          
             
      }//while      
      
      return w1;
}
/**
 * Non Main Hero Moves, which are Heros and Free warriors.
 * They can move one randomly.
 */ 
Game Game::nonMainHeroMoves(Game g1)
{
   
  for(int i=0; i< heros.size(); i++)
   {
        Hero h1 = g1.heros.at(i);
       if(!h1.getIsMainHero())
       {
          cout << "Updating the Location for Non Main Hero :" << h1.getHeroName()  << endl;  
          
          h1 = userTravelMove(g1, h1);
          g1.heros.at(i) = h1;
       }
   }
   
   // Noe Free warriors move..
   for(int i=0; i< warriors.size(); i++)
   {
       
      Warrior w1 = g1.warriors.at(i);
   
       if(w1.getIsFree() == true)
       {
          cout << "Updating the Location of Free Warior : " << w1.getWarriorName()  << endl;
          w1 = freeWarriorTravelMove(g1, w1);
          g1.warriors.at(i) = w1;
       }
   }
    
 return g1;   
}

Hero Game::playerSelectMainHero(Game game1)//when the hero either selects yes or no, on whether they want to create their own hero or not
{
    //following are mandatory statements which must be asked to the user
    cout << "State your name, Your Grace: " << endl;
    Hero h1;
    Utility util;
     string sName;
     cin >> sName;
     cin.clear();
     cout << "Would you like to choose a hero " << sName << ", Your Grace?(Y/N): " << endl; 
     string option;
     cin>>option; 
    if(option=="Y" || option=="y")//capitilization insensitive
      {
        int iH = game1.printHeros();
        int opt = util.selectMyOptionsMax(iH);
        cout << "opt = " << opt << endl;
        game1.setMainHeroAtIndex(opt-1);
        h1 = game1.getHeroAtIndex(opt-1);
        cout << "You selected Hero : " << h1.getHeroName() << endl;//.getHeroName determines the name of the hero which had been selected and displays it
      }
      else
      {
         h1 = createOwnHero(game1, sName);
        cout << "You created Hero, with Hero Name : " << h1.getHeroName() << endl;
      }
      
      return h1;
}
void Game::setMainHeroToList(Hero MainHero)
{
    string sName = MainHero.getHeroName();
    if(heros.size() > 0)
    {
        for(int i=0; i< heros.size(); i++)//reads the entire vector 
        {
            if(heros.at(i).getHeroName() == sName)
            {
                heros.at(i).setIsMainHero(true);//when "y" is selected 
            }
        }     
   
    }
}

//if the hero selects "n"
Hero Game::createOwnHero(Game game1, string pName)
{
          cout<<"Your Grace, "<<pName<< " you have chosen to go on this journey alone. Please provide starting values for your adventure."<<endl;
          cout<<"Enter the money (0 - 10,000)"<<endl;//range asked
          
          int iMoney;
          cin>>iMoney;
          if(iMoney>10000||iMoney<0)//establishing the range
          {
            cout<<"Re-enter value within the limit"<<endl;
            cin>>iMoney;
          }
          cout<<"Enter the influence (0 - 10,000)"<<endl;
          int iInfluence;
          cin>>iInfluence;
          if(iInfluence>10000||iInfluence<0)//establishing the range
          {
            cout<<"Re-enter value within the limit"<<endl;
            cin>>iInfluence;
          }
          cout<<"Enter the army size (0 - 10,000)"<<endl;//establishing the range
          int iArmySize;
          cin>>iArmySize;
          if(iArmySize>10000||iArmySize<0)
          {
            cout<<"Re-enter value within the limit"<<endl;//user error if they go out of the range
            cin>>iInfluence;
          }
         
          Hero MainHero (pName, iMoney,iInfluence, iArmySize);//inputs
          bool iStLoc = true;
          while(iStLoc)
          {
               cout<<"Enter the location (row and column)"<<endl;
               cout<<"Enter the row (1-25)"<<endl;
               int iRow;
               int iColumn;
               cin>>iRow;
               if(iRow<1||iRow>25)//if the number entered for the 
                {
                    cout<<"Re-enter value within the limit"<<endl;
                    cin>>iRow;    
                }
               cout<<"Enter the column (1-16)"<<endl;//the allowed input for the location when the user first selects and starts the game
               cin>>iColumn;
               if(iColumn<1||iColumn>16)
                {
                    cout<<"Re-enter value within the limit"<<endl;
                    cin>>iColumn;    
                 }
                  
              Location loc (iRow, iColumn);
              bool isExists = game1.checkHeroLocExists(loc);//if location object exists, then the location of the hero will be checked as well
              if(isExists)
              {
                 cout<<"Other Hero also starting from this location, pls re-enter new location."<<endl;//if two heros are at the same location
              }
              else
              {
               iStLoc = false;
                MainHero.setStartingLocation(loc);
              }
           } // while
          
          return MainHero;
}
/**
 * Find out if any other Heros are encountering with Main Hero
 * Return the encountered Hero name.
 */ 
string Game::anyHeroEncounterWithMainHero(Hero MainHero)
{
    Location heroLoc = MainHero.getMyLocation();//identifies the location and the below lines determine the specific row and column
    int iRow = heroLoc.getRow();
    int iCol = heroLoc.getColumn();
    
    std::cout << "Main Heror Location :" <<iRow<<"," << iCol <<  std::endl;//prints location of the encounter
    
    for(int i=0; i< heros.size(); i++)//reads the entire size
    {
        Hero h1 = heros.at(i);//particular hero 
        if(h1.getIsMainHero() == false)
        {
          Location l1 = h1.getMyLocation();
          int r = l1.getRow();
          int c = l1.getColumn();
          
          if((r >= iRow-2) && (r <= iRow+2))//when the column is within two or more tiles of the enemy the row will also do calculate the proximity by going into this statement
          {
              if((c >= iCol-2) && (c <= iCol+2))
              {
               //  std::cout << "Encounter Heror Location :" <<r<<"," << c <<  std::endl; 
                 return h1.getHeroName();
              }
          }
          
        }
    }
    
    
}

Hero Game::getHeroFromList(string EncHero)
{
    for(int i=0; i<heros.size(); i++)
    {
        if(EncHero == heros.at(i).getHeroName())
           return heros.at(i);
    }
}
void dispayWarriors(vector<Warrior> oppWrs)
{
      for(int i=0; i<oppWrs.size(); i++)
      {
        cout << i+1 <<". " <<  oppWrs.at(i).getWarriorName()  << endl; 
      } 
}
Hero Game::heroWinsAddPower(Hero MainHero, Hero eHero)
{
    Utility util;
    //gets the values of each hero, which are the 'essentials' for the non main hero 
         int iMoney = eHero.getMoney();
         int iInfl  = eHero.getInfluence();
         int iArmy  = eHero.getArmySize();
       
       //main hero, whos values are already given and had been retrieved from the .txt file  
         MainHero.addMoney(iMoney); 
         MainHero.addInfluence(iInfl);
         MainHero.addArmySize(iArmy);
         
         vector<Warrior> oppWrs = eHero.getAllWarriors();//object from the warrior object and is assinged to the eHero(enemy hero) in order to determine all of the warriors which are present for the opposing hero 
         
         int mWrSize = MainHero.getWarriorsSize();
         int eWrSize = eHero.getWarriorsSize();
       
         string option;
         if((mWrSize + eWrSize) > 4)
         {
             int ct = 4 - (mWrSize + eWrSize);
             cout << "Please pick any " << ct << " warriors you want to add, so you won't exceed 4" << endl;
             cout << "Enter like : 1,2 pick " << endl;
         
             dispayWarriors(oppWrs);
           
             cin>>option;
              cout << "You selected : " << option << endl;
            string str[4];
            int nos = util.split(option, ',', str);//split function used in order to 
            for(int i=0; i< nos; i++)
            {
                int j = stoi(str[i]);
               Warrior w3 = oppWrs.at(j-1);
               MainHero.addWarrirorToList(w3);
            }
         }
         else
         {
              for(int i=0; i<oppWrs.size(); i++)
              {
                Warrior w3 = oppWrs.at(i);
                MainHero.addWarrirorToList(w3);
              } 
         }
   
     return MainHero;    
}
//there are three options present to the main hero when there are 
Hero Game::encounterWithHero(Hero MainHero, string EncHero)
{
    Utility util;
    //show encounter options
    util.showEncounterOptions();
    int opt = util.selectMyOptionsMax(3);
    
    Hero eHero = getHeroFromList(EncHero);
    if(opt == 1) // Give a speech
    {
          int wMorale =0;
          int wsize = eHero.getWarriorsSize();
          if(wsize > 0)
          {
            Warrior w1 =  eHero.getFirstWarrior();//when engaged in battle for this particular case, the first warrior is being compared
             wMorale  = w1.getMorale();
           }
            int mHrInf = MainHero.getInfluence();
            double probVal = (1- (wMorale/100))* (mHrInf/1600);
          if(probVal <= 0)//conditioning for the main hero losing
          {
              std::cout << "Main Hero loses the battle, the encounter ends." << std::endl;
              //the encounter ends, the main hero escapes, but the main hero loses half their influence value
             int mInf =  MainHero.getInfluence();
             util.printDebug("Give a speech 1 ");
             MainHero.setInfluence(mInf/2);
             util.printDebug("Give a speech 2 ");
             return MainHero;
              
          }
          else if(probVal == 1)//condition for main hero winning
          {
              std::cout << "Main Hero WINs the battle" << std::endl;
              std::cout << EncHero << " has retired." << std::endl;
              eHero.setIsRetired(true);
               MainHero = heroWinsAddPower(MainHero,  eHero); 
              return MainHero;
            
          }
  
    }// option 1 end
    else if(opt == 2) //Buy them out right
    {
         util.printDebug("Buy them out right 1 ");
        //initializing the points for the values 
        int wLoyal =0;
        int mMoney =0;
        int wsize = eHero.getWarriorsSize();
        if(wsize > 0)
          {
            Warrior w1 =  eHero.getFirstWarrior();//when engaged in battle for this particular case, the first warrior is being compared
            wLoyal  = w1.getLoyalty();//identifies the Loyalty value for the particular warrior
            mMoney = MainHero.getMoney();//identifies the money for the particular hero
           }

          double probVal = (1- (wLoyal/100))* (mMoney/17800);//calculating the probability for the victory of the main hero against the enemy hero
     util.printDebug("Buy them out right 2 ");
          if(probVal <= 0)
          {
               util.printDebug("Buy them out right 2 ");
              std::cout << "Main Hero loses the battle, the encounter ends." << std::endl;
              //the encounter ends, the main hero escapes, but the main hero loses half their influence value
             int mInf =  MainHero.getMoney();
             
             MainHero.setMoney(mInf/2);
              util.printDebug("Buy them out right 3 ");
             return MainHero;
              
          }
          else if(probVal == 1)
          {
               util.printDebug("Buy them out right 4 ");
              std::cout << "Main Hero WINs the battle" << std::endl;
              std::cout << EncHero << " has retired." << std::endl;
              eHero.setIsRetired(true);
              MainHero = heroWinsAddPower(MainHero, eHero); 
               util.printDebug("Buy them out right 5 ");
              return MainHero;
             
          }
       }
       else if(opt == 3) //Battle condition
       {
            util.printDebug("Battle condition 1 ");
            int mNoWars = MainHero.getWarriorsSize();
            int eNoWars = eHero.getWarriorsSize();
            if((mNoWars == 0) && (eNoWars >0))//enemy number of warriors is greater than 0 and the main hero has warriors which are equal to 0(none)
            {
                cout << "Main Hero lost the battle." << endl;
                return MainHero;
            }
            else if((eNoWars == 0) && (mNoWars >0))//enemy has none while main hero has some number of warriors(opposite of the last one)
            {
                
                cout << "Enemy Hero lost the battle." << endl;
                return MainHero;
            }
            util.printDebug("Battle condition 2 ");
          // selecting Warrirors for battle filed for Main Hero.
            Warrior mBattleWar = MainHero.getWarriorAtIndex(0);
            if(mNoWars > 1)
            {
               vector<Warrior> mWrs = MainHero.getAllWarriors();//getting the warriors from the object
               
                 cout << "Please pick any warriors for battle field." << endl;//occurs when the hero can not acqure all of the enemy hero's warriors once he wins the game
                 dispayWarriors(mWrs);
                 int opt = util.selectMyOptionsMax(mNoWars);
                 mBattleWar = MainHero.getWarriorAtIndex(opt-1);
            }
            else{
                mBattleWar = MainHero.getWarriorAtIndex(0);
            }
              util.printDebug("Battle condition 3 ");
             // selecting Warriroe for battle filed for Opposition Hero.
            Warrior eBattleWar = eHero.getWarriorAtIndex(0);
            if(eNoWars > 1)
            {
               vector<Warrior> eWrs = eHero.getAllWarriors();
               
                 cout << "Please pick any warriors for battle field." << endl;
                 dispayWarriors(eWrs);
                 int opt = util.selectMyOptionsMax(eNoWars);
                 eBattleWar = eHero.getWarriorAtIndex(opt-1);
            }
            else{
                eBattleWar = eHero.getWarriorAtIndex(0);
            }
            
            //The hero with the highest value for (army size) * (strength of chosen warrior) wins the encounter
              util.printDebug("Battle condition 4 ");
            int mValue = (MainHero.getArmySize() * mBattleWar.getStrength());
             int eValue = (eHero.getArmySize() * eBattleWar.getStrength());
             
             if(mValue >= eValue)
             {
                 std::cout << "Main Hero WINs the battle." << std::endl;
                MainHero = heroWinsAddPower(MainHero,  eHero) ;
                return MainHero;
             }
             else
             {
                  std::cout << "Main Hero LOST the battle." << std::endl;
                   std::cout << "THE GAME END!!." << std::endl;
                   MainHero.setIsLostGame(true);
                   return MainHero;
             }
    }
    
}
//removes certain warriors from the game (free roaming)
void Game::romoveWarriorFromGame(string warrirorName)
{
    int index = getWarriorIndex(warrirorName);//gets the index of the warrior name in order to identify which one is to be removed
        warriors.erase(warriors.begin() + index);
}
//these include the conditions and certain assignments of some warriors to other heros after the stated conditions are met
void Game::preConditionedEvent()
{
    Utility util;
       util.printDebug(" in preConditionedEvent ");
     
        // Condition 1
        cout << "Condition 1" << endl;
        int i =getHeroIndex("Daenerys Targaryen");
        cout << "i = .."  << i <<endl; 
        Hero Daenerys = heros.at(i);//gives the index of Daenerys
        Daenerys.addArmySize(5000); // updating Army size by 5000
       
        int size = Daenerys.getWarriorsSize();
         // created new special warrior
         
         if(size >= 4)
         {
             Warrior devoured =  Daenerys.getWarriorAtIndex(3);
             Warrior dragon("Dragons",198,110,88);//dragon object being assigned the specific traits for the warriors
             romoveWarriorFromGame(devoured.getWarriorName());   //Remove the devoured warrior from the game.
             Daenerys.setWarrior(dragon);
         }
         else
         {
              Warrior dragon("Dragons",180,100,80);
              Daenerys.setWarrior(dragon);
         }
      
         heros.at(i) =  Daenerys;
         
         // condition 2
         
          cout << "Condition 2" << endl;
         
         i =getHeroIndex("Stannis Baratheon");
        cout << "i = .."  << i <<endl; 
        Hero Stannis = heros.at(i);
        cout << "Hero Name = .."  << Stannis.getHeroName() <<endl;  
        Stannis.makeWarriorsFree(); // All warriros for this Hero are free
        util.palyerRetired("Stannis");
        
        //condition 3
         cout << "Condition 3" << endl;
         i =getHeroIndex("Sansa Stark");
         Hero Sansa = heros.at(i);
        
         Warrior Arya = getWarriorWithName("Arya Stark");
         Arya.setHeroName("Sansa Stark");
         Arya.setIsFree(false);
         Sansa.setWarrior(Arya);
         
         //condition 4
         cout << "Condition 4" << endl;
          i =getHeroIndex("Cersei Lannister");
          Hero Cersei = heros.at(i);
          Cersei.removeWarrirorFmList("Jaime Lannister");
        
}