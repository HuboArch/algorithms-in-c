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

Status sl_InitList(List L);

Status sl_DestroyList(List L);

Status sl_ClearList(List L);

Status sl_isListEmpty(SeqList L);

int sl_GetListLen(SeqList L);

Status sl_GetElem(SeqList L, int i, ElementType *elem);

Status sl_GetElemPos(SeqList L, ElementType e);

Status sl_GetPrevElem(SeqList L, ElementType cur_e, ElementType *prev_e);

Status sl_InsertElem(SeqList *L, int i, ElementType elem);

Status sl_DeleteElem(SeqList *L, int i, ElementType *elem);

void sl_visitElem(ElementType elem);

Status sl_TraverseList(SeqList L, void(*sl_visitElem)(ElementType));

void sl_TestSequentialList();

#endif //ALGORITHMS_SEQUENTIAL_LIST_H
