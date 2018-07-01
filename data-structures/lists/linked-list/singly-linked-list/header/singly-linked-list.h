//
// Created by dean on 2018/7/1.
//

#ifndef ALGORITHMS_SINGLY_LINKED_LIST_H
#define ALGORITHMS_SINGLY_LINKED_LIST_H

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef int ElementType;
typedef int Status;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List initList();

void print(ElementType data);

void traverseList(List header, void(*print)(ElementType));

List makeEmpty(List l);

Status isEmpty(List header);

int getLength(List header);

Position getPosition(ElementType data, List header);

void delete(ElementType data, List header);

Status isLast(Position p, List l);

Position getPrevious(ElementType data, List header);

Status insert(ElementType data, List list, int i);

void deleteList(List l);

Position header(List l);

Position first(List l);

Position advance(Position p);

ElementType retrieve(Position p);


#endif //ALGORITHMS_SINGLY_LINKED_LIST_H

