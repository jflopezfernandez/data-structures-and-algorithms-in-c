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

void* allocate_memory(size_t size) {
    void* memory_block = malloc(size);

    if (memory_block == NULL) {
        fprintf(stderr, "[Error] Memory allocation failure: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return memory_block;
}
