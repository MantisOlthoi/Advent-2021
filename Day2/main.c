#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#include "helper.h"

int main(void)
{
    START_CLOCK;

    FILE *fp = fopen("input.txt", "r");
    assert(fp);

    long horizontal = 0;
    long vertical = 0;
    while(!feof(fp))
    {
        char str[24];
        int count;
        int c = fscanf(fp, "%s %d", str, &count);
        if (c != 2)
            continue;
        if (strncmp(str, "forward", 7) == 0)
            horizontal += count;
        else if(strncmp(str, "down", 4) == 0)
            vertical += count;
        else if(strncmp(str, "up", 2) == 0)
            vertical -= count;
    }
    fclose(fp);

    long ans = horizontal * vertical;

    END_CLOCK;

    printf("Ans: %ld\n", ans);

    return 0;
}
