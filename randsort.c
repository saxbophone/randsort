#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ARRAY_SIZE 16
#define NUMBER_RANGE 400

bool sorted(int array[ARRAY_SIZE]);

void print_array(int array[ARRAY_SIZE]);

int main(void) {
    // seed the mediocre random number generator
    srand(time(NULL));
    // generate an array of random ints
    int unsorted[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        unsorted[i] = ((long double)rand() / RAND_MAX) * NUMBER_RANGE;
    }
    // output array for debug logging
    print_array(unsorted);
    // begin of randsort
    // book-keeping for time metrics
    size_t iterations = 0;
    while (!sorted(unsorted)) {
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
        iterations++;
    }
    // print sorted result
    print_array(unsorted);
    printf("Sorted in %zu iterations\n", iterations);
    return 0;
}

bool sorted(int array[ARRAY_SIZE]) {
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        if (array[i] <= array[i + 1]) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

void print_array(int array[ARRAY_SIZE]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%i, ", array[i]);
    }
    printf("\n");
}
