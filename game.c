#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

char numRead[30];
int maxElement = 0;

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

char* stringLower(char* word)
{
   int i;
   for (i = 0; word[i]; i++)
   {
     word[i] = tolower(word[i]);
   }
   
   return word;
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
    printf(" This mode randomly outputs a specified amount of numbers \n\t and you have to type them in the space below as fast ");
    printf("as you can.\n\t Your statistics will be displayed after you have finished typing all\n\t of the words.\n\n");
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

void ready()
{
  char buf[10];
  printf("Are you ready??\n");
  scanf("%s['^\n']", buf);
  if (!strncmp(stringLower(buf),"yes", 10))
  {
  	/*Go on*/
  }
  else
  {
  	while (!strncmp(stringLower(buf),"yes",10))
  	{
  	  printf("Okay I'll wait...\n");
  	  wait(5);
  	  printf("How about now?\n");
  	  scanf("%s['^\n']", buf);
  	}
  }
}

void directionsMode1()
{
  char buf[15];
  system("clear");
  printf("\t\t\t*~~~~~~~~~~*\n");
  printf("\t\t\t|  MODE 1  |\n");
  printf("\t\t\t*~~~~~~~~~~*\n\n");
  printf("DIRECTIONS:\n");
  printf("~~~~~~~~~~~\n");
  printf(">>Input the amount of words you will like to try and type correctly and quickly\n");
  printf(">>Type the WORD form of the number that appears\n>>Twenty words will appear, one right after the other");
  printf("\n>>To quit press Ctrl+c\n>>Type the letters as fast as you can and push enter once you're done!!\n\n");
  wait(3);
  ready();
}

void directionsMode2()
{
  system("clear");
  printf("\t\t\t*~~~~~~~~~~*\n");
  printf("\t\t\t|  MODE 2  |\n");
  printf("\t\t\t*~~~~~~~~~~*\n\n");
  printf("DIRECTIONS:\n");
  printf("~~~~~~~~~~~\n");
  printf(">>Type the WORD form of the number that appears\n>>Words will appear, one right after the other, ");
  printf("\n  until you misspell a word");
  printf("\n>>To quit press Ctrl+c\n>>Type the letters as fast as you can and push enter once you're done!!\n\n");
  wait(3);
  ready();
  printf("GO!!\n\n");
}

void directionsMode3()
{
  system("clear");
  printf("\t\t\t*~~~~~~~~~~*\n");
  printf("\t\t\t|  MODE 3  |\n");
  printf("\t\t\t*~~~~~~~~~~*\n\n");
  printf("DIRECTIONS:\n");
  printf("~~~~~~~~~~~\n");
  printf(">>Input the amount of words you will like to try and type correctly and quickly\n");
  printf(">>Type the INTEGER form of the number that appears\n>>Twenty numbers will appear, one right after the other");
  printf("\n>>To quit press Ctrl+c\n>>Type the numbers as fast as you can and push enter once you're done!!\n\n");
  wait(3);
  ready();
}

char* intConverter(int num)
{
   char* buf[21] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen","eighteen", "nineteen", "twenty"};
   if (num > -1 && num < 21)
        return buf[num];
   else
        return buf[0]; //error handling
}

int wordConverter(char* word)
{
  int array[21] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  char* buf[21] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen","eighteen", "nineteen", "twenty"};
  for (int i = 0; i < 21; i++)
  {
    if (strncmp(word, buf[i], 100))
	return array[i];
    else
	return array[0];
  }
}

int printNum()
{
  time_t now = time(&now);
  srand((unsigned) now);
  int num = rand()%20;
  printf("%d\n",num);
  return num;
}

double getNum(int numDisplayed)
{
  time_t now = time(&now);
  time_t waitTime = now;
  double timeDiff = 0;
  
  scanf("%s['^\n']", numRead);
  stringLower(numRead);
  printf("\n");
  time(&waitTime);
  timeDiff = difftime(waitTime,now);
  if (!strncmp(numRead,intConverter(numDisplayed),100))
       return timeDiff;
  else
       return 99;
}

char* printWord()
{
  char* buf[21] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen","eighteen", "nineteen", "twenty"};
  time_t now = time(&now);
  srand((unsigned) now);
  int num = rand()%20;
  printf("%s\n",buf[num]);
  return buf[num];
}

double getNum2(char* wordDisplayed)
{
  int num;
  time_t now = time(&now);
  time_t waitTime = now;
  double timeDiff = 0;
  scanf("%d['^\n']", &num);
  printf("\n");
  time(&waitTime);
  timeDiff = difftime(waitTime, now);
  if (wordConverter(wordDisplayed) == num)
	return timeDiff;
  else
	return 99;
}

void statsMode1(double total, int numMissed)
{
  system("clear");
  printf("*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n");
  printf("*                    GAME OVER                   *\n");
  printf("*                                                *\n");
  printf("* STATS:                                         *\n");
  printf("*       >>Words Mispelled  %d/%d word(s)         *\n", numMissed,maxElement);
  printf("*       >>Average Time     %.2f second(s)        *\n", total/maxElement);
  printf("*                                                *\n");
  printf("*       !!THANKS FOR PLAYING TypeMachine!! =D    *\n");
  printf("*                                                *\n");
  printf("*         ~PLEASE WAIT WHILE GAME RESTARTS~      *\n");
  printf("*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n");
  wait(7);
}

void statsMode2(double total, int numSpelled)
{
  system("clear");
  printf("*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n");
  printf("*                    GAME OVER                       *\n");
  printf("*                                                    *\n");
  printf("* STATS:                                             *\n");
  printf("*       >>Words Spelled Correctly  %d word(s)        *\n", numSpelled);
  printf("*       >>Average Time             %.2f second(s)    *\n", total/numSpelled);
  printf("*                                                    *\n");
  printf("*       !!THANKS FOR PLAYING TypeMachine!! =D        *\n");
  printf("*                                                    *\n");
  printf("*         ~PLEASE WAIT WHILE GAME RESTARTS~          *\n");
  printf("*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n");
  wait(7);
}

void statsMode3(double total, int num)
{
  system("clear");
  printf("*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n");
  printf("*                       GAME OVER                    *\n");
  printf("*                                                    *\n");
  printf("* STATS:                                             *\n");
  printf("*       >>Numbers Missed        %d/%d numbers(s)     *\n", num,maxElement);
  printf("*       >>Average Time          %.2f second(s)       *\n", total/maxElement);
  printf("*                                                    *\n");
  printf("*       !!THANKS FOR PLAYING TypeMachine!! =D        *\n");
  printf("*                                                    *\n");
  printf("*         ~PLEASE WAIT WHILE GAME RESTARTS~          *\n");
  printf("*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n");
  wait(7);
}


int modeSelect()
{
   int mode = 0;
   
   printf(">>Mode Desired: ");
   scanf("%d['^\n']", &mode);
   while (mode != 1 && mode !=2 && mode !=3)
   {
      printf("Mode selected is not applicable. Please select from modes 1,2 or 3 by typing 1,2, or 3 and press enter.\n");
      printf(">>Mode Desired: ");
      scanf("%d['^\n']", &mode);
   }
   printf("\n\n");
   return mode;
}

void totalWords()
{
  int words;
  printf(">>\nEnter the amount of words you want to challenge yourself with: ");
  scanf("%d['^\n']", &words);
  maxElement = words;
  printf("GO!!\n\n");
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
            totalWords();
            while (i < maxElement)
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
	  {
	    timeDiff = 0;
	    directionsMode3();
	    totalWords();
	    while (i < maxElement)
            {
              timeDiff = getNum2(printWord());
              if (timeDiff != 99)
                  totalTime += timeDiff;
              else
                  missed++;

              i++;
            }
	    statsMode3(totalTime, missed);
            break;
	  }
          default:
            break;
          
      }
   }
    
    return 0;
}
//MODES:
// 1. keep going until you spell one wrong: record how many correct and total time
// 2. do reverse of original: print out word and type number
