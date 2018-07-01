//
// Created by dean on 2018/7/1.
//

#ifndef ALGORITHMS_SINGLY_LINKED_LIST_H
#define ALGORITHMS_SINGLY_LINKED_LIST_H

typedef int ElementType;
typedef int Status;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List makeEmpty(List l);

Status isEmpty(List l);

Status isLast(Position p, List l);

Position find(ElementType x, List l);

void delete(ElementType x, List l);

Position findPrevious(ElementType x, List l);

void insert(ElementType x, List l, Position p);

void deleteList(List l);

Position header(List l);

Position first(List l);

Position advance(Position p);

ElementType retrieve(Position p);


#endif //ALGORITHMS_SINGLY_LINKED_LIST_H

