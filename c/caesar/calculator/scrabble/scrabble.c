#include <ctype.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

//Points assigned to each letter of the alpahbet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    //Get input from each player
    string word1 = get_string("Player1: ");
    string word2 = get_string("Player2: ");

    //Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }

    else
    {
        printf("Tie\n");
    }
}

int compute_score(string word)
{
    //Keep track of the score
    int score = 0;

    //Compute score from each character
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS [word[i] - 'a'];
        }
    }
    return score;
}