#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <limits>
#include <ctime>
using namespace std;

string getFilename(int state);
void saveStats(string filename, int statArray[], int statSize);
void loadStats(string filename, int statArray[], int statSize);
void mainMenu();
void displayArt(int code);
#endif
