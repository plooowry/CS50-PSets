#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
//              a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q,  r, s, t, u, v, w, x, y,  z

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 is the winner!\n ");
    } else if (score1 < score2)
    {
        printf("Player 2 is the winner!\n ");
    }
    else {
        printf("It's a tie!\n");
        }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    // Keep track of the score
    int score = 0;
    int len = strlen(word);

    //compute score for each character
    // Begin a loop looking at each letter
    for (int i=0 ; i < len; i++)
    {
        //If the letter is uppercase then we need to subtract by 65 to get to the correct points index
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 65];
        }
        //If the letter is uppercase then we need to subtract by 97 to get to the correct points index
        else if (islower(word[i]))
        {
             score += POINTS[word[i] - 97];
        }
    }

    return score;

};
