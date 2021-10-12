#ifndef IN_HAND_H
#define IN_HAND_H

#include "mem_operations.h"

int input_handler(struct contract **array, size_t *size);

int input_contract(struct contract *cur_contract);
void input_fields(size_t *sum, char **contragent, char **date, struct extension *ext);

int input_string(const char *msg, char **str);
char *get_string(const char *msg);

int input_number(const char *msg, int *num);
int get_number(const char *msg);


#endif
