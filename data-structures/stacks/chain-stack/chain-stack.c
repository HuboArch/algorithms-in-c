////
//// Created by dean on 2018/7/3.
////
//
//#include <stdlib.h>
//
//#include "header/chain-stack.h"
//
//void initStack(ChainStack *s)
//{
//    s->top = (Node *) malloc(sizeof(Node));
//    s->top->next = NULL;
//}
//
//int isStackFull(ChainStack *s)
//{
//    // TODO  has't implementation
//}
//
//int isStackEmpty(ChainStack *s)
//{
//    return s->top->next == NULL;
//}
//
//void push(ChainStack *s, char c)
//{
//    Node *cur_node = (Node *) malloc(sizeof(Node));
//    cur_node->next = s->top->next;
//
//    s->top->next = cur_node;
//}
//
//char pop(ChainStack *s)
//{
//    Node *t = s->top->next;
//    char c = t->data;
//
//    s->top->next = t->next;
//    free(t);
//
//    return c;
//}
//
//void resetChainStack(ChainStack *s)
//{
//    while (!isStackEmpty(s))
//    {
//        pop(s);
//    }
//}
//
//void destroyChainStack(ChainStack *s)
//{
//    resetChainStack(s);
//    free(s->top);
//}