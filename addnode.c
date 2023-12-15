#include "monty.h"

/**
 * add_node_to_stack - add node to the head of the stack
 * @stack_head: head of the stack
 * @value: new_value
 * Return: no return
*/
void add_node_to_stack(stack_t **stack_head, int value)
{
    stack_t *new_node, *current;

    current = *stack_head;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }

    if (current)
        current->prev = new_node;

    new_node->n = value;
    new_node->next = *stack_head;
    new_node->prev = NULL;
    *stack_head = new_node;
}

