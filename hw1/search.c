#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>

#include "search.h"
#include "out_hand.h"

void search_agent(const struct contract *array, const size_t size)
{
    struct agent *res_array = create_res_array(array, size);

    sort_contracts(res_array, size, cmp_sum);
    
    char *str1 = NULL, *str2 = NULL, *str3 = NULL;
    get_angents(&str1, &str2, &str3, res_array, size);

    output_result(str1, str2, str3);

    free(res_array);
}


struct agent *create_res_array(const struct contract *array, const size_t size)
{
    struct agent *res_array = (struct agent *) malloc(size * sizeof(struct agent));
    
    for (size_t i = 0; i < size; i++) {
        char *cur_agent = array[i].contragent;
        
        int full_sum = 0;
        for (size_t j = i; j < size; j++) {
            if (strcmp(array[j].contragent, cur_agent) == 0) {
                full_sum += array[j].sum + array[j].extension.amount;
            }
        }

        res_array[i].name = cur_agent;
        res_array[i].sum = full_sum;
    }

    return res_array;
}

void sort_contracts(struct agent *base, const size_t num, int (*cmp)(struct agent, struct agent))
{
    for (size_t i = 0; i < num; i++ ) {
        for (size_t j = 1; j < num - i; j++) {
            if (cmp(base[j - 1], base[j]) < 0) {
                struct agent temp = base[j - 1];
                base[j - 1] = base[j];
                base[j] = temp;
            }
        }
    }
}

int cmp_sum(struct agent a, struct agent b)
{
    return a.sum - b.sum;
}


void get_angents(char **str1, char **str2, char **str3, 
                const struct agent *res_array, const size_t size)
{
    for (size_t i = 0; i < size; i++) {
        char *cur_str = res_array[i].name;

        if (*str1 == NULL) {
            *str1 = cur_str;
            continue;
        }

        if (*str2 == NULL && strcmp(*str1, cur_str) != 0) {
            *str2 = cur_str;
            continue;
        }

        if (*str3 == NULL && strcmp(*str1, cur_str) != 0 && strcmp(*str2, cur_str) != 0) {
            *str3 = cur_str;
            break;
        }
    }
}
