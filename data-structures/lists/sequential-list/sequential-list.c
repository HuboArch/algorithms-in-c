//
// Created by dean on 2018/7/4.
//

#include <stdio.h>
#include <stdlib.h>

#include "../headers/list.h"

#define INIT_SIZE 10            // 初始表空间大小
#define INCREMENT_SIZE 5        // 空间分配增量

struct _SeqList;
typedef struct _SeqList SeqList;
typedef ElementType *PtrToElementType;
typedef PtrToElementType BaseAddress;
typedef SeqList *PtrToSeqList;
typedef PtrToSeqList List;

struct _SeqList
{
    BaseAddress baseAddress;    // 存储空间基址
    int length;                 // 表长度
    int size;                   // 表空间大小
};

/**
 * 初始化顺序存储的线性表(顺序表)
 * @param L
 * @return
 */
Status InitList(List L)
{
    L->baseAddress = (ElementType *) malloc(INIT_SIZE * sizeof(ElementType));
    if (!L->baseAddress)
    {
        return ERROR;
    }

    L->length = 0;
    L->size = INIT_SIZE;

    return OK;
}

/**
 * 销毁线性表
 * @param L
 * @return
 */
Status DestroyList(List L)
{
    free(L->baseAddress);
    L->length = 0;
    L->size = 0;

    return OK;
}

/**
 * 清空线性表
 * @param L
 * @return
 */
Status ClearList(List L)
{
    L->length = 0;

    return OK;
}

/**
 * 判断线性表是否为空
 * @param L
 * @return
 */
Status isEmpty(const SeqList L)
{
    if (L.length == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 * 获取线性表当前长度
 * @param L
 * @return
 */
int getLength(const SeqList L)
{
    return L.length;
}

/**
 * 获取指定位置的元素,索引从 1 开始
 * @param element
 * @param i
 * @param L
 * @return
 */
Status GetElem(ElementType *elem, int i, const SeqList L)
{
    if (i < 1 || i > L.length)
    {
        return ERROR;
    }

    *elem = L.baseAddress[i - 1];

    return OK;
}




