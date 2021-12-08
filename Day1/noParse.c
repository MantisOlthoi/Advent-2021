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

    int prev = -1;
    int increases = 0;
    for (int i = 0; i < inputCount; i++)
    {
        if (prev != -1 && input[i] > prev)
        {
            increases++;
        }
        prev = input[i];
    }

    END_CLOCK;

    printf("Count: %d\n", increases);

    PRINT_ELAPSED;

    return 0;
}
