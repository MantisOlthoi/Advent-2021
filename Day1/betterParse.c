#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <time.h>
#include <string.h>

#include "helper.h"

int main(void)
{
    START_CLOCK;

    // Read in the input file
    FILE *fp = fopen("input1.txt", "r");
    assert(fp);

    long startPos = ftell(fp);
    fseek(fp, 0, SEEK_END);
    long endPos = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    size_t inputSize = endPos - startPos;
    char *inputStr = (char *)(malloc(inputSize + 1));
    int count = fread(inputStr, inputSize, 1, fp);
    assert(count == 1);
    inputStr[inputSize] = '\0'; // Gotta make sure to properly terminate our input!!!
    fclose(fp);

    // Parse the input file
    //count = 0;
    //char *currPos = inputStr;
    //do
    //{
    //    count++;
    //    currPos = strchr(currPos, '\n') + 1;
    //} while(currPos != (char *)1);
    //printf("%d elements\n", count);

    count = 0;
    char *currPos = inputStr;
    int prev = -1;
    int increases = 0;
    do
    {
        int curr;
        int c = sscanf(currPos, "%d", &curr);
        if(!c) break;
        currPos = strchr(currPos, '\n') + 1;
        if (prev != -1 && curr > prev)
        {
            increases++;
        }
        prev = curr;
    } while(currPos != (char *)1);

    END_CLOCK;

    printf("Count: %d\n", increases);

    PRINT_ELAPSED;

    return 0;
}

