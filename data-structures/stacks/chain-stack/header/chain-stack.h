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

typedef struct _ChainStack
{
    Node *top;
} ChainStack;

void initStack(ChainStack *s);

int isStackFull(ChainStack *s);

int isStackEmpty(ChainStack *s);

void push(ChainStack *s, char c);

char pop(ChainStack *s);

void resetChainStack(ChainStack *s);

void destroyChainStack(ChainStack *s);

#endif //ALGORITHMS_CHAIN_STACK_H
