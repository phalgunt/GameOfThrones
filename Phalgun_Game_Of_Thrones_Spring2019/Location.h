#include <string>

using namespace std;

class Location
{
    public:
   // addNewHero();
    Location()//initializing the location
    {
       row = 0; 
       column =0;
    };
    //identifies the location based on the tile
    Location(int row, int column);
    void setRow(int iRow);
    int getRow();
     void setColumn(int iRow);
    int getColumn();
    void setTileNo(int iNo);
    int getTileNo();
    
    //this gets and city names along with the markings of the tile
    void setTileMark(string sMark);
    string getTileMark();
    string getDisplayTileMark();
    string getCityName();
    void setCityName(string sName);
    
    //getters and setters which simply check if a tile is of a particular type
    bool getIsWaterTile();//checks if it is water tile
    void setIsWaterTile(bool Bol);
    bool getIsLandTile();
    void setIsLandTile(bool Bol);
    bool getIsCity();
    void setIsCity(bool Bol);
    void resetLocation(int row, int column);
    
    void setOpponentLocation(int row, int column); //after you beat them in battle 

    private:
    int row;
    int column;
    string CityName;
    int tileNo;
    string tileMark;
  //  City city;
    bool isWaterTile = false;
    bool isLandTile = false;
    bool isCity = false;


};