#ifndef IN_HAND_H
#define IN_HAND_H

#include "mem_operations.h"

int input_handler(struct contract **array, size_t *size);

int input_string(const char *msg, char **str);
char *get_string(const char *msg);

int input_number(const char *msg, int *num);
int get_number(const char *msg);

void node_constructor(struct contract **array, const size_t size, 
                        char *type, int sum, char *contragent, char *date, struct extension ext);


#endif
