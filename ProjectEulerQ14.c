#include <stdio.h>
#include <stdlib.h>

#define UPPERBOUND 1000000

int main()
{
    int max = 0;
    int maxnum = 0;
    long long int currentnum = 0;
    int current = 0;
    // uses cashe to save the numbers' sequence length so once currentnum goes below the i it exits while loop and adds the current counter with the previously saved sequence length in the cache to reduce run time
    int *cache;
    cache = malloc(sizeof(int)*UPPERBOUND);
    for (int i = 0; i < UPPERBOUND; i++)
    {
        cache[i] = -1;
    }

    for (int i = 2; i < UPPERBOUND; i++)
    {
        currentnum = i;
        current = 0;
        while (currentnum != 1 && currentnum >= i)
        {
            current++;
            if (currentnum % 2 == 0)
            {
                currentnum /= 2;
            }
            else
            {
                currentnum = 3 * currentnum + 1;
            }
        }
        cache[i] = current + cache[currentnum];
        if (cache[i] > max)
        {
            maxnum = i;
            max = cache[i];
        }
    }

    printf("%d\n", maxnum);

    return 1;
}