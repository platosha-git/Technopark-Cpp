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

output_result(char *(*res_agents), const size_t num)
{
    for (size_t i = 0; i < num; i++) {
        printf("Agent %ld: %s\n", i + 1, res_agents[i]);
    }
    printf("\n");
}