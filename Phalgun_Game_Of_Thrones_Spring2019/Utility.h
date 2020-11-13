#include <string>
#include <vector>

using namespace std;

class Utility
{
    public:
    Utility()
    {
        
    };
    //Enables the user to check for particular objects within the 
    int selectMyOptions();
    int selectMyOptionsMax(int end);
    int split(string str, char delim, string strWords[]);
    int randomNum(int min, int max);
    void showEncounterOptions();
    bool palyerRetired(string pName);
    void continueOption();
    void printDebug(string sString);
    
    private:
};