//
// Created by dean on 2018/7/1.
//

#ifndef ALGORITHMS_STACK_H
#define ALGORITHMS_STACK_H

#include <stdbool.h>

typedef struct _Stack
{
    int _len;
    int _top;
    char *_space;
} Stack;

void initStack(Stack *s, int size);

bool isStackFull(Stack *s);

bool isStackEmpty(Stack *s);

void push(Stack *s, char ch);

int pop(Stack *s);

void resetStack(Stack *s);

void destroyStack(Stack *s);

#endif //ALGORITHMS_STACK_H
