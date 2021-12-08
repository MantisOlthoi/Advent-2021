#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <time.h>

#include "helper.h"

int main(void)
{
    START_CLOCK;

    FILE *fp = fopen("input1.txt", "r");
    assert(fp);

    int prev = -1;
    int increases = 0;
    while (!feof(fp))
    {
        int curr;
        int count = fscanf(fp, "%d", &curr);
        if (!count) 
        {
            perror("Failed to fscanf");
            continue;
        }
        if (prev != -1 && curr > prev)
        {
            increases++;
        }
        prev = curr;
    }
    fclose(fp);

    END_CLOCK;

    printf("Count: %d\n", increases);

    PRINT_ELAPSED;

    return 0;
}
