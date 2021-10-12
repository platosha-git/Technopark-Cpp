/*  Вариант #36
  Создать структуру для хранения информации о договорах: 
  виде и сумме договора, наименовании контрагента, дате заключения и наличии дополнительных соглашений. 
  Составить с ее использованием программу поиска информации о трех ключевых контрагентах компании, 
  общая сумма договоров с которыми (с учетом дополнительных соглашений) максимальна. 
*/

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
    
#include "in_hand.h"
#include "search.h"  
#include "out_hand.h"

int fill_and_find(struct contract **contracts_array, size_t *size)
{
    int exit_code = input_handler(contracts_array, size);
    if (exit_code == SUCCESS) {
        search_agent(*contracts_array, *size);
    }

    free_array(contracts_array, *size);

    return exit_code;
}

int main(void)
{    
    struct contract *contracts_array = NULL;
    size_t size = 0;

    int exit_code = fill_and_find(&contracts_array, &size);

    return exit_code;
}

