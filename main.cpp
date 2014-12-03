#include "header.h"

int main() 
{
   int charHealth = 1, charPower = 1, roomNumber = 1, potionCount = 1, healthMax = 1, charAction, statSize = 6, option, enemyArray[2]; //enemyArray[health, power]
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
            // This could be made a function. Just doing it in main for now
                statArray[0] = charName;
                statArray[1] = convertInt2Str(charHealth);
                statArray[2] = convertInt2Str(charPower);
                statArray[3] = convertInt2Str(roomNumber);
                statArray[4] = convertInt2Str(potionCount);
                statArray[5] = convertInt2Str(healthMax);

                filename = getFilename(0);
                saveStats(filename, statArray, statSize);
           } else if (charAction == 5) {
             exit(0);
          } else {
            fleeCombat = resolveCombat(charAction, charHealth, charPower, potionCount, healthMax, enemyArray);
          }
        } while (charHealth > 0 && enemyArray[0] > 0 && fleeCombat != true);
       roomNumber++;
    } while (charHealth > 0);

    charDeath(roomNumber);

    return 0;
}
