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

void free_fields(char **type, char **contragent, char **date, struct extension *ext)
{
    if (*type != NULL) {
        free(*type);
    }

    if (*contragent != NULL) {
        free(*contragent);
    }

    if (*date != NULL) {
        free(*date);
    }

    if ((*ext).desc != NULL) {
        free((*ext).desc);
    }
}

void free_array(struct contract **array, const size_t size)
{
    if (*array != NULL) {
        for (size_t i = 0; i < size; i++) {
            struct contract cur_contract = (*array)[i];
            free_fields(&cur_contract.type, &cur_contract.contragent, 
                &cur_contract.date, &cur_contract.extension);
        }

        free((*array));
        *array = NULL;
    }
}