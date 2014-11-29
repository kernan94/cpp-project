#include "header.h"

int main() 
{
   int charHealth = 1, charPower = 1, roomNumber = 1, potionCount = 1, healthMax = 1, charAction, state, enemyArray[2]; //enemyArray[health, power]
   string charName, filename, statArray[6]; //statArray[name, health, power, room, potion, healthMax]
   bool fleeCombat = false;

   srand(unsigned(time(NULL)));

    displayArt(1);
    mainMenu();
    charGen(charName, charHealth, charPower, roomNumber, potionCount, healthMax);

    do
    {
       enemyGen(roomNumber, enemyArray);
       do
       {
          charAction = roomChoice(charName, charHealth, potionCount);
          fleeCombat = resolveCombat(charAction, charHealth, charPower, potionCount, healthMax, enemyArray);
       } while (charHealth > 0 && enemyArray[0] > 0 && fleeCombat != true);

       roomNumber++;
    } while (charHealth > 0);

    charDeath(roomNumber);

    return 0;
}
