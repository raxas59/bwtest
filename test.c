#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char **argv) {
    unsigned long long arrSize;
    unsigned long long iterCount;
    int *array;
    unsigned long long i, j;
    struct timespec start;
    struct timespec end;
    unsigned long long numElems;

    if (argc < 3) {
        fprintf(stderr, "Usage: bwtest <numelems> <itercount>\n");
        exit(1);
    }

    numElems = (unsigned long long)atoi(argv[1]);
    iterCount = (unsigned long long)atoi(argv[2]);

    arrSize = numElems * sizeof (int);

    array = (int *) malloc(arrSize);

    clock_gettime(CLOCK_MONOTONIC, &start);

    for (i = 0; i < iterCount; i++) {
        for (j = 0; j < numElems; j++) {
            array[j]++;
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    long seconds = end.tv_sec - start.tv_sec;
    long nanosecs = end.tv_nsec - start.tv_nsec;
    double elapsed = seconds + nanosecs * 1e-9;

    unsigned long long numOps = numElems * iterCount;

    double opRate = numOps / elapsed;

    // printf("numElems: %lld iterCount: %lld numOps: %lld elapsed: %f opRate: %.0f\n", numElems, iterCount, numOps, elapsed, opRate);
    printf("%.0f\n", opRate);

    // while (1) {
        // sleep(30);
    // }

    return 0;
}
