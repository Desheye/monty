#include "monty.h"

/**
 * f_mul - multiplies the top two elements of the stack.
 * @stack_head: stack head
 * @line_number: line_number
 * Return: no return
 */
void f_mul(stack_t **stack_head, unsigned int line_number)
{
    stack_t *current;
    int length = 0, result;

    current = *stack_head;
    while (current)
    {
        current = current->next;
        length++;
    }
    if (length < 2)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        fclose(var_global.file);
        free(var_global.buffer);
        free_stack(*stack_head);
        exit(EXIT_FAILURE);
    }
    current = *stack_head;
    result = current->next->n * current->n;
    current->next->n = result;
    *stack_head = current->next;
    free(current);
}

