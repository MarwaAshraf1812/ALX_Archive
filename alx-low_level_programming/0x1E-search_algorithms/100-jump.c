#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"
/**
 * min: function that Returns the smaller of two values
 * - a: First value to compare
 * - b: Second value to compare
 * Returns: The minimum of 'a' and 'b'.
*/


size_t min(size_t a, size_t b) {
    return (a < b) ? a : b;
}

/**
 * jump_search: Function that searches for a value in an array
 * - *array : is a pointer to the first element
 * - size : size of array
 * - value : is the value to search for
 * 
 * Return :  the first index where value is located
*/


int jump_search(int *array, size_t size, int value) {
    size_t steps = sqrt(size);
    size_t prev = 0;

    while (array[min(steps, size) - 1] < value) {
        prev = steps;
        steps += sqrt(size);

        if (prev >= size) {
            return (-1);
        }
    }

    while (array[prev] < value) {
        prev++;

        if (prev == min(steps, size)) {
            return (-1);
        }
    }

    if (array[prev] == value) {
        return (prev);
    }

    return (-1);
}
