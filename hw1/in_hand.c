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

        char *type = get_string("\tInput type: ");
        if (strcmp(type, "none") == 0) {
            free(type);
            break;
        }

        exit_code = correct_string(type);

        if (exit_code == SUCCESS) {
            size_t sum = get_number("\tInput sum: ");
            getchar();
            exit_code = correct_number(sum);

            if (exit_code == SUCCESS) {
                char *contragent = get_string("\tInput contragent: ");
                exit_code = correct_string(contragent);

                if (exit_code == SUCCESS) {
                    char *date = get_string("\tInput date (dd-mm-yyyy): ");
                    exit_code = correct_date(date);

                    if (exit_code == SUCCESS) {
                        printf("\tInput extension\n");
                        
                        struct extension ext;
                        ext.desc = get_string("\t\tInput description: ");                         
                        ext.amount = get_number("\t\tInput extension: ");
                        getchar();

                        if (exit_code == SUCCESS) {
                            increase_memory(array, &max_size, *size);
                            node_constructor(array, *size, type, sum, contragent, date, ext);
                            (*size)++;
                        }
                        else {
                            free(ext.desc);
                            free(date);
                            free(contragent);
                            free(type);
                            break;
                        }
                    }
                    else {
                        free(date);
                        free(contragent);
                        free(type);
                        break;
                    }
                }
                else {
                    free(contragent);
                    free(type);
                    break;
                }
            } 
            else {            
                free(type);
                break;
            }
        }
        else {
            free(type);
            break;
        }
    }

    exit_code = realloc_memory(array, *size);

    return exit_code;
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

void node_constructor(struct contract **array, const size_t size, 
                        char *type, int sum, char *contragent, char *date, struct extension ext)
{
    (*array)[size].type = type;
    (*array)[size].sum = sum;
    (*array)[size].contragent = contragent;
    (*array)[size].date = date;
    (*array)[size].extension = ext;
}