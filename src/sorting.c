/**
 * Data Structures and Algorithms in C
 * Copyright (C) 2020 Jose Fernando Lopez Fernandez
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "data-structures-and-algorithms-in-c.h"

long int* bubble_sort(long int* input_array, size_t n) {
    long int* sorted_array = allocate_memory(sizeof (long int) * n);

    /** Copy the input array to the sorted array before sorting */
    for (size_t i = 0; i < n; ++i) {
        sorted_array[i] = input_array[i];
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (sorted_array[i] < sorted_array[j]) {
                long int temp = sorted_array[i];
                sorted_array[i] = sorted_array[j];
                sorted_array[j] = temp;
            }
        }
    }

    return sorted_array;
}

long int* counting_sort(long int* input_array, size_t n) {
    /** Find the maximum element in the input array */
    long int maximum = 0;

    for (size_t i = 0; i < n; ++i) {
        if (maximum < input_array[i]) {
            maximum = input_array[i];
        }
    }

    /** Allocate an array to hold the sorted input */
    long int* sorted_input = allocate_memory(sizeof (long int) * n);

    /** Allocate array to use as temporary working storage */
    long int* temporary_storage = allocate_memory(sizeof (long int) * (maximum + 1));

    for (long int i = 0; i <= maximum; ++i) {
        temporary_storage[i] = 0;
    }

    for (size_t i = 0; i < n; ++i) {
        temporary_storage[input_array[i]] = temporary_storage[input_array[i]] + 1;
    }

    for (long int i = 1; i <= maximum; ++i) {
        temporary_storage[i] += temporary_storage[i-1];
    }

    for (size_t i = n; i > 0; --i) {
        sorted_input[temporary_storage[input_array[i-1]]-1] = input_array[i-1];
        temporary_storage[input_array[i-1]] = temporary_storage[input_array[i-1]] - 1;
    }

    /** Free the temporary storage array */
    free(temporary_storage);

    return sorted_input;
}
