#include "header.h"

int main() 
{
    int charHealth = 1, charPower = 1, roomNumber = 1, potionCount = 1;
    int healthMax = 1, charAction, statSize = 6, option, enemyArray[2]; //enemyArray[health, power]
    string charName, filename, statArray[6]; //statArray[name, health, power, room, potion, healthMax]
    bool fleeCombat = false;

    srand(unsigned(time(NULL)));

    displayArt(1);
    option = mainMenu();

    if (option == 1)
    {
      charGen(charName, charHealth, charPower, roomNumber, potionCount, healthMax);
    }
    else if (option == 2)
    {
       filename = getFilename(1);
       loadStats(filename, statArray, statSize);
       extractArray(charName, charHealth, charPower, roomNumber, potionCount, healthMax, statArray);
    }

    do
    {
       enemyGen(roomNumber, enemyArray);
       do
       {
           charAction = roomChoice(charName, charHealth, potionCount, roomNumber);
           if (charAction == 4){
                infuseArray(charName, charHealth, charPower, roomNumber, potionCount, healthMax, statArray);
                filename = getFilename(0);
                saveStats(filename, statArray, statSize);
           } 
           else if (charAction == 5) 
           {
                exit(0);
           } 
           else 
           {
                fleeCombat = resolveCombat(charAction, charHealth, charPower, potionCount, healthMax, enemyArray);
           }
        } while (charHealth > 0 && enemyArray[0] > 0 && fleeCombat != true);
    
        roomNumber++;
    
    } while (charHealth > 0);

    charDeath(roomNumber);

    return 0;
}
