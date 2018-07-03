//
// Created by dean on 2018/7/1.
//
#include <stdlib.h>

#include "header/stack.h"


void initStack(Stack *s, int size)
{
    s->_top = 0;
    s->_len = size;
    s->_space = (char *) malloc(sizeof(char) * s->_len);
}

bool isStackFull(Stack *s)
{
    return s->_top == s->_len;
}

bool isStackEmpty(Stack *s)
{
    return s->_len == 0;
}

void push(Stack *s, char ch)
{
    s->_space[s->_top] = ch;
    s->_top++;
}

int pop(Stack *s)
{
    s->_top--;
    return s->_space[s->_top];
}

void resetStack(Stack *s)
{
    s->_top = 0;
}

void destroyStack(Stack *s)
{
    free(s->_space);
}