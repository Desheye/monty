#include "monty.h"

/**
 * f_push - add node to the stack
 * @stack_head: stack head
 * @line_number: line_number
 * Return: no return
*/
void f_push(stack_t **stack_head, unsigned int line_number)
{
    int value, index = 0, invalid_flag = 0;

    if (var_global.push_arg)
    {
        if (var_global.push_arg[0] == '-')
            index++;
        for (; var_global.push_arg[index] != '\0'; index++)
        {
            if (var_global.push_arg[index] > '9' || var_global.push_arg[index] < '0')
                invalid_flag = 1;
        }
        if (invalid_flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            fclose(var_global.file);
            free(var_global.buffer);
            free_stack(*stack_head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        fclose(var_global.file);
        free(var_global.buffer);
        free_stack(*stack_head);
        exit(EXIT_FAILURE);
    }

    value = atoi(var_global.push_arg);
    if (var_global.lifo == 0)
        add_node_to_stack(stack_head, value);
    else
        add_node_to_queue(stack_head, value);
}

