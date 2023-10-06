#include <stdio.h>
#include <stdlib.h>

/**
 * 顺序线性表 
 */

#define LIST_INIT_SIZE 5 // 线性表存储空间的初始分配量
#define LISTINCREMENT 10 // 线性表存储空间的分配增量
#define ElemType int

typedef struct {
    ElemType *elem;
    int length; // 当前长度
    int listsize; // 当前分配的存储容量 以 ElemType 为单位
} SqList;

/**
 * 初始化线性表
*/
bool InitList_Sq(SqList &L) {
    L.elem = (ElemType *) malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    if (!L.elem) {
        return false;
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return true;
}

/**
 * 在表 L 的第 i 个元素之前插入一个元素 e
*/
bool ListInsert_Sq(SqList &L, int i, ElemType e) {
    // 判断位置的合法性
    if (i < 1 || i > L.length + 1) {
        return false;
    }
    // 存储空间不够
    if (L.length >= L.listsize) {
        // 开辟新空间，增加分配
        ElemType* newbase = (ElemType *) realloc(L.elem, sizeof(ElemType)*(L.length+LISTINCREMENT));
        if (!newbase) {
            return false;
        }
        L.elem = newbase;
        L.listsize = L.length + LISTINCREMENT;
    }
    // 插入位置 地址位置
    ElemType* insert = &(L.elem[i-1]);
    // 后移元素
    for (ElemType* p = &(L.elem[L.length-1]); p >= insert; --p) {
        *(p+1) = *p;
    }
    // 修改插入位置的值
    *insert = e;
    // 修改表长
    L.length++;
    return true;
}

/**
 * 将表 L 的第 i 个元素删除，并将删除元素返回 e
*/
bool ListDelete_Sq(SqList &L, int i, ElemType &e) {
    // 判断位置合法性
    if (i < 1 || i > L.length) {
        return false;
    }
    // 删除位置
    ElemType* del = &(L.elem[i-1]);
    // 返回元素
    e = *del;
    // 前移元素
    for (ElemType* p = del; p < &(L.elem[L.length-1]); p++) {
        *p = *(p+1);
    }
    // 重置最后一个元素
    L.elem[L.length-1] = 0;
    //修改表长
    L.length--;
    return true;
}

/**
 * 输出线性表
*/
void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d\t", L.elem[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    printf("list start!\n");
    SqList list;
    InitList_Sq(list);
    printf("%d\n", ListInsert_Sq(list, 1, 10));
    ElemType e;
    ListDelete_Sq(list, 1, e);
    printf("e = %d\n", e);
    ListInsert_Sq(list, 1, 10);
    ListInsert_Sq(list, 1, 20);
    ListInsert_Sq(list, 1, 30);
    ListInsert_Sq(list, 1, 40);
    ListInsert_Sq(list, 1, 50);
    PrintList(list);
    printf("list end!\n");
    return 0;
}
