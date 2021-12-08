#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <time.h>

#include "helper.h"

extern int input[];
extern const int inputCount;

int main(void)
{
    START_CLOCK;

    int increases = 0;
    int prevSum = input[0] + input[1] + input[2];
    for (int i = 3; i < inputCount; i++)
    {
        // No need to be fancy since this is already in cache
        int currSum = prevSum - input[i-3] + input[i];
        if (currSum > prevSum)
        {
            increases++;
        }
        prevSum = currSum;
    }

    END_CLOCK;

    printf("Count: %d\n", increases);

    PRINT_ELAPSED;

    return 0;
}
