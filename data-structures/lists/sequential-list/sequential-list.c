//
// Created by dean on 2018/7/4.
//

#include <stdio.h>
#include <stdlib.h>

#include "headers/sequential-list.h"

struct _SeqList
{
    BaseAddress base_addr;      // 存储空间基址
    int length;                 // 表长度
    int size;                   // 表空间大小
};

/**
 * 初始化顺序存储的线性表(顺序表)
 * @param L
 * @return
 */
Status sl_InitList(List L)
{
    L->base_addr = (ElementType *) malloc(INIT_SIZE * sizeof(ElementType));
    if (!L->base_addr)
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
Status sl_DestroyList(List L)
{
    free(L->base_addr);
    L->length = 0;
    L->size = 0;

    return OK;
}

/**
 * 清空线性表
 * @param L
 * @return
 */
Status sl_ClearList(List L)
{
    L->length = 0;

    return OK;
}

/**
 * 判断线性表是否为空
 * @param L
 * @return
 */
Status sl_isListEmpty(const SeqList L)
{
    return L.length == 0 ? TRUE : FALSE;
}

/**
 * 获取线性表当前长度
 * @param L
 * @return
 */
int sl_GetListLen(const SeqList L)
{
    return L.length;
}

/**
 * 获取指定位置的元素,位置从 1 开始
 * @param element
 * @param i i的取值范围：[1, L.length]
 * @param L
 * @return
 */
Status sl_GetElem(const SeqList L, int i, ElementType *elem)
{
    if (i < 1 || i > L.length)
    {
        return ERROR;
    }

    *elem = L.base_addr[i - 1];

    return OK;
}

/**
 * 查找元素所在位置
 * @param L
 * @param elem 所要查找的元素
 */
Status sl_GetElemPos(const SeqList L, ElementType elem)
{
    int i;
    for (i = 0; i < L.length; ++i)
    {
        if (L.base_addr[i] == elem)
        {
            return i + 1;
        }
    }

    if (i == L.length)
    {
        return ERROR;
    }
}

/**
 * 获取前驱元素
 * @param L
 * @param cur_e
 * @param prev_e
 * @return
 */
Status sl_GetPrevElem(const SeqList L, ElementType cur_e, ElementType *prev_e)
{
    // 获取当前元素所在位置
    int p = sl_GetElemPos(L, cur_e);

    if (p && p != 1)
    {
        *prev_e = L.base_addr[(p - 1) - 1];

        return OK;
    }
    else
    {
        return ERROR;
    }
}

/**
 * 在指定位置插入元素
 * @param L
 * @param i 元素要插入的位置，位置范围：[1, L.length + 1]
 * @param elem 要插入的元素
 */
Status sl_InsertElem(SeqList *L, int i, ElementType elem)
{
    ElementType *new_addr;

    if (i < 1 || i > L->length + 1)
    {
        return ERROR;
    }

    // 内存扩容
    if (L->length == L->size)
    {
        new_addr = (BaseAddress) realloc(L->base_addr, (L->size + INCREMENT_SIZE) * (sizeof(ElementType)));
        if (!new_addr)
        {
            printf("内存扩容失败");
            return ERROR;
        }

        L->base_addr = new_addr;
        L->size += INCREMENT_SIZE;
    }

    // 从 p 开始，将数值向后移动一个内存单元
    ElementType *p = &L->base_addr[i - 1];
    ElementType *q = &L->base_addr[L->length - 1];
    for (; q >= p; q--)
    {
        *(q + 1) = *q;
    }

    *p = elem;
    L->length++;

    return OK;
}

/**
 * 删除指定位置的元素，并返回之
 * @param L
 * @param i 取值范围：[1, L.length]
 * @param elem
 */
Status sl_DeleteElem(SeqList *L, int i, ElementType *elem)
{
    if (i < 1 || i > L->length)
    {
        return ERROR;
    }

    ElementType *p = &L->base_addr[i - 1];
    *elem = *p;

    ElementType *q = &L->base_addr[L->length - 1];
    for (; p < q; p++)
    {
        *p = *(p + 1);
    }

    L->length--;

    return OK;
}

/**
 * 打印元素
 * @param elem
 */
void sl_visitElem(ElementType elem)
{
    printf("%d\n", elem);
}

/**
 * 遍历线性表
 * @param L
 * @param visit
 * @return
 */
Status sl_TraverseList(const SeqList L, void(*sl_visitElem)(ElementType))
{
    for (int i = 0; i < L.length; ++i)
    {
        sl_visitElem(L.base_addr[i]);
    }

    return OK;
}

/**
 * 测试顺序存储的线性表
 */
void sl_TestSequentialList()
{

    SeqList L;
    if (sl_InitList(&L))
    {
        ElementType e;
        printf("init_success\n");

        for (int i = 0; i < 10; i++)
        {
            sl_InsertElem(&L, i + 1, i);
        }
        printf("length is %d\n", sl_GetListLen(L));

        if (sl_GetElem(L, 1, &e))
        {
            printf("The first element is %d\n", e);
        }
        else
        {
            printf("element is not exist\n");
        }

        if (sl_isListEmpty(L))
        {
            printf("list is empty\n");
        }
        else
        {
            printf("list is not empty\n");
        }
        printf("The 5 at %d\n", sl_GetElemPos(L, 5));

        sl_GetPrevElem(L, 6, &e);
        printf("The 6's previous element is %d\n", e);

//        NextElem(L, 6, &e);
//        printf("The 6's next element is %d\n", e);

        sl_DeleteElem(&L, 1, &e);
        printf("delete first element is %d\n", e);

        printf("list:");
        sl_TraverseList(L, sl_visitElem);

        if (sl_DestroyList(&L))
        {
            printf("\ndestroy_success\n");
        }
    }
}















