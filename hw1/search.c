#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "search.h"
#include "out_hand.h"

void search_agent(const struct contract *array, const size_t size)
{
    struct agent *res_array = create_res_array(array, size);
    sort_contracts(res_array, size, cmp_sum);
    
    char *(res_agents)[num_agents];
    size_t found_agents = get_agents(&res_agents, res_array, size);
    output_result(res_agents, found_agents);

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


size_t get_agents(char *(*res_agents)[num_agents], const struct agent *res_array, const size_t size)
{
    size_t idx_agent = 0;

    for (size_t i = 0; i < size && idx_agent < num_agents; i++) {
        char *cur_agent = res_array[i].name;

        bool is_new_agent = true;
        for (size_t j = 0; j < idx_agent; j++) {
            if (strcmp((*res_agents)[j], cur_agent) == 0) {
                is_new_agent = false;
                break;
            }
        }

        if (is_new_agent) {
            (*res_agents)[idx_agent] = cur_agent;
            idx_agent++;
        }
    }

    return idx_agent;
}
