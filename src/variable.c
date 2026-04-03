#include "variable.h"

bool variable_compare(struct Variable left, struct Variable right)
{
        if (left.letter != right.letter)
                return false;

        return left.subscript == right.subscript;
}

bool variable_search(void *left, void *right)
{
        struct Variable var_left = *(struct Variable *)left;
        struct Variable var_right = *(struct Variable *)right;

        return variable_compare(var_left, var_right);
}