#include <stdio.h>
#include <cs50.h>


int main(void)
{
     // Get height
     int n;
     
     {
         n = get_int("Height:  ");
     }
     
     
     // While the below is true carry out the loop
     while (n > 8 || 1 > n);
     
     // Print hash pattern height loop
     for (int i = 0; i < n; i++)
     {
         //Make the spaces to the left [DONE]
         for (int j = 1; j < n-i; j++)
         {
             printf(" ");
         }
         
         
         //Make the hashes to the left
         for (int j = 0; j <= i; j++)
         {
             printf("#");
         }
         
         
         //Make the space in the middle
         {
             printf(" ");
         }
         
         
         //Make the hashes to the right
          for (int j = 0; j <= i; j++)
         {
             printf("#");
         }
         
         
         //New line
         printf("\n");
         
         
     }
}


