#include <stdio.h>
#include <cs50.h>

int main(void)

{
    int x = get_int("x : ");
    int y = get_int("x: ");
    printf("%i\n", x + y);
}