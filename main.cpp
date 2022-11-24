#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <cwchar>
#include <windows.h>
using namespace std;

int main() {

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 30;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    int n = 1;
    string input, in;
    int score;
    srand(time(NULL));//  without this rand() function might continuously give the same value
    
    string filename = "data.txt";
    ifstream dataFile;
    dataFile.open(filename, ios::in);

    if (dataFile.fail())
    {
      cout << filename << "file canne intot be opened!" << endl;
      cout << endl;
      return 0;
    }
    string hw;
    
    dataFile >> hw;
    int num = stoi(hw);
    score = num;
      

    dataFile.close();



label4:
    cout << "current score: " << score << endl;
    cout << "type start to play and exit to exit back to home, type save to save" << endl;
    cout << "->";
    cin >> in; 

if (in == "start") 
{
 
    label1:
    string s=""; // taking null string

    int m = rand() % 10;
    
    if(m < 4)
    {
        goto label1;
    }
    for(int i=0; i<m; i++)
    {
        s += 'a' + (rand() % 26);
    }
    
    label3:
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    cout<<s<<" ";
    cout << endl;
    cout << "->";
    cin >> input;
    
    
    if (input == s)
    {
        score ++;
        goto label1;
    }
    else if (input == "exit")
    {
        goto label4;
    }
    else {
        goto label3;
    }
    
}
else if (in == "save")
{
        ofstream dataFileOut;

        dataFileOut.open(filename, std::ofstream::out | std::ofstream::trunc);

         cout <<"Saving.." << endl;
         
         if(dataFileOut.is_open())
         {
            dataFileOut<<score;
            dataFile.close();
         }
         else cerr<<"Unable to open file";   
         cout << "Saved!" << endl;
         goto label4;
         
         
}


    
    return 0;
}

