#include "header.h"

// function used to get filename for saving or loading
// EX: filename = getFilename(1);

/*
Purpose: Get filename for save or load function
Pre: state defined for action
Post: tests file first, will output if error or warning
Author: Kevin
*/
string getFilename(int state)
{
    string overwrite, inputFile, outputFile;
    bool alwaysTrue = true;
    ifstream fin;
    ofstream fout;

    // state 1 == input
    // state 0 == output
    if (state == 1)
    {
        cout << "Input Filename: ";
        cin >> inputFile;
        cin.clear();
        cin.sync();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        fin.open(inputFile.c_str(), ios::in);
        if(fin.fail())
        {
            cout << "Error: File cannot be opened." << endl;
            inputFile = "";
        }
        fin.close();
        return inputFile;

    
    } 
    else
    {
        while (alwaysTrue){
        cout << "Output Filename: ";
        cin >> outputFile;
        cin.clear();
        cin.sync();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        fout.open(outputFile.c_str(), ios::in);
            if(fout.good()) // file we are going to write to exists!
            { 
                cout << outputFile << " already exists, overwrite? (Y/N)" << endl;
                cin >> overwrite;
                cin.clear();
                cin.sync();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                if (overwrite == "Y" || overwrite == "y") 
                {
                    fout.close();
                    return outputFile;   
                }
            } 
            else
            {
                return outputFile;           
            }
         fout.close();   
        }
    }

// Should never return this. I'm getting compiler warnings if I don't return a string here.
    return inputFile;
}

/*
Purpose: Saves stats to file
Pre: filename from user and statArray populated
Post: filename populates with data
Author: Kevin
*/
void saveStats(string filename, string statArray[], int statSize)
{
    ofstream fout;
    fout.open(filename.c_str(), ios::out);

    for (int x=0; x < statSize; x++)
    {
        fout << statArray[x] << endl;
    }

    fout.close();
}

/*
Purpose: Loads stats from file
Pre: filename from user
Post: statsArray populates with data for extraction
Author: Kevin
*/
void loadStats(string filename, string statArray[], int statSize)
{
    ifstream fin;
    fin.open(filename.c_str(), ios::in);

    // Only need the 6 lines.
    for (int x=0; x < statSize; x++) 
    {
        getline(fin,statArray[x]);
    }
    fin.close();

}

/*
Purpose: To display ascii art
Pre: Code for which art to display defined
Post: ascii art is displayed on screen
Author: Kevin
*/
void displayArt(int code) 
{
    switch (code) 
    {
        // Logo
        case 1:
            cout << "                  {}\n";
            cout << "  ,   A           {}\n";
            cout << " / \\, | ,        .--.\n";
            cout << "|  =|= >        /.--.\\\n";
            cout << " \\ /` | `       |====|\n";
            cout << "  `   |         |`::`|\n";
            cout << "      |     .-;`\\..../`;_.-^-._\n";
            cout << "     /\\\\/  /  |...::..|`   :   `|\n";
            cout << "     |:'\\ |   /'''::''|   .:.   |\n";
            cout << "      \\ /\\;-,/\\   ::  |..Kevin..|\n";
            cout << "      |\\ <` >  >._::_.| .Reuben |\n";
            cout << "      | `""`_/  ^^/>/>  |   ':'   |\n";
            cout << "      |       |       \\    :   /\n";
            cout << "      |       |        \\   :   /\n";
            cout << "      |       |___/\\___|`-.:.-`\n";
            cout << "      |        \\_ || _/    `\n";
            cout << "      |        <_ >< _>\n";
            cout << "      |        |  ||  |\n";
            cout << "      |        |  ||  |\n";
            cout << "      |       _\\.:||:./_\n";
            cout << "      |      /____/\\____\\\n";
            cout << "\n";
            cout << "Welcome to Endless Halls of Killing Things for Glory" << endl << endl; //or whatever, think of something better later. Use a focus group.
            cout << "There is no glory in dying as an old and withered husk, in dying as a frail shadow of former might! ";
            cout << "And so warriors come to this Hallowed place from all accross the land to test their mettle, one last time. ";
            cout << "Here they encounter endless ranks of Demons. It is said that they guard an ancient treasure. ";
            cout << "What is it? Nobody knows. How many rooms must be cleared? Nobody knows. Will the seekers of treasure be immortalised in song for glorious battle? Heck yeah!" << endl << endl;
            break;

        // Character
        case 2:
            cout << "       ,   |\\ ,__\n";
            cout << "       |\\   \\/   `.\n";
            cout << "       \\ `-.:.     `\\\n";
            cout << "        `-.__ `\\=====|\n";
            cout << "           /=`'/   ^_\\\n";
            cout << "          .'   /\\   .=)\n";
            cout << "       .-'  .'|  '-(/_|\n";
            cout << "       .'  __(  \\  .'`\n";
            cout << "   /_.'`  `.  |`\n";
            cout << "            \\ |\n";
            cout << "             |/\n";
            break;

    }
}

/*
Purpose: Main menu function when game opened
Pre: None
Post: Menu options are outputted onto screen. Returns option input from user
Author: Kevin
*/
int mainMenu() 
{
    int menuValue, option = -1;// passed to main: 1 will call charGen. 2 loads old character.
        do {
            cout << "Select an option: " << endl;
            cout << "1. New Game" << endl;
            cout << "2. Load Game" << endl;
            cout << "0. Exit" << endl;
        
            cin >> menuValue; // This needs input validation!
            if (menuValue == 1)
            {
               option = 1;
            } 
            else if (menuValue == 2)
            {
               option = 2;  
            } 
            else if (menuValue == 0)
            {
               cout << "Thanks for Playing!" << endl;
               exit(0);
           }
        if (option != 1 && option != 2)
        {
            cout << "Please choose new or load before exiting menu" << endl;
        }
    } while( option != 1 && option != 2);
   return option;
}

