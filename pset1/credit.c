#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //get the card number
    long card_number = get_long("what is your card number:  ");

    //Checksum if valid

    //check the cards length.
    int i = 0;
    long card_length = card_number;
    while (card_length > 0)
    {
        //Bascially, how many times can we divide by ten. This will give us the total number of digits
        card_length = card_length / 10; 
        i++;

    };

    //Check to see that the card length is acceptable
    if (i != 15 && i != 16 && i != 13)
    {
        printf("INVALID \n");
        return 0;
    }
    
    // Next, check starting digits for card type
    // Get starting digits
    long starting_digits = card_number;
    do
    {
        starting_digits = starting_digits / 10;
    }
    while (starting_digits > 100); // Here we are knocking off end digits until we only have the last two digits which must be less than 100
    printf("Starting digit is %li \n", starting_digits);

    
    if ((starting_digits / 10 == 5) && ((starting_digits % 10 > 0) && (starting_digits % 10 < 6)))
    {
        printf("MASTERCARD\n");
    }

    else if ((starting_digits / 10 == 3) && (starting_digits % 10 == 4 || starting_digits % 10 == 7))
    {
        printf("AMEX\n");
    }

    else if (starting_digits / 10 == 4)
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }
    
    // Calculate checksum, Luhn’s Algorithm

    
    int sum1 = 0;
    int sum2 = 0;
    long x = card_number;
    int total = 0;
    int mod1;
    int mod2;
    int digit1;
    int digit2;
    
    // Exmple card number for testing: "4" #0 "0" #3 "6" #0 "0" #0 "0" #0 "0" #0 "0" #0 "1" #4
    do
    {
        
         
        mod1 = x % 10; // Grab the last digit
        x = x / 10; // remove the last digit
        sum1 = sum1 + mod1; // Here we are just adding the numbers
        printf("Your sum1 is: %i \n", sum1);
        
        mod2 = x % 10; //Grabing the next number which is the second last number of the card.
        x = x / 10; //Remove the last digit again
        
        mod2 = mod2 * 2; // times teh number by 2
        
        // Now we need to seperte any digits, because we have to add teh digits together, not teh whole number together
        digit1 = mod2 / 10; // this will give the first digit
        digit2 = mod2 % 10; //this will give the last digit
        sum2 = sum2 + digit1 + digit2; 
        printf("Your sum2 is: %i \n", sum2);
        
    }
    while ( x > 0);
    
    total = sum1 + sum2;
    printf("Your sum1 is: %i \n", sum1);
    printf("Your sum2 is: %i \n", sum2);
    
    printf("Your Total is: %i \n", total);
    
   
    // Now lets say that if the last digit isnt a 0 then the number is INVALID.
    
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    } 
    
    else 
    {
        printf("VALID \n");
    }
    
    
 //END OF SCRIPT

}
