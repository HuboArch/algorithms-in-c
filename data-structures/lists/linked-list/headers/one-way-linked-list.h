//
// Created by dean on 2018/7/5.
//

#ifndef ALGORITHMS_ONE_WAY_LINKED_LIST_H
#define ALGORITHMS_ONE_WAY_LINKED_LIST_H

#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef int ElementType;
typedef int Status;

struct _ssl_Node;
typedef struct _ssl_Node ssl_Node;
typedef ssl_Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List ssl_InitList();

Status ssl_InsertNode(ElementType data, List list, int i);

void ssl_visitNode(ElementType data);

void ssl_TraverseList(List header, void(*print)(ElementType));

bool ssl_isEmpty(List header);

int ssl_GetLen(List header);

Position ssl_getNodeAddr(ElementType data, List header);

Position ssl_getPrevNodeAddr(ElementType data, List header);

void ssl_DeleteNode(ElementType data, List header);

#endif //ALGORITHMS_ONE_WAY_LINKED_LIST_H
