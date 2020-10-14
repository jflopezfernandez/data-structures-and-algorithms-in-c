
#include "data-structures-and-algorithms-in-c.h"

void* allocate_memory(size_t size) {
    void* memory_block = malloc(size);

    if (memory_block == NULL) {
        fprintf(stderr, "[Error] Memory allocation failure: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return memory_block;
}

void print_array(long int* array, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        printf("%ld ", array[i]);
    }

    printf("\n");
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

int main(int argc, char *argv[])
{
    if (argc == 1) {
        fprintf(stderr, "No input(s).\n");
        return EXIT_FAILURE;
    }

    long int* input_array = allocate_memory(sizeof (long int) * (argc - 1));

    for (int i = 1; i < argc; ++i) {
        char* endptr = NULL;
        errno = 0;
        input_array[i-1] = strtol(argv[i], &endptr, 10);

        if ((errno == ERANGE && (input_array[i-1] == LONG_MAX || input_array[i-1] == LONG_MIN)) || (errno != 0 && input_array[i-1] == 0)) {
            perror("strtol");
            return EXIT_FAILURE;
        }
    }

    
    long int* sorted_array = counting_sort(input_array, argc - 1);

    /** Print the original input array */
    print_array(input_array, argc - 1);
    print_array(sorted_array, argc - 1);

    /** Free the original input array */
    free(input_array);

    /** Free the sorted array */
    free(sorted_array);

    return EXIT_SUCCESS;
}
