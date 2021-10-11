#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include "mem_operations.h"

int create_array(struct contract **array, const size_t size)
{
    int exit_code = SUCCESS;

    *array = (struct contract *) malloc(size * sizeof(struct contract));
    if (array == NULL) {
        exit_code = MEM_ERR;
    }

    return exit_code;
}

void increase_memory(struct contract **array, size_t *max_size, const size_t cur_size)
{
    if (cur_size == *max_size) {
        *max_size *= 2;
        
        realloc_memory(array, *max_size);
    }
}

int realloc_memory(struct contract **array, const size_t size)
{
    int exit_code = SUCCESS;

    if (size > 0) {
        struct contract *tmp = (struct contract *) realloc(*array, size * sizeof(struct contract));
        if (tmp != NULL) {
            *array = tmp;
        }
        else {
            exit_code = MEM_ERR;
        }
    }

    return exit_code;
}

void free_array(struct contract **array, const size_t size)
{
    if (*array != NULL) {
        for (size_t i = 0; i < size; i++) {
            free((*array)[i].type);
            free((*array)[i].contragent);
            free((*array)[i].date);
            free((*array)[i].extension.desc);
        }

        free((*array));
        *array = NULL;
    }
}