/*
Purpose: Generate new character
Pre: Random number generator seeded
Post: Returns character name, health, power, potion, max health. Sets room = 1.
Author: Reuben
*/
void charGen(string& name, int& health, int& power, int& room, int& potion, int& max)
{
   displayArt(2);
   cout << "What is the hero's name?" << endl;
   cin >> name; //charName
   cin.clear();
   cin.sync();
   cin.ignore(numeric_limits<streamsize>::max(),'\n');
   health = rand() % 41 + 40; //charHealth. between 40 and 80.
   power = rand() % 6 + 5; //charPower. between 5 and 11.
   room = 1; //New characters starts in room 1.
   potion = rand() % 3 + 1; //Begin with 1, 2, or 3 potions.
   max = health;
}

/*
Purpose: Convert statArray into appropriate data types.
Pre: statArray[] populated with character info.
Post: charName, charHealth, charPower, roomNumber, potionCount, healthMax passed by reference. charName remains as string.
Author: Reuben.
*/
void extractArray(string& name, int& health, int& power, int& room, int& potion, int& max, string statArray[])
{
   name = statArray[0];
   health = convertStr2Int(statArray[1]);
   power = convertStr2Int(statArray[2]);
   room = convertStr2Int(statArray[3]);
   potion = convertStr2Int(statArray[4]);
   max = convertStr2Int(statArray[5]);
}

/*
Purpose: Convert stats into appropriate datatypes and into array
Pre: statArray[] populated with character info.
Post: charName, charHealth, charPower, roomNumber, potionCount, healthMax passed by reference. charName remains as string.
Author: Kevin
*/
void infuseArray(string& name, int& health, int& power, int& room, int& potion, int& max, string statArray[])
{
    statArray[0] = name;
    statArray[1] = convertInt2Str(health);
    statArray[2] = convertInt2Str(power);
    statArray[3] = convertInt2Str(room);
    statArray[4] = convertInt2Str(potion);
    statArray[5] = convertInt2Str(max);
}



/*
Purpose: extract player's decision.
Pre:
Post: combatChoice is returned.
Author: Reuben.
*/
int roomChoice(string name, int health, int potions, int room)
{
    string input = "";
    int action;
    
    cout << "Current room: " << room << endl;
    cout << name << "'s health is at " << health << " and " << name << " has " << potions << " potion(s)." << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Attack" << setw(10) << "" << "2. Use Potion" << setw(10) << "" << "3. Run" << endl;
    cout << "4. Save" << setw(10) << "" << " 5. Quit" << endl;
    cin.clear();

    while(true) 
    {
        cout << "Your choice is: ";
        getline(cin, input);
        
        stringstream convertStream(input);
        if (convertStream >> action)
        {
            break;
        }
        cout << "Please enter valid input" << endl;
    }
   return action;
}

/*
Purpose: determine outcome of combat.
Pre: player made choice, character stats, enemy stats.
Post: health and potion count adjusted.
Author: Reuben.
*/
bool resolveCombat(int action, int& health, int power, int& potion, int max, int enemyArray[])
{
   int damage;
   bool run = false;

   switch (action) 
    {
        //attack was chosen
        case 1:
            damage = (rand() % 4) * power;
            cout << "You dealt " << damage << " points of damage!" << endl;
            enemyArray[0] = enemyArray[0] - damage;

            if (enemyArray[0] <= 0)
                cout << "You defeated the enemy and continue to the next room." << endl << endl;
            break;

        //use potion was chosen.
        case 2:
            if (potion > 0)
            {
                health = max;
                potion = potion - 1;
            }
            else
                cout << "You search for potions in your bag but you have none!" << endl << endl;
            break;

        //run was chosen.
        case 3:
            if (rand() % 4 == 3) //one fourth chance to flee.
            {
                run = true;
                cout << "You successfully fled combat and continue to the next room." << endl << endl;
            }
            else
                cout << "You failed to flee combat." << endl;
            break;
   }
   if (enemyArray[0] > 0 && run != true)
   {
      damage = (rand() % 4) * enemyArray[1];
      cout << "You recieved " << damage << " points of damage!" << endl << endl;
      health = health - damage;
   }
   return run;
}

/*
Purpose: Create an enemy, adjusted for room.
Pre:
Post: enemyArray ready for combat!
Author: Reuben.
*/
void enemyGen(int room, int enemyArray[])
{
   enemyArray[0] = rand() % 21 + room * 3; //enemy health is 0 to 20 plus room modifier.
   enemyArray[1] = rand() % 6 + room * 2; //enemy power is 0 to 5 plus room modifier.
}


/*
Purpose: End Game, Show how far character went.
Pre: room it made it too
Post: End game
Author: Reuben
*/
void charDeath(int room)
{
   string restart;
   cout << "Congratulations, you reached room " << room << " before dying!" << endl;
}


//Taken from lab 5.
// You can use this section of code as is
string convertInt2Str(int intValue)
{
   stringstream stringValue;

   stringValue << intValue;

   return stringValue.str();
}


// You can use this section of code as is
int convertStr2Int(string stringValue)
{
   int intValue;
   stringstream str;

   str << stringValue;

   str >> intValue;

   return intValue;
}
