#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//[NOTES] Our main function can take argument. The first argument is "argc" which represents the argument count (the number of command line arguments) ... and an array of strings called argv[] i.e.  If ./caesar 3 is entered -- argc = 2, argv[0] = ./caesar // argv[1] = 3
int main(int argc, string argv[])
{
    // Getting the Key
        // Ensure single command line argument
        if (argc != 2)
        {
            printf("Usage argc error: ./caesar key \n");
            return false;
        }
        else
        {
            // Check that second condition only contains digits
            string k = argv[1];
            for (int i = 0; i < strlen(k); i++)
            {
                if (isdigit(k[i]) == false)
                {
                    printf("Usage err: doesnt only contain digits \n");
                }
            }

            // Turn the argv[1] into an integer
            int myKey = atoi(k);

            // Promt use to get plain text
            string plainText = get_string("What is your Plain Text: ");

            //encipher plain text
            for (int i=0; i < strlen(plainText); i++)
            {
                if ( isupper(plainText[i]))
                {
                    plainText[i] = (plainText[i] - 65);
                    plainText[i] = (plainText[i] + myKey) % 26;
                    plainText[i] = (plainText[i] + 65 );
                }

                 if (islower(plainText[i]))
                {
                    plainText[i] = (plainText[i] - 97);
                    plainText[i] = (plainText[i] + myKey) % 26;
                    plainText[i] = (plainText[i] + 97);
                }

                 if (isalpha(plainText[i]))
                {
                    plainText[i] = plainText[i];
                }
            }

            printf("Ciphertext: %s\n", plainText);
            printf("Thank you for playing \n");

            //[TEST, k = 1]: pText = xyz123!"£
            //[TEST, k = 1]: cText = yza123!"£
        }
}
