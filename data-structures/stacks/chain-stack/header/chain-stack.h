//
// Created by dean on 2018/7/3.
//

#ifndef ALGORITHMS_CHAIN_STACK_H
#define ALGORITHMS_CHAIN_STACK_H

typedef struct _Node
{
    char data;
    struct _Node *next;
} Node;

typedef struct _Stack
{
    Node *top;
} Stack;

void initStack(Stack *s);

int isStackFull(Stack *s);

int isStackEmpty(Stack *s);

void push(Stack *s, char c);

char pop(Stack *s);

#endif //ALGORITHMS_CHAIN_STACK_H
