#include <stdio.h>
#include <stdlib.h>

/**
 * 链式线性表（带头结点）
*/

#define ElemType int

typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

/**
 * 初始化链表
*/
bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));    
    return true;
}

/**
 * 在链表 list 的第 i 个位置插入元素 e
*/
bool ListInsert_L(LinkList &L, int i, ElemType e) {
    LNode* p = L;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1) {
        return false;
    }
    LNode* eNode = (LNode *) malloc(sizeof(LNode));
    eNode->data = e;
    eNode->next = p->next;
    p->next = eNode;
    return true;
}

/**
 * 获取线性表第 i 个位置的元素，并返回 e
*/
bool GetElem(LinkList L, int i, ElemType &e) {
    // p 指向第一个结点
    LNode* p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i) {
        return false;
    }
    e = p->data;
    return true;
}

/**
 * 删除线性表第 i 个元素，并返回 e
*/
bool ListDelete_L(LinkList &L, int i, ElemType &e) {
    LNode* p = L;
    int j = 0;
    // 查找删除位置的前驱
    while (p->next && j < i-1) {
        p = p->next;
        j++;
    }
    if (!(p->next)) {
        return false;
    }
    // 要删除的结点
    LNode* q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return true;
}

/**
 * 输入元素值，建立单链表
*/
void CreateList_L(LinkList &L, int n) {
    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    for (int i = n; i > 0; i--) {
        LNode* p = (LNode *) malloc(sizeof(LNode));
        scanf("%d", &(p->data));
        p->next = L->next;
        L->next = p;
    }
}

/**
 * 输出单链表
*/
void PrintList_L(LinkList L) {
    LNode* node = L->next;
    while (node != NULL) {
        printf("%d\t", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    LinkList list;
    // InitList(list);
    // ListInsert_L(list, 1, 20);
    // ListInsert_L(list, 1, 10);
    // ListInsert_L(list, 2, 40);
    // ListInsert_L(list, 3, 30);
    // ListInsert_L(list, 5, 50);
    // ElemType e = -1;
    // GetElem(list, 1, e);
    // printf("get e = %d\n", e);
    // ListDelete_L(list, 6, e);
    // printf("delete e = %d\n", e);

    CreateList_L(list, 5);

    PrintList_L(list);

    return 0;
}