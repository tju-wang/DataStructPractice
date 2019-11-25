#include "list.h"
#include "practice.h"
struct Node* head;

int main(int argv,char* argc)
{
    Status status = OK;
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    // test_function(&head);
    // test_function2();
    // test_Loop();
    // test_cut();
    // test_Last_k();
    // test_Arr();
    // test_OrderListSet();
    test_ListSet();
    return 0;
}

char test_function(List *pList)
{
    int mData[10] = {1,2,3,4,5,6,7,8,9};
    int number = 0;
    int cnt = 0;
    // if(InsertList(pList,1,mData[1])!=OK)
    // {
    //     printf("insert fail.\n");        
    // }
    // if(InsertList(pList,2,mData[2])!=OK)
    // {
    //     printf("insert fail.\n");        
    // }
    for(cnt=0;cnt<8;cnt++)
    {
        AddItem(pList,mData[cnt],&number);
    }

    DeleteList(pList,3);        //delete third elements
    printf("%d  \n",number);
    ShowList(pList);
    Reserve(pList);
    ShowList(pList);
    Reserve_1(pList);
    ShowList(pList);
}
/*
合并有序的单链表  随机数链表创建  链表冒泡排序  合并有序链表
*/
char test_function2(void)
{
    List list1,list2,list3;
    int list1Len,list2Len,list3Len;
    list1 = (List)malloc(sizeof(Node));
    list2 = (List)malloc(sizeof(Node));
    list3 = (List)malloc(sizeof(Node));
    if(list1==NULL||list2==NULL||list3==NULL)
        return ERROR;
    InitList(&list1,10);
    InitList(&list2,12);
    ShowList(&list1);
    ShowList(&list2);
  
    ListLen(&list1,&list1Len);
    printf("lietLen = %d\n",list1Len);
    sortS2M(&list1);
    ShowList(&list1);
    sortS2M(&list2);
    ShowList(&list2);

    MergeList(&list1,&list2,&list3);
    ShowList(&list3);
    return 0;
}
/*
环相关
*/
char test_Loop(void)
{
    List head;
    int loopLen = 0;
    int loopInPoint = 0;
    head = (List)malloc(sizeof(Node));
    //创建环
    CreatLoop(&head);    //数据随机  环入口位于第
    if(IsLoop(&head))
        printf("this list is loop.\n");
    else 
        printf("this lsit is not loop.\n");
    if(GetLoopLength(&head,&loopLen)==0)
        printf("The loop length is %d.\n",loopLen);
    if(GetLoopInPoint(&head,&loopInPoint)==0)
        printf("The inLoop point is %d.\n",loopInPoint);

    return 0;
}
/*
判断两个单链表是否相交  返回交点位置
*/
char test_cut()
{
    List head1,head2;
    int cutPos[2] = {0};
    head1 = (List)malloc(sizeof(Node));
    head2 = (List)malloc(sizeof(Node));
    Creat2CutList(&head1,&head2);
    if(IsTwoListCut(&head1,&head2,&cutPos[0],&cutPos[1])==0)
        printf("the cutPos1 = %d    cutPos2 = %d\n",cutPos[0],cutPos[1]);
    
    return OK;
}
char test_Last_k(void)
{
    List head;
    Elemtype value;
    head = (List)malloc(sizeof(Node));
    InitList(&head,24);
    ShowList(&head);
    if(Last_k(&head,5,&value)==0)
        printf("the element is %d.\n",value);
}
//测试两个顺序表的  交 并 差  
char test_Arr(void)
{
    const int sizeA = 20;
    const int sizeB = 20;
    const int sizeC = 40;
    int lenC = 0;
    int cnt = 0;
    int arrA[20] = {0,1,5,4,9,45,85,68,1204,456,52,32,45,78,14};
    int arrB[20] = {12,13,56,69,75,9,85,68,69,32,78,14,85,36,46,89};
    int arrC[40] = {0xFF};

    intersectionSeqList(arrA,sizeA,arrB,sizeB,arrC,&lenC);
    printf("the seqList intersection set is:  \n");
    ArrPrint(arrC,lenC);
    UnionSetSeqList(arrA,sizeA,arrB,sizeB,arrC,&lenC);
    printf("the seqList Union set is:  \n");
    ArrPrint(arrC,lenC);
    DiffSetSeqList(arrA,sizeA,arrB,sizeB,arrC,&lenC);
    printf("the seqList Diff set is:  \n");
    ArrPrint(arrC,lenC);
}
char ArrPrint(int *arrC,int lenC)
{
    int cnt;
    for(cnt=0;cnt<lenC;cnt++)       {
        printf("%5d  ",arrC[cnt]);
        if(cnt%10==0&&cnt>0)
            printf("\n");
    }
    printf("\n");
    return OK;
}
char test_OrderListSet(void)
{
    List head1 = (List)malloc(sizeof(Node));
    List head2 = (List)malloc(sizeof(Node));
    List head3 = (List)malloc(sizeof(Node));
    //初始化两个有序链表
    Elemtype arr1[8] = {0, 0, 1, 3, 3,4,4,9};
    Elemtype arr2[5] = {0, 3,3, 6, 9};
    InitList(&head1,8);
    // Arr2List(&head1,&arr1[0],8);     
    sortS2M(&head1);
    InitList(&head2,5); 
    //Arr2List(&head2,&arr2[0],5);    
    sortS2M(&head2);

    ShowList(&head1);
    ShowList(&head2);
    if(intersectionOrderList(&head1,&head2,&head3)==0)
    {
        ShowList(&head3);
        ClearList(&head3);
    }        
    else
        printf("intersect err.\n");
    if(UnionOrderList(&head1,&head2,&head3)==0)
    {
        ShowList(&head3);
        sortS2M(&head3);
        ShowList(&head3);
        ClearList(&head3);
        // ShowList(&head3);
    }
    else
        printf("Union set err.\n");
    if(DiffSetOrderList(&head1,&head2,&head3)==0)
    {
        ShowList(&head3);
        ClearList(&head3);
    }
    else
    {
        printf("Diff set err.\n");
    }
    
}
Status test_ListSet(void)
{
    List head1 = (List)malloc(sizeof(Node));
    List head2 = (List)malloc(sizeof(Node));
    List head3 = (List)malloc(sizeof(Node));
    //初始化两个有序链表
    Elemtype arr1[8] = {0, 0, 1, 3, 3,4,4,9};
    Elemtype arr2[5] = {0, 3,3, 6, 9};
    InitList(&head1,8);
    // Arr2List(&head1,&arr1[0],8);     
    // sortS2M(&head1);
    InitList(&head2,5); 
    //Arr2List(&head2,&arr2[0],5);    
    // sortS2M(&head2);

    ShowList(&head1);
    ShowList(&head2);
    if(intersectionList(&head1,&head2,&head3)==0)
    {
        ShowList(&head3);
        ClearList(&head3);
    }        
    else
        printf("intersect err.\n");
    if(UnionList(&head1,&head2,&head3)==0)
    {
        ShowList(&head3);
        sortS2M(&head3);
        ShowList(&head3);
        ClearList(&head3);
        // ShowList(&head3);
    }
    else
        printf("Union set err.\n");
    if(DiffSetList(&head1,&head2,&head3)==0)
    {
        ShowList(&head3);
        ClearList(&head3);
    }
    else
    {
        printf("Diff set err.\n");
    }
}
Status ClearList(List *pList)
{
    List p,q;
    p = *pList;
    p = p->next;
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*pList)->next = NULL;
    return OK;

}

