/*
Author: Reuben Kernan & Kevin Law
Class: CSI-140-01
Assignment: Final Project
Date Assigned: Week 13
Due Date: 17:00 EST, Dec 5, 2014

Description:
Text based adventure

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the
definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:
-   Reproduce this assignment and provide a copy to another member of
academic staff; and/or
-   Communicate a copy of this assignment to a plagiarism checking
service (which may then retain a copy of this assignment on its
database for the purpose of future plagiarism checking)
*/

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

void saveStats(string, string[], int);
int roomChoice(string, int, int, int);
bool resolveCombat(int, int&, int, int&, int, int[]);
int mainMenu();
void loadStats(string, string[], int);
void infuseArray(string&, int&, int&, int&, int&, int&, string[]);
string getFilename(int);
void extractArray(string&, int&, int&, int&, int&, int&, string[]);
void enemyGen(int, int[]);
void displayArt(int);
void charGen(string&, int&, int&, int&, int&, int&);
void charDeath(int);

string convertInt2Str(int);
int convertStr2Int(string);

#endif
