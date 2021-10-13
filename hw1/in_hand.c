#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include "in_hand.h"
#include "correct_input.c"

int input_handler(struct contract **array, size_t *size)
{
    size_t max_size = 1;
    int exit_code = create_array(array, max_size);
    
    while (exit_code == SUCCESS) {
        printf("Input contract\n");

        struct contract cur_contract;
        exit_code = input_contract(&cur_contract);

        if (exit_code == SUCCESS) {
            increase_memory(array, &max_size, *size);

            (*array)[(*size)] = cur_contract;
            (*size)++;
        }
    }

    exit_code = realloc_memory(array, *size);

    return exit_code;
}

int input_contract(struct contract *cur_contract)
{
    int exit_code = SUCCESS;

    char *type = get_string("\tInput type: ");
    if (strcmp(type, "none") == 0) {
        free(type);
        exit_code = END_INPUT;
    }

    if (exit_code == SUCCESS) {
        size_t sum = 0;
        char *contragent = NULL, *date = NULL;
        struct extension ext;
        
        input_fields(&sum, &contragent, &date, &ext);
        exit_code = check_fields(sum, contragent, date, ext);
        
        if (exit_code == SUCCESS) {
            (*cur_contract).type = type;
            (*cur_contract).sum = sum;
            (*cur_contract).contragent = contragent;
            (*cur_contract).date = date;
            (*cur_contract).extension = ext;
        }
        else {
            free_fields(&type, &contragent, &date, &ext);
        }

    }

    return exit_code;
}

void input_fields(size_t *sum, char **contragent, char **date, struct extension *ext)
{
    *sum = get_number("\tInput sum: ");
    getchar();
    
    *contragent = get_string("\tInput contragent: ");
    *date = get_string("\tInput date (dd-mm-yyyy): ");
        
    printf("\tInput extension\n");
    (*ext).desc = get_string("\t\tInput description: ");                         
    (*ext).amount = get_number("\t\tInput extension: ");
    getchar();
}

char *get_string(const char *msg)
{
    printf("%s", msg);
    char *str = (char *) malloc(sizeof(char));
    if (str != NULL) {
        str[0] = '\0';

        char symb = '0';
        int i = 0;
        while (scanf("%c", &symb) == 1) {
            i++;
            str = (char *) realloc(str, i * sizeof(char));
            if (symb != '\n') {
                str[i - 1] = symb;
            }
            else {
                str[i - 1] = '\0';
                break;
            }
        }
    }

    return str;
}

int get_number(const char *msg)
{
    int count = 0;

    printf("%s", msg);
    scanf("%d", &count);

    return count;
}