#include <stdio.h>
#include <cs50.h>
#include <math.h>

// American change system: 25, 10, 5, 1
// convert users answer into cents



int main(void)
{
    
    // Ask user how much change they need
    float change_owed = get_float("How much change do you need?:  "); 
    
    //Convert this change into cents
    int change_in_cents = change_owed * 100;

     
    //Initial coin count integer 
    int coin_count = 0;

    //coin values
    int loopchange = round(change_in_cents);
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    int x = loopchange % 25;

    printf("change %i \n", loopchange);
    printf("change %i \n", x);
    
    //start serie of while loops
    
    //while we can use quarters
    while ((loopchange / quarter) > 0)
    {
        coin_count++;
        loopchange -= quarter;
    }
    
    while ((loopchange / dime) > 0)
    {
        coin_count++;
        loopchange -= dime;
    }
    
    while ((loopchange / nickel) > 0)
    {
        coin_count++;
        loopchange -= nickel;
    }
    
    while ((loopchange / penny) > 0)
    {
        coin_count++;
        loopchange -= penny;
    }
    
    printf("coin count is %i \n", coin_count);
    printf("change left is: %i \n", loopchange);

}
