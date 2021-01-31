#include <cs50.h>
#include <stdio.h>

int main(void)
{
int start,end,born,dead;

    // greater than or equal to 9. 
    do
    {
        start=get_int("Start size: ");
    }
    while(start<9);
    
    //greater than or equal to the starting population size
    do
    {
        end=get_int("End size: ");
    }
    while(end<start);
    
    
    int i=0;
    while(start< end)
    {
        born=start/3;
        dead=start/4;
        start=start+born-dead;
        i++;
    }

    printf("Years: %i",i);
}
