#define START_CLOCK \
    struct timespec startTime; \
    clock_gettime(CLOCK_REALTIME, &startTime);

#define END_CLOCK \
    struct timespec endTime; \
    clock_gettime(CLOCK_REALTIME, &endTime);

#define PRINT_ELAPSED \
    time_t deltaS = endTime.tv_sec - startTime.tv_sec; \
    long deltaNS; \
    if (endTime.tv_nsec >= startTime.tv_nsec) \
        deltaNS = endTime.tv_nsec - startTime.tv_nsec; \
    else \
    { \
        deltaNS = 1000000000 - startTime.tv_nsec + endTime.tv_nsec; \
        deltaS--; \
    } \
    printf("Time Elapsed: %lds %ldms %ldus %ldns\n", deltaS, deltaNS / 1000000, deltaNS / 1000 % 1000, deltaNS % 1000);
