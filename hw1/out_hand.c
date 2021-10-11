#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include "out_hand.h"

void output_struct(const struct contract *array, const size_t size)
{
    printf("\n");
    for (size_t i = 0; i < size; i++) {
        printf("type = %s\n", array[i].type);
        printf("sum = %d\n", array[i].sum);
        printf("contragent = %s\n", array[i].contragent);
        printf("date = %s\n", array[i].date);
        printf("extension = %s\n", array[i].extension.desc);
        printf("extension = %d\n\n", array[i].extension.amount);
    }
}

void output_result(const char *str1, const char *str2, const char *str3)
{
    if (str1 != NULL) {
        printf("Agent 1: %s\n", str1);
    }

    if (str2 != NULL) {
        printf("Agent 2: %s\n", str2);
    }

    if (str3 != NULL) {
        printf("Agent 3: %s\n", str3);
    }
}