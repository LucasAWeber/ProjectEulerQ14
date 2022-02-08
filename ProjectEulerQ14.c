#include <stdio.h>

// can run just fine anything from 100000 and below but takes too long above that threshold
#define UPPERBOUND 1000000

int main()
{
    int max = 0;
    int maxnum = 0;
    int currentnum = 0;
    int current = 0;

    for (int i = 2; i < UPPERBOUND; i++)
    {
        currentnum = i;
        current = 0;
        while (currentnum != 1)
        {
            if (currentnum % 2 == 0)
            {
                currentnum /= 2;
            }
            else
            {
                currentnum = 3 * currentnum + 1;
            }
            current++;
        }
        if (current > max)
        {
            maxnum = i;
            max = current;
        }
    }

    printf("%d", maxnum);

    return 1;
}