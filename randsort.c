#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ARRAY_SIZE 16
#define NUMBER_RANGE 400

int main(void) {
    // seed the mediocre random number generator
    srand(time(NULL));
    // generate an array of random ints
    int unsorted[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        unsorted[i] = ((long double)rand() / RAND_MAX) * NUMBER_RANGE;
    }
    // begin of randsort
    while (true) { // TODO: change true for (!sorted(unsorted))
        // pick a random pair of items and swap them
        int a = ((long double)rand() / RAND_MAX) * ARRAY_SIZE;
        int b = ((long double)rand() / RAND_MAX) * ARRAY_SIZE;
        // decide which way round the numbers are
        int left = a < b ? a : b;
        int right = a < b ? b : a;
        // compare items and swap if wrong way round
        if (unsorted[left] > unsorted[right]) {
            int temporary = unsorted[left];
            unsorted[left] = unsorted[right];
            unsorted[right] = temporary;
        }
        // print out the array for debugging purposes
        for (int i = 0; i < ARRAY_SIZE; i++) {
            printf("%i, ", unsorted[i]);
        }
        printf("\n");
        getchar();
    }
    return 0;
}
