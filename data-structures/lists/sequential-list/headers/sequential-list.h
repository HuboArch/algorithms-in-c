//
// Created by dean on 2018/7/5.
//

#ifndef ALGORITHMS_SEQUENTIAL_LIST_H
#define ALGORITHMS_SEQUENTIAL_LIST_H

#define INIT_SIZE 10            // 初始表空间大小
#define INCREMENT_SIZE 5        // 空间分配增量

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef int ElementType;
typedef int Status;

struct _SeqList;
typedef struct _SeqList SeqList;
typedef ElementType *PtrToElementType;
typedef PtrToElementType BaseAddress;
typedef SeqList *PtrToSeqList;
typedef PtrToSeqList List;

Status InitList(List L);

Status DestroyList(List L);

Status ClearList(List L);

Status isEmpty(SeqList L);

int getLength(SeqList L);

Status GetElem(SeqList L, int i, ElementType *elem);

int compare(ElementType e1, ElementType e2);

Status FindElem(SeqList L, ElementType e, int(*compare)(ElementType, ElementType));

Status PrevElem(SeqList L, ElementType cur_e, ElementType *prev_e);

Status Insert(SeqList *L, int i, ElementType elem);

Status Delete(SeqList *L, int i, ElementType *elem);

void visit(ElementType elem);

Status Traverse(SeqList L, void(*visit)(ElementType));

void Test();

#endif //ALGORITHMS_SEQUENTIAL_LIST_H
