#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

char numRead[30];

int wait(double seconds)
{
  time_t now;
  time(&now);
  time_t wait = now;

  while ( difftime(wait,now) < seconds)
  {
     time(&wait);
  }
  return 1;
}

void welcome()
{
  system("clear");
  printf("\t\t ___________________________\n");
  printf("\t\t|                           |\n");
  printf("\t\t| Welcome to Type-Machine!! |\n");
  printf("\t\t|  By: Braedon Dickerson    |\n");
  printf("\t\t|            & Siraj Ali    |\n");
  printf("\t\t|___________________________|\n");
  printf("\t\t                             \n");
  printf("    **PLEASE SELECT A MODE AND WAIT UNTIL THE GAME STARTS**\n\n");
  wait(4);
}

void modeDescriptions()
{
  char buf[10];
  
  printf("If you would like to skip the mode descriptions enter 'yes', otherwise enter 'no': ");
  scanf("%s['^\n']", buf);
  if (!strncmp(buf,"no",10))
  {
    printf("\n\n~>MODES<~\n");
    printf("__________\n\n");
    printf("Mode1:\n\t-Activate mode1 by inputing '1' when prompted.\n\t");
    printf(" This mode randomly outputs twenty numbers and you have to type them in\n\t the space below as fast ");
    printf("as you can.\n\t Your statistics will be displayed after you have finished typing all\n\t twenty words.\n\n");
    printf("Mode2:\n\t-Activate mode2 by inputing '2' when prompted.\n\t");
    printf(" This mode randomly generates numbers and you will have to type them in\n\t the space below as fast ");
    printf("as you can.\n\t The game will end once you mess up typing a number in the word form.\n\t");
    printf(" Your statistics will then be displayed.\n\n");
    printf("Mode3:\n\t-Activate mode3 by inputing '3' when prompted.\n\t");
    printf(" This mode is the exact reverse of mode1, instead of the numbers being\n\t displayed and you having to type the word forms.\n\t");
    printf(" The words of the numbers will be displayed and you will input the number\n\t forms as fast as you can.\n\t");
    printf(" Like always, the stats will be displayed at the end =)\n\n");
  }
}

void directionsMode1()
{
  system("clear");
  printf("\t\t\t*~~~~~~~~~~*\n");
  printf("\t\t\t|  MODE 1  |\n");
  printf("\t\t\t*~~~~~~~~~~*\n\n");
  printf("DIRECTIONS:\n");
  printf("~~~~~~~~~~~\n");
  printf(">>Type the WORD form of the number that appears\n>>Twenty words will appear, one right after the other");
  printf("\n>>To quit press Ctrl+c\n>>Type the letters as fast as you can and push enter once you're done!!\n\n");
  wait(12);
  printf("Are you ready?? ;)\n");
  wait(3);
  printf("GO!!\n\n");
}

void directionsMode2()
{
  system("clear");
  printf("\t\t\t*~~~~~~~~~~*\n");
  printf("\t\t\t|  MODE 2  |\n");
  printf("\t\t\t*~~~~~~~~~~*\n\n");
  printf("DIRECTIONS:\n");
  printf("~~~~~~~~~~~\n");
  printf(">>Type the WORD form of the number that appears\n>>Words will appear, one right after the other, until you mess up");
  printf("\n>>To quit press Ctrl+c\n>>Type the letters as fast as you can and push enter once you're done!!\n\n");
  wait(12);
  printf("Are you ready?? ;)\n");
  wait(3);
  printf("GO!!\n\n");
}

void directionsMode3()
{

}

char* intConverter(int num)
{
   char* buf[21] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen","eighteen", "nineteen", "twenty"};
   if (num > -1 && num < 21)
        return buf[num];
   else
        return buf[0]; //error handling
}

void lowerCase(char* word)
{
	int i;
	for (i = 0; word[i]; i++)
	{
		word[i] = tolower(word[i]);
	}
}

int printNum()
{
  time_t now = time(&now);
  srand((unsigned) now);
  int num = rand()%20;
  printf("%d\n", num);
  
  return num;
}

double getNum(int numDisplayed)
{
  time_t now = time(&now);
  time_t waitTime = now;
  double timeDiff = 0;
  
  scanf("%s['^\n']", numRead);
  lowerCase(numRead);
  printf("\n");
  time(&waitTime);
  timeDiff = difftime(waitTime,now);
  if (strncmp(numRead,intConverter(numDisplayed),100))
       return 99;
  else
       return timeDiff;
}

void statsMode1(double total, int numMissed)
{
  system("clear");
  printf("*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n");
  printf("*                GAME OVER                    *\n");
  printf("*                                             *\n");
  printf("* STATS:                                      *\n");
  printf("*       >>Words Mispelled  %d/20 word(s)      *\n", numMissed);
  printf("*       >>Average Time     %.2f second(s)     *\n", total/20);
  printf("*                                             *\n");
  printf("*   !!THANKS FOR PLAYING TypeMachine!! =D     *\n");
  printf("*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n");
  wait(8);
}

void statsMode2(double total, int numSpelled)
{
  system("clear");
  printf("*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n");
  printf("*                GAME OVER                            *\n");
  printf("*                                                     *\n");
  printf("* STATS:                                              *\n");
  printf("*       >>Words Spelled Correctly  %d word(s)         *\n", numSpelled);
  printf("*       >>Average Time             %.2f second(s)     *\n", total/20);
  printf("*                                                     *\n");
  printf("*   !!THANKS FOR PLAYING TypeMachine!! =D             *\n");
  printf("*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n");
  wait(8);
}

int modeSelect()
{
   int mode = 0;
   
   printf(">>Mode Desired: ");
   scanf("%d['^\n']", &mode);
   while (mode != 1 && mode !=2 && mode !=3)
   {
      printf("Mode selected is not applicable. Please select from modes 1,2 or 3 by typing 1,2, or 3 and press enter.\n");
   }
   printf("\n\n");
   return mode;
}

int main()
{
   enum States{mode1, mode2, mode3};
   enum States curState;
   
   while (1)
   {
      int timeDiff;
      int missed = 0;
      int spelled = -1;
      int i = 0;
      double totalTime = 0;
      welcome();
      modeDescriptions();
      int mode = modeSelect();
      if (mode == 1) curState = mode1;
      else if (mode == 2) curState = mode2;
      else if (mode == 3) curState = mode3;

      switch(curState)
      {
          case mode1: 
          {
            directionsMode1();
            while (i < 20)
            {
              timeDiff = getNum(printNum());

              if (timeDiff != 99)
                  totalTime += timeDiff;
              else
                  missed++;

              i++;
            }
            statsMode1(totalTime,missed);
            break;
	  }
          
          case mode2: 
          {
            timeDiff = 0;	
            directionsMode2();
            while (timeDiff != 99)
            {
               timeDiff = getNum(printNum());
	       totalTime += timeDiff;
	       spelled++;
            }
            statsMode2(totalTime,spelled);
            break;
          }
          
          case mode3:
          break;
          
          default:
          break;
          
      }
   }
    
    return 0;
}
//MODES:
// 1. keep going until you spell one wrong: record how many correct and total time
// 2. do reverse of original: print out word and type number
