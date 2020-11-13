#include <string>
#include "Location.h"

using namespace std;

//this entire function simply determines the location of the warrior or hero, and states where they are located using the rows and column
//also depicts the type of tile each one is
//this is the implementation of the .h function, in which all of these methods were initially declared
Location::Location(int iRow, int iColumn)//determines the row and column
{
    row = iRow;
    column = iColumn;
}
void Location::setRow(int iRow)
{
   row = iRow;
}
int Location::getRow()
{
   return row;
}
void Location::setColumn(int iColumn)
{
    column = iColumn;//captures location
}
int Location::getColumn()
{
   return column;
}
void Location::setCityName(string sName)
{
    CityName = sName;//captures city name
}

string Location::getCityName()
{
    return CityName;
}
void Location::setTileNo(int iNo)//gets the tiles and assigns it to a variable
{
    tileNo = iNo;
}
int Location::getTileNo()
{
    return tileNo;
}
void Location::setTileMark(string sMark)
{
    tileMark = sMark;//assigngs the marking of the tile to a string variable
}
string Location::getTileMark()//gets the tile marking
{
    return tileMark;
}
string Location::getDisplayTileMark() //assigning the 
{
    if(tileMark == "p")
       return "*";
     else if(tileMark == "w")  
       return "~";
       else
        return tileMark;
}
bool Location::getIsWaterTile()
{
      if(isWaterTile == true)
      return true;
     
    return false;  
}
void Location::setIsWaterTile(bool Bol)
{
    isWaterTile = Bol;
}
bool Location::getIsLandTile()
{
    if(isLandTile == true)
      return true;
     
    return false;  
}
void Location::setIsLandTile(bool Bol)
{
    isLandTile = Bol;
}
bool Location::getIsCity()
{
     if(isCity == true)
      return true;
     
    return false; 
   
}
void Location::setIsCity(bool Bol)
{
    isCity = Bol;
}
 void Location::resetLocation(int iRow, int iColumn)
 {
      row = iRow;
      column = iColumn;
 }