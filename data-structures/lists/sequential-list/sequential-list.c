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
    BaseAddress base_addr;    // 存储空间基址
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
Status DestroyList(List L)
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
Status GetElem(const SeqList L, int i, ElementType *elem)
{
    if (i < 1 || i > L.length)
    {
        return ERROR;
    }

    *elem = L.base_addr[i - 1];

    return OK;
}

/**
 * 比较两个元素大小
 * @param e1
 * @param e2
 * @return
 */
int compare(ElementType e1, ElementType e2)
{
    if (e1 == e2)
    {
        return 0;
    }
    else if (e1 < e2)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

/**
 * 查找元素所在位置
 * @param L
 * @param e
 * @param compare
 * @return
 */
Status FindElem(const SeqList L, ElementType e, int(*compare)(ElementType, ElementType))
{
    for (int i = 0; i < L.length; ++i)
    {
        if (!(*compare)(L.base_addr[i], e))
        {
            return i + 1;
        }
    }

    return ERROR;
}

/**
 * 获取前驱元素
 * @param L
 * @param cur_e
 * @param prev_e
 * @return
 */
Status PrevElem(const SeqList L, ElementType cur_e, ElementType *prev_e)
{
    int cur_e_pos = FindElem(L, cur_e, compare);

    if (cur_e_pos && cur_e_pos != 1)
    {
        *prev_e = L.base_addr[cur_e_pos - 2];

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
 * @param i
 * @param elem
 * @return
 */
Status Insert(SeqList *L, int i, ElementType elem)
{
    ElementType *new_addr;

    if (i < 1 || i > L->length + 1)
    {
        return ERROR;
    }

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

    /**
     * 从 p 开始，将数值向后移动一个内存单元
     */
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
 * @param i
 * @param elem
 * @return
 */
Status Delete(SeqList *L, int i, ElementType *elem)
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
void visit(ElementType elem)
{
    printf("%d\n", elem);
}

/**
 * 遍历线性表
 * @param L
 * @param visit
 * @return
 */
Status Traverse(const SeqList L, void(*visit)(ElementType))
{
    for (int i = 0; i < L.length; ++i)
    {
        visit(L.base_addr[i]);
    }

    return OK;
}

/**
 * 测试
 */
void Test()
{

    SeqList L;
    if (InitList(&L))
    {
        ElementType e;
        printf("init_success\n");

        for (int i = 0; i < 10; i++)
        {
            Insert(&L, i + 1, i);
        }
        printf("length is %d\n", getLength(L));

        if (GetElem(L, 1, &e))
        {
            printf("The first element is %d\n", e);
        }
        else
        {
            printf("element is not exist\n");
        }

        if (isEmpty(L))
        {
            printf("list is empty\n");
        }
        else
        {
            printf("list is not empty\n");
        }
        printf("The 5 at %d\n", FindElem(L, 5, compare));

        PrevElem(L, 6, &e);
        printf("The 6's previous element is %d\n", e);

//        NextElem(L, 6, &e);
//        printf("The 6's next element is %d\n", e);

        Delete(&L, 1, &e);
        printf("delete first element is %d\n", e);

        printf("list:");
        Traverse(L, visit);
        if (DestroyList(&L))
        {
            printf("\ndestroy_success\n");
        }
    }
}















