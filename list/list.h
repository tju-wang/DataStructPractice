#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


typedef int Elemtype;
typedef char Status;
#define OK   0
#define ERROR  1


typedef struct Node
{
    Elemtype data;
    struct Node *next;
}Node;
typedef struct Node *List;



char test_function(List *pList);
Status ShowList(List *pList);
Status GetList(List *pList,int i, Elemtype *e);
Status InsertList(List *pList,int i, Elemtype e);
Status AddItem(List *pList,Elemtype val, int *end);
Status DeleteList(List *pList,int seq);
Status ClearList(List *pList);
Status InitList(List *plist,int len);
Status Arr2List(List *plist,Elemtype *arr,int arrLen);
char test_function2(void);
Status sortS2M(List *plist);

Status CreatLoop(List *pList);
char test_Loop(void);

Status Creat2CutList(List *pList1,List *pList2);
char test_cut();
char test_Last_k(void);
char test_Arr(void);
char ArrPrint(int *arrC,int lenC);
char test_ListSet(void);
char test_OrderListSet(void);
#endif
