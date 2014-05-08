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
  fprintf(stdout, "\t\t __________________________\n");
  fprintf(stdout, "\t\t|                          |\n");
  fprintf(stdout, "\t\t| Welcome to TypeMachine!! |\n");
  fprintf(stdout, "\t\t|  By: Braedon Dickerson   |\n");
  fprintf(stdout, "\t\t|            & Siraj Ali   |\n");
  fprintf(stdout, "\t\t|__________________________|\n");
  fprintf(stdout, "\t\t                            \n");
  fprintf(stdout, "\t**PLEASE SELECT A MODE AND WAIT UNTIL THE GAME STARTS**\n\n");
  wait(4);
}

void modeDescriptions()
{
  char buf[10];
  
  fprintf(stdout, "If you would like to skip the mode descriptions, enter yes, otherwise enter no");
  scanf("%s['^\n']", buf);
  if (!strncmp(buf,"no",10))
  {
    fprintf(stdout,"\n\n~>MODES<~\n");
    fprintf(stdout,"__________\n\n");
    fprintf(stdout,"Mode1:\n\t-Activate mode1 by inputing '1' when prompted.\n\t");
    fprintf(stdout,"This mode randomly outputs twenty numbers and you have to type them in the space below as fast ");
    fprintf(stdout,"as you can.\n\t Your statistics will be displayed after you have finished typing all twenty words.\n\n");
    fprintf(stdout,"Mode2:\n\t-Activate mode2 by inputing '2' when prompted.\n\t");
    fprintf(stdout,"This mode randomly generates numbers and you will have to type them in the space below as fast ");
    fprintf(stdout,"as you can.\n\t The game will end once you mess up typing a number in the word form.\n\t");
    fprintf(stdout,"Your statistics will then be displayed.\n\n");
    fprintf(stdout,"Mode3:\n\t-Activate mode3 by inputing '3' when prompted.\n\t");
    fprintf(stdout,"This mode is the exact reverse of mode1, instead of the numbers being displayed and you having to type the word fomrms,\n\t");
    fprintf(stdout,"The words of the numbers will be displayed and you will input the number forms as fast as you can.\n\t");
    fprintf(stdout,"Like always, the stats will be displayed at the end =)\n\n");
    wait(15);
  }
}

void directionsMode1()
{
  fprintf(stdout, "DIRECTIONS:\n");
  fprintf(stdout, "~~~~~~~~~~~\n");
  fprintf(stdout, ">>Type the WORD form of the number that appears\n>>Twenty words will appear, one right after the other");
  fprintf(stdout, "\n>>To quit press Ctrl+c\n>>Type the letters as fast as you can and push enter once you're done!!\n\n");
  wait(12);
  fprintf(stdout, "Are you ready?? ;)\n");
  wait(3);
  fprintf(stdout, "GO!!\n\n");
}

void directionsMode2()
{

}

void directionsMode3()
{

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
  timeDiff = difftime(waitTime,now);
  if (strncmp(numRead,intConverter(numDisplayed),100))
       return 99;
  else
       return timeDiff;
}

void stats(double total, int numMissed)
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
}

int modeSelect()
{
   int mode = 0;
   
   fprintf(stdout,">>Mode Desired: ");
   scanf("%d['^\n']", &mode);
   while (mode != 1 && mode !=2 && mode !=3)
   {
      fprintf(stdout,"Mode selected is not applicable. Please select from modes 1,2 or 3 by typing 1,2, or 3 and press enter.\n");
   }
   fprintf(stdout,"\n\n");
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
          case mode1: {
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
          stats(totalTime,missed);
          break;
	  }
          
          case mode2:
          break;
          
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
