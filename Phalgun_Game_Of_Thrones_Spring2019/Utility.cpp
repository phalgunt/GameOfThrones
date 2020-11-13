#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <random>
#include "Utility.h"

using namespace std;

void Utility::printDebug(string sString)
{
 // cout <<  sString <<  endl;
}
void Utility::continueOption()
{
 cout <<" One round is completed, press any key to continue.. "  <<  endl;
        string  option;
        cin >> option;
        cin.clear();
        
}     

bool Utility::palyerRetired(string pName)
{
 string option; 
 bool isTrue = true;
  cout << pName << " has retired. Press F to pay respects." << endl;
  while(isTrue)
  {
    cin >> option;
    cin.clear();
   cout << "option = " << option << endl;
    if(option == "F" || option == "f")//states the bounds of the allowed input value
    {
        isTrue = false;
    }else
    {
     cout << "Have you no respect?! Press F to pay respects." << endl;
     cout << "  " << endl;   
    }
     
    
   }
 return true;  
}
int Utility::selectMyOptions()
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
int Utility::selectMyOptionsMax(int end)
{
 float option; 
 
  while(true)
  {
   cout << "Select a numerical option:" << endl;
  
    cin >> option;
    cin.clear();
  
    if(option <1 || option - floor(option) != 0)//states the bounds of the allowed input value
    {
     cout << "invalid input, re-enter!" << endl;
     cout << "  " << endl;     
    // exit(0);
    }else if(option > end)
    {
       cout << "invalid input, re-enter!" << endl;
       cout << "  " << endl;   
    }
     else
         return int(option); 
    
   }
 return int(option);    
}
int Utility::split(string str, char delim, string strWords[])
{//determines delimeter and cuts there
    
   if(str=="")
    {
        return -1;
    }
    int count=0;
    int size =0;
    while(true)
    {
      int index = str.find(delim);//finds the delimiter index value in string
     
        string sWord ="";//string initializing
        if(index == 0)//if delimiter is the first character in the string, this deletes that
        {
            str.erase(0, index+1);
            continue;
        }
        for(int j=0; j< index; j++)
        {
           if(j==1)
            count += 1;//adds one to the original statement
            
          sWord += str[j];//each character is added to string
          
        }
        str.erase(0, index+1);//erasing the string up to delimiter
       if(index == -1)
        {
           if(str != "")//this is used for the last word in the string
           {
            count += 1;
            strWords[size] = str;
           }
            break;
        }
        strWords[size] = sWord;
     //  cout << ""<<endl;
       size += 1;
    }
    
  return size+1;
}

int Utility::randomNum(int min, int max)
{
   srand(time(NULL)); // Seed the time
    
   return rand()%(max-min+1)+min;
    
}

void Utility::showEncounterOptions()
{
   std::cout << "1. Give a speech" << std::endl;
   std::cout << "2. Buy them out right" << std::endl;
   std::cout << "3. Battle" << std::endl;
}

