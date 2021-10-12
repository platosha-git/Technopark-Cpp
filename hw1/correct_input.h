#ifndef CORRECT_INPUT_H
#define CORRECT_INPUT_H

#include <stdbool.h>
#include "exit_codes.h"
#include "mem_operations.h"

#define MILLENNIUM 1000
#define CENTURY 100
#define DECADE 10

#define MIN_YEAR 1900
#define MAX_YEAR 2022

#define NUM_MONTH 12
#define NUM_DAY 31

int check_fields(const size_t sum, const char *contragent, 
	const char *date, const struct extension ext);

bool is_correct_string(const char *str);
bool is_correct_number(const int count);

int correct_date(const char *str);
bool is_correct_format(const char *str);
bool is_correct_day(const char *str); 
bool is_correct_month(const char *str); 
bool is_correct_year(const char *str);

#endif
