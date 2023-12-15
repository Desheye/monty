#include "monty.h"

/**
 * f_pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @stack_head: stack head
 * @line_number: line_number
 * Return: no return
*/
void f_pstr(stack_t **stack_head, unsigned int line_number)
{
    stack_t *current;
    (void)line_number;

    current = *stack_head;
    while (current)
    {
        if (current->n > 127 || current->n <= 0)
        {
            break;
        }
        printf("%c", current->n);
        current = current->next;
    }
    printf("\n");
}

