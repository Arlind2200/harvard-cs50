#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int mine = 2;
    int points = get_int("How many points did you get\n");

    if(points < mine)

    {
    printf("you lost more points than me\n");
    }

    else if (points > mine)
    {
    printf("you lost less point than me\n");
    }

    else
    {
        printf("you lost equal point as me\n");
    }
}