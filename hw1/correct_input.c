#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>

#include "correct_input.h"

int check_fields(const size_t sum, const char *contragent, 
    const char *date, const struct extension ext)
{
    int exit_code = SUCCESS;

    if (!is_correct_string(contragent) ||
        !is_correct_string(ext.desc)) {
        exit_code = STRING_ERR;

        return exit_code;
    }

    if (!is_correct_number(sum) ||
        !is_correct_number(ext.amount)) {
        exit_code = COUNT_ERR;

        return exit_code;
    }

    exit_code = correct_date(date);

    return exit_code;
}

bool is_correct_string(const char *str)
{
    bool is_correct = true;

    if (strlen(str) == 0) {
        is_correct = false;
    }
    
    for (int i = 0; str[i] != '\0' && is_correct; i++) {
        if (!isalpha(str[i])) {
            is_correct = false;
        }
    }

    return is_correct;
}


bool is_correct_number(const int count)
{
    bool is_correct = true;

    if (count < 0) {
        is_correct = false;
    }
    
    return is_correct;
}


int correct_date(const char *str)
{
    int exit_code = SUCCESS;

    if (!is_correct_format(str) || !is_correct_day(str) || 
        !is_correct_month(str) || !is_correct_year(str)) {
        exit_code = DATE_ERR;
    }

    return exit_code;
}

bool is_correct_format(const char *str)
{
    bool is_correct = true;

    if (strlen(str) != 10) {
        return false;
    }

    if (!isdigit(str[0]) || !isdigit(str[1]) || str[2] != '-' ||
        !isdigit(str[3]) || !isdigit(str[4]) || str[5] != '-' ||
        !isdigit(str[6]) || !isdigit(str[7]) || !isdigit(str[8]) || !isdigit(str[9])) {

        is_correct = false;
    }

    return is_correct;
}

bool is_correct_day(const char *str) 
{
    int day = (str[0] - '0') * 10 + (str[1] - '0');
        
    bool is_correct = true;
    if (day <= 0 || day > NUM_DAY) {
        is_correct = false;
    }

    return is_correct;
}

bool is_correct_month(const char *str) 
{
    int month = (str[3] - '0') * 10 + (str[4] - '0');
     
    bool is_correct = true;   
    if (month <= 0 || month > NUM_MONTH) {
        is_correct = false;
    }

    return is_correct;
}

bool is_correct_year(const char *str) 
{
    int year = (str[6] - '0') * MILLENNIUM + 
                (str[7] - '0') * CENTURY +
                (str[8] - '0') * DECADE +
                (str[9] - '0');

    bool is_correct = true;
    if (year <= MIN_YEAR || year >= MAX_YEAR) {
        
        is_correct = false;
    }

    return is_correct;
}