//将数组转化为列表并返回  用于生成指定数的列表
Status Arr2List(List *plist,Elemtype *arr,int arrLen)
{
    int cnt = 0;
    List p,q;
    p = (*plist);
    for(cnt=0;cnt<arrLen;cnt++)
    {
        q = (List)malloc(sizeof(Node));
        q->data = arr[cnt];
        p->next = q;
        p = p->next;
    }
    p->next = NULL;
    return 0;
}

Status GetList(List *pList,int i, Elemtype *e)
{
    Status ret = OK;
    int cnt;
    List p; //define a pointer
    p = *pList;
    cnt = 1;
    while(p && cnt<i)   //move
    { // MergeList(&list1,&list2,&list3);
    // ShowList(&list3);
        p=p->next;
        cnt++;
    }
    if(!p || cnt>i)     // !p (if p is NULL)
        return ERROR;
    *e = p->data;
    return ret;
}
Status InsertList(List *pList,int i, Elemtype e)
{
    int cnt = 1;
    List p,s;
    p = *pList;
    while(p && cnt<i)
    {
        p = p->next;
        cnt++;
    }
    if(!p || cnt>i)
        return ERROR;
    s = (List)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}
Status DeleteList(List *pList,int seq)
{
    List p,q;
    int cnt=0;
    p = *pList;
    while(p && cnt<seq-1)
    {
        p = p->next;
        cnt++;
    }
    if(!(p->next) || cnt>seq-1)
        return ERROR;
    q = p->next;
    p->next = q->next;
    free(q);
    return OK;
}


