//
// Created by dean on 2018/7/1.
//

#include <stdio.h>
#include <stdlib.h>

#include "headers/one-way-linked-list.h"

struct Node
{
    ElementType data;
    Position next;
};

/*
 * 初始化链式线性表
 */
List ssl_InitList()
{
    List header = (List) malloc(sizeof(struct Node));
    if (!header)
    {
        exit(OVERFLOW);
    }
    header->next = NULL;

    return header;
}

/**
 * 在指定位置插入元素
 * 除表头外的第一个结点的索引是 0
 * @param data 所插入结点数据域的值
 * @param list 链表的地址
 * @param i    结点插入的索引位置 大于等于0 小于等于链表的长度
 */
Status ssl_InsertNode(ElementType data, List list, int i)
{
    Position tmpCell;
    List p = list;

    for (int j = 0; j < i; ++j)
    {
        if (p != NULL)
        {
            p = p->next;
        }
    }

    if (p == NULL)
    {
        return ERROR;
    }

    tmpCell = (List) malloc(sizeof(struct Node));
    tmpCell->data = data;
    tmpCell->next = p->next;

    p->next = tmpCell;
    return OK;
}

/**
 * 打印结点数据域的值
 */
void ssl_visitNode(ElementType data)
{
    printf("%d", data);
}

/**
 * 遍历链式线性表
 */
void ssl_TraverseList(List header, void(*print)(ElementType))
{
    Position p = header->next;
    while (p)
    {
        ssl_visitNode(p->data);
        p = p->next;
    }
}

/**
 * 判断链表是否为空
 * @param list
 * @return
 */
Status ssl_isListEmpty(List header)
{
    if (header->next == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 * 获取链表长度
 * @param header
 * @return
 */
int ssl_GetListLen(List header)
{
    int len = 0;
    Position p = header->next;

    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

/**
 * 获取元素结点所在内存地址
 * @param data
 * @param header
 * @return Position
 */
Position ssl_getNodeAddr(ElementType data, List header)
{
    Position p = header->next;

    // 方法一
    while (p != NULL)
    {
        if (p->data == data)
        {
            return p;
        }
        p = p->next;
    }

    return NULL;

    /*// 方法二
    while (p != NULL)
    {
        if (p->data == data)
        {
            break;
        }
        p = p->next;
    }
    return p;*/
}

/**
 * 获取前驱结点位置
 * @param data
 * @param header
 * @return
 */
Position ssl_getPrevNodeAddr(ElementType data, List header)
{
    Position p = header->next;

    if (p->data == data)
    {
        return header;
    }

    while (p->next != NULL)
    {
        if (p->next->data == data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

/**
 * 删除结点
 * @param data
 * @param header
 * @return
 */
void ssl_DelNode(ElementType data, List header)
{
    Position cur_node = ssl_getNodeAddr(data, header);

    if (cur_node != NULL)
    {
        Position prev_node;
        // 如果是最后一个结点
        if (cur_node->next == NULL)
        {
            prev_node = ssl_getPrevNodeAddr(cur_node->data, header);
            prev_node->next = NULL;
            free(cur_node);
        }
            // 如果不是最后一个结点，将此结点数据域的值和下一个结点交换
            // 以避免再次对链表进行遍历
        else
        {
            Position next_node = cur_node->next;
            cur_node->data = next_node->data;
            cur_node->next = next_node->next;
            free(cur_node->next);
        }
    }
}
