#ifndef CORRECT_INPUT_H
#define CORRECT_INPUT_H

#define NUM_MONTH 12
#define NUM_DAY 31

#include <stdbool.h>
#include "exit_codes.h"

//int check_fields(size_t *sum, char **contragent, char **date, struct extension *ext);

int correct_string(const char *str);
int correct_number(const int count);

int correct_date(const char *str);
bool is_correct_day(const char *str); 
bool is_correct_month(const char *str); 
bool is_correct_year(const char *str);

#endif
