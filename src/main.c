
#include "data-structures-and-algorithms-in-c.h"

int main(int argc, char *argv[])
{
    if (argc == 1) {
        fprintf(stderr, "No input(s).\n");
        return EXIT_FAILURE;
    }

    long int* input_array = malloc(sizeof (long int) * (argc - 1));

    if (input_array == NULL) {
        fprintf(stderr, "[Error] Memory allocation failure.\n");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; ++i) {
        char* endptr = NULL;
        errno = 0;
        input_array[i-1] = strtol(argv[i], &endptr, 10);

        if ((errno == ERANGE && (input_array[i-1] == LONG_MAX || input_array[i-1] == LONG_MIN)) || (errno != 0 && input_array[i-1] == 0)) {
            perror("strtol");
            return EXIT_FAILURE;
        }
    }

    /** Find the maximum element in the input array */
    long int maximum = 0;

    for (int i = 1; i < argc; ++i) {
        if (maximum < input_array[i-1]) {
            maximum = input_array[i-1];
        }
    }

    /** Allocate an array to hold the sorted input */
    long int* sorted_input = malloc(sizeof (long int) * (argc - 1));

    if (sorted_input == NULL) {
        fprintf(stderr, "[Error] Memory allocation failure.\n");
        return EXIT_FAILURE;
    }

    /**
     * Allocate an array for us to use as temporary working
     * storage.
     *
     */
    long int* temporary_storage = malloc(sizeof (long int) * (maximum + 1));

    for (long int i = 0; i <= maximum; ++i) {
        temporary_storage[i] = 0;
    }

    for (int i = 1; i < argc; ++i) {
        temporary_storage[input_array[i-1]] = temporary_storage[input_array[i-1]] + 1;
    }

    for (long int i = 1; i <= maximum; ++i) {
        temporary_storage[i] += temporary_storage[i-1];
    }

    for (int i = argc - 1; i > 0; --i) {
        sorted_input[temporary_storage[input_array[i-1]] - 1] = input_array[i-1];
        temporary_storage[input_array[i-1]] = temporary_storage[input_array[i-1]] - 1;
    }

    /** Print the original input array */
    for (int i = 1; i < argc; ++i) {
        printf("%lu ", input_array[i-1]);
    }

    puts(" ");

    /** Print the sorted input array */
    for (int i = 1; i < argc; ++i) {
        printf("%lu ", sorted_input[i-1]);
    }

    puts(" ");

    /** Free the original input array */
    free(input_array);

    /** Free the sorted input array */
    free(sorted_input);

    /** Free the temporary storage array */
    free(temporary_storage);

    return EXIT_SUCCESS;
}
