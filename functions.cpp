#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <limits>
#include <ctime>
#include "header.h"

using namespace std;


// function used to get filename for saving or loading
// EX: filename = getFilename(1);
string getFilename(int state){
    string overwrite, inputFile, outputFile;
    ifstream fin;
    ofstream fout;

    // state 1 == input
    // state 0 == output
    if (state == 1){
        cout << "Input Filename: ";
        cin >> inputFile;

        fin.open(inputFile.c_str(), ios::in);
        if(fin.fail()){
            cout << "Error: File cannot be opened." << endl;
        }
        fin.close();
        return inputFile;

    
    }else{
        while (true){
        cout << "Output Filename: ";
        cin >> outputFile;
        fout.open(outputFile.c_str(), ios::in);
            if(fout.good()){ // file we are going to write to exists!
                cout << outputFile << " already exists, overwrite? (Y/N)" << endl;
                cin >> overwrite;
                if (overwrite == "Y" || overwrite == "y") {
                    fout.close();
                    return outputFile;   
                }
            } else{
                return outputFile;           
            }
         fout.close();   
        }
    }
}

void saveStats(string filename, int statArray[], int statSize){
    ofstream fout;

    
    


}

void loadStats(string filename, int statArray[], int statSize){
    ifstream fin;



}

void displayArt(int code) {
    switch (code) {
        // Logo
        case 1:
            cout << "Some ascii art" << endl;
            cout << "Welcome to game X" << endl;
            break;

        // Character
        case 2:
            break;

        // Monster
        case 3:
            break;
        }
}

void mainMenu() {
    int menuValue;
    do {
        cout << "Select an option: " << endl;
        cout << "1. New Game" << endl;
        cout << "2. Load Game" << endl;
        cout << "0. Exit" << endl;
        
        cin >> menuValue;
        if (menuValue == 1){
            // newGame();
        } else if (menuValue == 2){
            // getFilename(1);
            // loadStats(filename, statsArray, statSize);
            // start game
        }
    } while( menuValue != 0);
}
