#include "monty.h"

/**
 * execute_instruction - executes the opcode
 * @line_content: line content
 * @stack: head linked list - stack
 * @line_number: line_counter
 * @monty_file: pointer to monty file
 * Return: no return
 */
int execute_instruction(char *line_content, stack_t **stack, unsigned int line_number, FILE *monty_file)
{
    instruction_t opcodes[] = {
        {"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
        {"pop", f_pop},
        {"swap", f_swap},
        {"add", f_add},
        {"nop", f_nop},
        {"sub", f_sub},
        {"div", f_div},
        {"mul", f_mul},
        {"mod", f_mod},
        {"pchar", f_pchar},
        {"pstr", f_pstr},
        {"rotl", f_rotl},
        {"rotr", f_rotr},
        {"queue", f_queue},
        {"stack", f_stack},
        {NULL, NULL}
    };

    unsigned int i = 0;
    char *opcode;

    opcode = strtok(line_content, " \n\t");
    if (opcode && opcode[0] == '#')
        return (0);

    var_global.push_arg = strtok(NULL, " \n\t");

    while (opcodes[i].opcode && opcode)
    {
        if (strcmp(opcode, opcodes[i].opcode) == 0)
        {
            opcodes[i].f(stack, line_number);
            return (0);
        }
        i++;
    }

    if (opcode && opcodes[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
        fclose(monty_file);
        free(line_content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    return (1);
}

