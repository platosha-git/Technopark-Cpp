#ifndef CHANGES_H
#define CHANGES_H

#include "exit_codes.h"
#include "mem_operations.h"

const static size_t num_agents = 3;

struct agent
{
	char *name;
	int sum;
};

void search_agent(const struct contract *contracts_array, const size_t size);

struct agent *create_res_array(const struct contract *array, const size_t size);

void sort_contracts(struct agent *base, const size_t num, int (*cmp)(struct agent, struct agent));
int cmp_sum(struct agent a, struct agent b);

size_t get_agents(char *(*res_agents)[num_agents], const struct agent *res_array, const size_t size);

#endif