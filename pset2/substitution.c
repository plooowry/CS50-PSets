#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Substitution key = argv[1], must be 26 characters long.
// [TEST Key]: argv[1] = YTNSHKVEFXRBAUQZCLWDMIPGJO
// [Test Input] = abc ABC 123 !")
// [Test Output] = ytn YTN 123!")

int main(int argc, string argv[])
{
    int count = 0;
    int countK = 0;
    string k = argv[1];
    const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < strlen(k); i++)
    {
        count ++;
        // is the key purely alphabetical?
        if (isalpha(k[i]) == false)
        {
            printf("The key you have selected contains non-alphabetical inputs\n");
            return false;
        }
        // Does the key should have repeated characters?
        for (int j = i+1; j < strlen(k); j++)
        {
            if (k[i] == k[j])
            {
                printf("You have repeating letters\n");
                return false;
            }
        }
    }
// Check to see if string is 26 characters
    if (count != 26)
    {
        printf("Your key length is: %i and it should be 26, please try again \n", count);
        return false;
    }
// logic
    string plainText = get_string("What is your message: ");
    for (int i = 0; i < strlen(k); i++)
    {
        if (isalpha(plainText[i]))
        {
            for (int j = 0; j < strlen(k); j++)
            {
                // Option 1: if it's lower case letter
                if (plainText[i] == tolower(alphabet[j]))
                {
                    printf("%c",tolower(k[j]));
                }
                // Option 2: if it's upper case letter
                else if (plainText[i] == toupper(alphabet[j]))
                {
                    printf("%c",toupper(k[j]));
                }
            }
        }
        // Option 3: special ch
        else if (plainText[i-1] > 31 && plainText[i-1] < 127 )
        {
            printf("%c", plainText[i]);
        }
    }
    printf("\n");
}
