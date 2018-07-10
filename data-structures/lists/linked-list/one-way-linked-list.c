//
// Created by dean on 2018/7/1.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "headers/one-way-linked-list.h"

struct _ssl_Node
{
    ElementType data;
    Position next;
};

/*
 * 初始化链表
 */
List ssl_InitList()
{
    List header = (List) malloc(sizeof(ssl_Node));
    if (!header)
    {
        exit(OVERFLOW);
    }
    header->next = NULL;

    return header;
}

/**
 * 销毁链表
 * @param p
 */
void ssl_DestroyList(Position *p)
{
    Position tmpCell;

    while (*p)
    {
        tmpCell = (*p)->next;
        free(*p);
        *p = tmpCell;
    }
}

/**
 * 清空链表
 * @param list
 */
void ssl_ClearList(List header)
{
    Position p = header->next;
    header->next = NULL;

    ssl_DestroyList(&p);
}

/**
 * 在指定位置插入元素
 * 除表头外的第一个结点的索引是 0
 * @param data 所插入结点数据域的值
 * @param list 链表的地址
 * @param i    结点插入的位置 取值范围：[1, list.length + 1]
 */
Status ssl_InsertNode(ElementType data, List header, int i)
{
    Position tmpCell;
    Position p = header;

    for (int j = 1; j < i; ++j)
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

    tmpCell = (List) malloc(sizeof(ssl_Node));
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
bool ssl_isEmpty(List header)
{
    Position p = header->next;

    return p == NULL;
}

/**
 * 获取链表长度
 * @param header
 * @return
 */
int ssl_GetLen(List header)
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
void ssl_DeleteNode(ElementType data, List header)
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
