#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <cwchar>
#include <windows.h>
#include <vector>
#include "Linked.h" //doubly linked list bag
using namespace std;


void displayBag(const DoublyLinkedBag<string>& bag)
    {
        cout << "The bag contains " << bag.getCurrentSize()
        << " items:" << endl;
        
    vector<string> bagItems = bag.toVector();
    int numberOfEntries = (int) bagItems.size();
    for (int i = 0; i < numberOfEntries; i++)
        {
            cout << bagItems[i] << " ";
        } // end for
        
        cout << endl << endl;
    }   // end displayBag


int main() {

    DoublyLinkedBag<string> lib;
    

    int n = 1;
    string input, in;
    int score;
    srand(time(NULL));//  without this rand() function might continuously give the same value
    
    string filename = "data.txt";
    string filename2 = "library.txt";
    ifstream dataFile;
    dataFile.open(filename, ios::in);

    if (dataFile.fail())
    {
      cout << filename << "file cannot be opened!" << endl;
      cout << endl;
      return 0;
    }
    string hw;
    
    dataFile >> hw;
    int num = stoi(hw);
    score = num;
    dataFile.close();


    dataFile.open(filename2, ios::in);

    if (dataFile.fail())
    {
      cout << filename << "file cannot be opened!" << endl;
      cout << endl;
      return 0;
    }


    if(dataFile.is_open());
    {
        string words;
        while(dataFile >> words)
        {
            lib.add(words);
        }
   
    }

        dataFile.close();
label4:



    cout << "current score: " << score << endl;
    cout << "1: start" << endl;
    cout << "2: save" << endl;
    cout << "3: exit" << endl;
    cout << "->";
    cin >> in; 


 vector<string> libWord = lib.toVector();
if (in == "start") 
{

   
    label1:
    

    int m = rand() % 1000;
    

    
    label3:

    cout<<libWord[m]<<" ";
    cout << endl;
    cout << "->";
    cin >> input;
    
    
    if (input == libWord[m])
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
