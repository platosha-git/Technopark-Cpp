#ifndef MEM_OPERATIONS_H
#define MEM_OPERATIONS_H

#include "exit_codes.h"

struct extension {
    char *desc;
    int amount;
};

struct contract
{
    char *type;
    int sum;
    char *contragent;
    char *date;
    struct extension extension;
};


int create_array(struct contract **array, const size_t size);
int realloc_memory(struct contract **array, const size_t size);
void increase_memory(struct contract **array, size_t *max_size, const size_t cur_size);
void free_fields(char **type, char **contragent, char **date, struct extension *ext);
void free_array(struct contract **array, const size_t size);

#endif