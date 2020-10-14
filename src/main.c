
#include "data-structures-and-algorithms-in-c.h"

int main(int argc, char *argv[])
{
    if (argc == 1) {
        fprintf(stderr, "No input(s).\n");
        return EXIT_FAILURE;
    }

    while (*++argv) {
        char* copy = allocate_memory_block(strlen (*argv) + 1);

        if (copy == NULL) {
            fprintf(stderr, "[Error] Memory allocation failure in call to jlibc.\n");
            return EXIT_FAILURE;
        }

        strcpy(copy, *argv);
        printf("%s\n", copy);
        free(copy);
    }

    return EXIT_SUCCESS;
}
