
#include "data-structures-and-algorithms-in-c.h"

void print_array(long int* array, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        printf("%ld ", array[i]);
    }

    printf("\n");
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

    sort_function_t sort_function = bubble_sort;

    long int* sorted_array = sort_function(input_array, argc - 1);

    /** Print the original input array */
    print_array(input_array, argc - 1);
    print_array(sorted_array, argc - 1);

    /** Free the original input array */
    free(input_array);

    /** Free the sorted array */
    free(sorted_array);

    return EXIT_SUCCESS;
}
