#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

// Keeping track of the square, rectangle, and generation
int square     = 0;
int rectangle  = 0;
int generation = 0;

// The actual program
void program(void)
{
    // Generating the co-ordinate to determine the selected pixel
    int x = (rand() % (50 - 1 + 1)) + 1;
    int y = (rand() % (25 - 1 + 1)) + 1;
    
    // Checking if the position of the square or the rectangle or not
    if ((x > 13 && y > 6) && (x < 47 && y < 19))
    {
        rectangle++;
    }
    else if ((x > 1 && y > 8) && (x < 10 && y < 17))
    {
        square++;
    }
}

void call(void)
{
    system("clear");
    
    // local variables for keeping track
    int counter = 0;
    int genStart = generation;
    
    for (counter;counter<100000;counter++)
    {
        program();
        generation++;
    }
    
    // Report Print
    float result = (float)rectangle / (float)square;
    printf("## Monte Carlo Simulation ##\n\n* Generation:  %d-%d\n* Square:      %d\n* Rectangle:   %d\n\n* Result:      %f\n",
           genStart, generation, square, rectangle, result);
    
}

int main(void)
{
    srand(time(0));
    // local variables
    char choice[3];
    int  comparision;
    bool check = true;
    
    while (check == true)
    {
        // Asking for choice and converting into uppercase
        printf("\nrun? ");
        scanf("%s", choice);
        
        for(int i=0;choice[i];i++)  
        {
            if(choice[i]>=97 && choice[i]<=122)
                choice[i]-=32;
        }
        
        // Comparing the string if it is either "y" or "yes"
        comparision = strcmp(choice, "Y");
        if (comparision != 0)
        {
            comparision = strcmp(choice, "YES");
        }
        
        // Checking the answer
        if (comparision == 0)
        {
            call();
        }
        else
        {
            check = false;
        }
    }
    return 0;
}