Status ShowList(List *pList)
{
    Status ret = OK;
    List p;
    p = *pList;
    int cnt = 0;
    p = p->next;
    // printf("This list:\n");
    while(p)
    {
        if(cnt%10==0)
            printf("\n");
        printf("%4d  ",p->data);
        p = p->next;
        cnt++;
    }
    printf("\n");

    return ret;

}
/*

*/
Status AddItem(List *pList,Elemtype val, int *end)
{
    List p;
    List s;
    int cnt = 1;;
    p = *pList;
    while(p->next)
    {
        p = p->next;
        cnt++;
    }
    s = (List)malloc(sizeof(Node));
    if(s==NULL)
        return ERROR;
    
    p->next = s;
    s->data = val;
    s->next = NULL;
    *end = cnt;
    return OK;
}

/*
初始化一个由随机数组成的链表
*/
Status InitList(List *plist,int len)
{
    List p;
    p = *plist;
    int cnt = 0;
    p->data = 0;
    p->next = NULL;
    sleep(1);
    srand((unsigned)time(NULL));
    while(cnt<len)
    {
        List q = (List)malloc(sizeof(Node));
        if(q==NULL)
            return ERROR;
        q->data = (int)rand()%10;
        p->next = q;
        p = p->next;
        cnt++;
    }
    p->next = NULL;
    return OK;
}

/*
创建环
*/
Status CreatLoop(List *pList)
{
    List p;
    InitList(pList,10);
    p = *pList;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = (*pList)->next->next->next->next;
    return OK;
}
//创建相交的列表  p2长于p1
Status Creat2CutList(List *pList1,List *pList2)
{
    InitList(pList1,10);
    InitList(pList2,5);
    List p;
    p = (*pList1);
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = (*pList2)->next->next->next;
    return OK;
}
/*
冒泡排序  小到大
*/
Status sortS2M(List *plist)
{
    List p,pMove,pPrev,pMovePrev,temp;
    int length,i,j = 0;
    ListLen(plist,&length);
    pPrev = (*plist); //指向头指针
    p = pPrev->next;
    pMovePrev = p;
    pMove = p->next;
    temp = (List)malloc(sizeof(Node));

    if(length==0)
        return ERROR;
    for(i=0;i<length-1;i++)
    {
        for(j=i;j<length-1;j++)
        {
            if(p->data > pMove->data)
            {
                if(pMovePrev!=p)  //间隔交换  
                {
                    *temp = *p;
                    p->next = pMove->next;
                    pMove->next = temp->next;
                    pMovePrev->next = p;
                    pPrev->next = pMove;
                    p = pPrev->next;
                }
                else    //相邻交换
                {
                    p->next = pMove->next;
                    pMove->next = p;
                    pPrev->next = pMove;
                    //还原交换前的状态
                    p = pPrev->next;
                    pMovePrev = p;
                    pMove = pMovePrev->next;
                }
            }           
            //移动指针
            pMovePrev = pMovePrev->next;
            pMove = pMovePrev->next;
        }
        //移向下一个位置
        pPrev = pPrev->next;
        p = pPrev->next;
        pMovePrev = p;
        pMove = pMovePrev->next;
    }
    return OK;
    
}



