#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>

#include "correct_input.h"

/*int check_fields(size_t *sum, char **contragent, char **date, struct extension *ext)
{
    int exit_code = SUCCESS;
    return exit_code;
}
*/
int correct_string(const char *str)
{
    int exit_code = SUCCESS;
    
    if (strlen(str) == 0) {
        exit_code = STRING_ERR;
    }
    else {
        for (int i = 0; str[i] != '\0'; i++) {
            if (!isalpha(str[i])) {
                printf("String input is incorrect.\n");
                exit_code = STRING_ERR;
                break;
            }
        }
    }

    return exit_code;
}


int correct_number(const int count)
{
    int exit_code = SUCCESS;

    if (count < 0) {
        printf("Count input is incorrect.\n");
        exit_code = COUNT_ERR;
    }
    
    return exit_code;
}


int correct_date(const char *str)
{
    int exit_code = SUCCESS;

    if (strlen(str) != 10) {
        printf("Date input is incorrect.\n");
        exit_code = DATE_ERR;
    }
    else {
        if (!is_correct_day(str) || str[2] != '-' ||
            !is_correct_month(str) || str[5] != '-' ||
            !is_correct_year(str)) {
            
            printf("Date input is incorrect.\n");
            exit_code = DATE_ERR;
        }
    }

    return exit_code;
}

bool is_correct_day(const char *str) 
{
    if (isdigit(str[0]) && isdigit(str[1])) {
        int day = (str[0] - '0') * 10 + (str[1] - '0');
        
        if (day > 0 && day <= NUM_DAY) {
            return true;
        }
    }

    return false;
}

bool is_correct_month(const char *str) 
{
    if (isdigit(str[3]) && isdigit(str[4])) {
        int month = (str[3] - '0') * 10 + (str[4] - '0');
        
        if (month > 0 && month <= NUM_MONTH) {
            return true;
        }
    }

    return false;
}

bool is_correct_year(const char *str) 
{
    if (isdigit(str[6]) && isdigit(str[7]) && isdigit(str[8]) && isdigit(str[9])) {
        int year = (str[6] - '0') * 1000 +
                    (str[7] - '0') * 100 +
                    (str[8] - '0') * 10 +
                    (str[9] - '0');

        if (year > 1990 && year < 2022) {
            return true;
        }
    }

    return false;
}