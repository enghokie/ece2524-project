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

int welcome()
{
  system("clear");
  fprintf(stdout, "\t\t __________________________\n");
  fprintf(stdout, "\t\t|                          |\n");
  fprintf(stdout, "\t\t| Welcome to TypeMachine!! |\n");
  fprintf(stdout, "\t\t|  By: Braedon Dickerson   |\n");
  fprintf(stdout, "\t\t|            & Siraj Ali   |\n");
  fprintf(stdout, "\t\t|__________________________|\n");
  fprintf(stdout, "\t\t                            \n");
  fprintf(stdout, "\t     **PLEASE SELECT A MODE AND WAIT UNTIL THE GAME STARTS**\n\n");
  wait(4);

  return 0;
}

int directionsMode1()
{
  fprintf(stdout, "DIRECTIONS:\n");
  fprintf(stdout, "~~~~~~~~~~~\n");
  fprintf(stdout, ">>Type the WORD form of the number that appears\n>>Twenty words will appear, one right after the other\n>>Type the letters as fast as you can and push enter once you're done!!\n\n");
  wait(12);
  fprintf(stdout, "Are you ready?? ;)\n");
  wait(3);
  fprintf(stdout, "GO!!\n\n");

  return 0;
}

char* intConverter(int num)
{
   char* buf[21] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen","eighteen", "nineteen", "twenty"};
   if (num > -1 && num < 21)
        return buf[num];
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
  fprintf(stdout, "%d\n", num);
  
  return num;
}

double getNum(int numDisplayed)
{
  time_t now = time(&now);
  time_t waitTime = now;
  double timeDiff = 0;
  
  scanf("%s['^\n']", numRead);
  lowerCase(numRead);
  fprintf(stdout, "\n");
  time(&waitTime);
  timeDiff = difftime(waitTime,numDisplayed);
  if (strncmp(numRead,intConverter(numDisplayed),100))
       return 99;
  else
       return timeDiff;
}

int stats(double total, int numMissed)
{
  system("clear");
  fprintf(stdout,"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n");
  fprintf(stdout,"*                GAME OVER                    *\n");
  fprintf(stdout,"*                                             *\n");
  fprintf(stdout,"* STATS:                                      *\n");
  fprintf(stdout,"*       >>Words Mispelled  %d/20 word(s)      *\n", numMissed);
  fprintf(stdout,"*       >>Average Time     %.2f second(s)     *\n", total/20);
  fprintf(stdout,"*                                             *\n");
  fprintf(stdout,"*   !!THANKS FOR PLAYING TypeMachine!! =D     *\n");
  fprintf(stdout,"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n");
  wait(8);
  return 0;
}

int main()
{
   enum States{mode1, mode2, mode3};
   enum States curState = mode1;
   
   while (1)
   {
      int timeDiff;
      int missed = 0;
      int i = 0;
      double totalTime = 0;
     
      welcome();
      directionsMode1();
   

      switch(curState)
      {
          case mode1: {
          
          while (i < 20)
          {
            timeDiff = getNum(printNum());

            if (timeDiff != 99)
                totalTime += timeDiff;
            else
                missed++;

            i++;
          }
          stats(totalTime,missed);
          break;
	  }
          
          case mode2:
          break;
          
          case mode3:
          break;
          
      }
   }
    
    return 0;
}
//MODES:
// 1. keep going until you spell one wrong: record how many correct and total time
// 2. do reverse of original: print out word and type number
