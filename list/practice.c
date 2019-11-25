#include "list.h"
#include "practice.h"
/*
1. ni zhi dan lian biao 

*/

Status Reserve(List *pList)
{
    List p,mhead;
    int cnt = 0;
    p = *pList;
    mhead = p;
    p = p->next;
    while(p->next)
    {
        List pNext = p->next;
        p->next = pNext->next;
        pNext->next = mhead->next;
        mhead->next = pNext;
        cnt++;
    }
    p->next = NULL;
    // printf("cnt = %d\n",cnt);
    return OK;

}

Status Reserve_1(List *pList)
{
    List p = *pList;
    p = p->next;
    (*pList)->next = NULL;
    while (p != NULL)
    {
        List pNext = p->next;
        p->next = (*pList)->next;
        (*pList)->next = p;
        p = pNext;
    }
    return OK;

}

/**
 * 合并两个有序的单链表
 */

Status MergeList(List *pList1,List *pList2,List *pList3)
{
    List p1,p2,p3;
    p1 = (*pList1)->next; p2 = (*pList2)->next; p3 = (*pList3);
    
    while(p1 && p2)
    {
        if(p1->data < p2->data)
        {
            p3->data = p1->data;
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
        else if(p1->data > p2->data)
        {
            p3->data = p2->data;
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
        else
        {
            p3->data = p1->data;
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
    }
    if(p1)
    {
        p3->next = p1;
    }
    else if(p2)
    {
        p3->next = p2;
    }

    return OK;
}

/*
1.判断单链表是否有环   快慢指针  返回1  有环   返回0  无环
*/
Status IsLoop(List *pList)
{
    Status status = 0;
    List pslow,pfast;
    pslow = (*pList)->next;
    pfast = (*pList)->next->next;
    while(pfast!=NULL && pslow!=NULL)  //有环  一定不会指向NULL 且一定会相遇
    {
        if(pslow==pfast)
        {
            status = 1;
            break;
        }
        pslow = pslow->next;
        pfast = pfast->next->next;
    }
    return status;
}
//求环的长度  找到快慢指针相遇的地方  开始移动慢指针让它们再次相遇
Status GetLoopLength(List *pList,int *len)
{
    int cnt = 0;
    Status status = ERROR;
    List pslow,pfast;
    pslow = (*pList);
    pfast = pslow->next;
    while(pslow->next != NULL && pfast->next !=NULL)
    {
        if(pslow==pfast)
        {
            if(status==OK)  //第二次相等
                break;
            status = OK;            
        }
        pslow = pslow->next;
        if(status!=OK)
            pfast = pfast->next->next;
        else
            cnt++;  //status == OK 表明第一次相遇  移动慢指针  计数器++
    }
    *len = cnt;
    return status;
}
//求单链表是否有环  环的入口点  返回入口位置
Status GetLoopInPoint(List *pList,int *inPoint)
{
    char flag = 0; int cnt = 0;
    Status status = ERROR;
    List pslow,pfast,pmeet,pcnt;
    pslow = (*pList)->next;
    pcnt = (*pList);
    pfast = (*pList)->next->next;
    while(pslow->next != NULL && pfast->next != NULL && pcnt->next != NULL)
    {
        if(pslow==pfast)
        {
            if(flag==0)
            {
                pmeet = pslow;
                flag = 1;   //第一次相遇
                cnt = 0;
            }    
        }
        if(flag==1&&pcnt==pmeet)
        {
            status = OK;
            *inPoint = cnt;
            break;
        }
        if(flag==0)
        {
            pslow = pslow->next;
            pfast = pfast->next->next;
        }
        if(flag==1)
        {
            cnt++;
            pcnt = pcnt->next;
            pmeet = pmeet->next;   
        }
    }
    return status;
}
//判断两个单链表是否相交  求取交点位置
Status IsTwoListCut(List *pList1,List *pList2,int *pos1,int *pos2)
{
    List p1,p2; Status status = ERROR;
    int lenList1,lenList2,lenErr,cnt=0;
    p1 = (*pList1);
    p2 = (*pList2);
    //求链表长度
    ListLen(pList1,&lenList1);
    ListLen(pList2,&lenList2);
    lenErr = lenList2 - lenList1;
    if(lenErr>0)
    {
        while(lenErr--)
        {
            p2 = p2->next;
        }
    }
    else
    {
        lenErr = -lenErr;
        while(lenErr--)
        {
            p1 = p1->next;
        }
    }
    while(p1->next!=NULL && p2->next!=NULL)
    {
        if(p1==p2)
        {
            if(lenList2>lenList1)
            {
                *pos1 = cnt;
                *pos2 = cnt + (lenList2-lenList1);    
            }
            else
            {
                *pos2 = cnt;
                *pos1 = cnt - (lenList2-lenList1);
            }
            
            status = OK;
            break;
        }
        cnt++;
        p1 = p1->next;
        p2 = p2->next;  
    }

    return status;

}



Status ListLen(List* plist,int *len)
{
    *len = 0;
    List p;
    p = (*plist)->next;
    while(p)
    {
        p = p->next;
        (*len)++;
    }
    return OK;
}

/*
7.最快时间找到单链表的倒数第k个节点  并返回
最快的关键在于不数到最后一个节点再倒着数
设置两个指针 p q   p先向前移动k-1次  之后 p q同时移动  当p指向尾节点时  
q指向倒数第k个节点
*/
Status Last_k(List *pList,int k,Elemtype *e)
{   
    Status status = ERROR;
    List p,q;
    p = (*pList);
    q = p;
    while((--k)&&p->next!=NULL)
    {
        p = p->next;
    }
    if(p->next==NULL)
        return ERROR;
    while(p->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    *e = q->data;

    return OK;
}
/*单链表的交集、并集、差集
1.顺序表（数组、使用一组连续地址的存储单元依次存储数据元素）  2.有序单链表   3.单链表   
求顺序表的交 并 差集  还存在问题  需要继续搞清楚用while(p!=NULL) 还是 while(p->next!=NULL)
有些数据，在运行时会出现 Segmentation fault(core dumped)
*/
//顺序表的交集求取
Status intersectionSeqList(int *List1,int len1,int *List2,int len2,int *List3,int *len3)
{
    //对两个数组进行遍历
    int i,j,counter,cnt;
    counter = 0;
    for(i=0;i<len1;i++)
    {
        for(j=0;j<len2;j++)     {
            if(List1[i]==List2[j])      {
                cnt = counter;   //判断是否于list3的内容  不相等再写入list3
                while(cnt--)    {
                    if(List3[cnt]==List1[i])
                        break;
                }
                if(cnt==-1)     {
                    List3[counter] = List1[i];
                    counter++;
                    break;
                }
            }
        }
    }
    *len3 = counter;
    return OK;
}

//求两个顺序表的并集
Status UnionSetSeqList(int *List1,int len1,int *List2,int len2,int *List3,int *len3)
{
    int i,j,counter,cnt;
    counter = 0;
    for(i=0;i<len1;i++)     {   //复制List1的内容到List3  并确保List1里没有重复元素
        cnt = counter;
        while(cnt--)    {
            if(List3[cnt]==List1[i])
                break;
        }
        if(cnt==-1) {
            List3[counter] = List1[i];
            ++counter;
        }
        
    }
    for(i=0;i<len2;i++)
    {
        for(j=0;j<len1;j++)     {   //遍历List2
            if(List1[j]==List2[i])
                break;
        }
        if(j==len1)     {
            List3[counter] = List2[i];
            ++counter;
        }
    }
    *len3 = counter;
    return OK;
}

//求两个顺序表A B的差集C  C = A-B   其中  AB一个是被减数  一个是减数  
Status DiffSetSeqList(int *List1,int len1,int *List2,int len2,int *List3,int *len3)
{
     int i,j,counter,cnt;
     counter = 0; 
     for(i=0;i<len1;i++)
     {
         for(j=0;j<len2;j++)    {
             if(List1[i]==List2[j]) {
                break;
             }
             if(j==len2-1)    {
                 List3[counter] = List1[i];
                 ++counter;
             }
         }

     }
     *len3 = counter;
}

//求有序单链表的交集  并集  差集 并将结果返回一个新链表中
//因为 有链表有序的条件  所以可以改良算法
Status intersectionOrderList(List *plist1,List *plist2,List *plist3)
{
    List p1,p2,p3,temp;
    Elemtype tempVal = 0xFFFF;
    p1 = (*plist1);
    p2 = (*plist2);
    p3 = (*plist3);
    p1 = p1->next;  p2 = p2->next; 
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data < p2->data)
        {
            p1 = p1->next;
        }
        else if(p1->data > p2->data)
        {
            p2 = p2->next;
        }
        else
        {
            if(tempVal!=p1->data)
            {
                temp = (List)malloc(sizeof(Node));
                p3->next = temp;
                p3 = p3->next;
                p3->data = p1->data;
                tempVal = p3->data;
            }
            p1= p1->next;      p2 = p2->next;
        }
        
    }
    p3->next = NULL;
    return OK;
}

//求有序单链表的并集  先复制List1  
Status UnionOrderList(List *plist1,List *plist2,List *plist3)
{
    List p1,p2,p3,temp;
    p1 = (*plist1);
    p2 = (*plist2);
    p3 = (*plist3);

    Elemtype tempVal = 0;
    while(p1!=NULL)      {  //此处注意  是 p!=NULL  若写成p->next!=NULL  则需要调整p1=p1->next;的位置
         
        if(p1->data!=p3->data)  //p1为有序的单链表  相等的元素可能在一块
        {
            temp = (List)malloc(sizeof(Node));
            p3->next = temp;
            p3 = p3->next;
            p3->data = p1->data;
            p3->next = NULL;
        }
        p1 = p1->next;
    }
    p1 = (*plist1)->next;
    p2 = p2->next;
    while(p2!=NULL&&p1!=NULL)     {
        tempVal = p2->data;     //比较 排除p2中有数据重复的情况
        if(p1!=NULL && p1->data<p2->data) //移动p1到合适的比较位置
            p1 = p1->next;
        else if(p1->data == p2->data)
        {
            p1 = p1->next;
            p2 = p2->next;
            if(p2->next!=NULL && p2->data==tempVal)
                p2 = p2->next;
        }
        else        {
            if(p1->data!=p2->data)  //确认p1中没有p2当前指向的内容
            {
                temp = (List)malloc(sizeof(Node));
                p3->next = temp;
                p3 = p3->next;
                p3->data = p2->data;
                p3->next = NULL;    
            } 
            p2 = p2->next; 
            if(p2!=NULL && p2->data==tempVal)
                p2 = p2->next;
        }
    }
    while(p2!=NULL)
    {
        if(p2->data!=p3->data)
        {
            temp = (List)malloc(sizeof(Node));
            p3->next = temp;
            p3 = p3->next;
            p3->data = p2->data;
            p3->next = NULL;    
        }
        else
        {
            p2 = p2->next;
        }
        
    }
    // p3->next = NULL;
    return OK;
}
//求两个有序链表的 差集  
Status DiffSetOrderList(List *plist1,List *plist2,List *plist3)
{
    List p1,p2,p3,p4,temp;
    p1 = (*plist1);     p2 = (*plist2);
    p3 = (*plist3);
    p4 = (List)malloc(sizeof(Node));
    Elemtype tempVal;
    intersectionOrderList(plist1,plist2,&p4);    //求交集
    //p1 - p3  得到差集
    p1 = p1->next;
    p4 = p4->next;
    if(p4==NULL)
        return 1;
    while(p1!=NULL)
    {
        tempVal = p1->data;
        if(p1->data != p4->data)
        {
            temp = (List)malloc(sizeof(Node));
            p3->next = temp;
            p3 = p3->next;
            p3->data = p1->data;    
            p1 = p1->next;
            while(p1!=NULL)
            {
                if(p1->data==tempVal)
                    p1 = p1->next;
                else
                    break;
            } 
        }
        else if(p1->data == p4->data)
        {
            if(p1!=NULL)
                p1 = p1->next;
            else
                break;
            if(p4->next!=NULL)
                p4 = p4->next;
            while(p1!=NULL)
            {
                if(p1->data==tempVal)
                    p1 = p1->next;
                else
                break;
                
            }                    
        }   
    }
    p3->next = NULL;
    return 0;
}

/*
无序列表求交集 并集 差集
*/
//思路  遍历p1链表  在p2链表中寻找元素是否存在
//判断指定链表中是否存在该元素   不存在返回0  存在返回非0
Status isPresent(List *plist1,Elemtype data)
{
    List p1;
    p1 = (*plist1)->next;   //p1指向传入链表的第一个元素
    while(p1!=NULL)
    {
        if(p1->data == data)
            return 1;   //查询到
        p1 = p1->next;
    }
    return 0;  //未查询到末尾  检测到链表中有相同的值  退出
}

Status intersectionList(List *plist1,List *plist2,List *plist3)
{
    List p1,p2,p3;
    p1 = (*plist1)->next;
    p3 = (*plist3);
    //判断p2中是否存在 p1当前指向的元素  存在 判断当前p3中是否有p1当前指向的元素  存在 pass 不存在 申请空间存入
    while(p1!=NULL)
    {
        if(isPresent(plist2,p1->data))
        {
            if(isPresent(plist3,p1->data)==0)   //存入p3中
            {
                p2 = (List)malloc(sizeof(Node));
                p2->data = p1->data;
                p2->next = NULL;    //很关键  将新结点next元素设置为NULL  否则其是未初始化的变量  在后续使用时无法判断链表是否到达尾部
                p3->next = p2;
                p3 = p3->next;
            }
        }
        p1 = p1->next;
    }
    p3->next = NULL;
    return OK;
}
//输出两个无序链表的并集  复制p1的内容到p3 遍历p2
Status UnionList(List *plist1,List *plist2,List *plist3)
{
    List p1,p2,p3,temp;
    p1 = (*plist1)->next;
    p2 = (*plist2)->next;
    p3 = (*plist3);
    while(p1!=NULL)
    {
        if(isPresent(plist3,p1->data)==0)   //p3中不存在p1当前元素 存入
        {
            temp = (List)malloc(sizeof(Node));
            temp->data = p1->data;
            temp->next = NULL;
            p3->next = temp;
            p3 = p3->next;
        }
        p1 = p1->next;
    }
    p1 = (*plist1)->next;
    while(p2!=NULL)
    {
        if(isPresent(plist3,p2->data)==0)
        {
            temp = (List)malloc(sizeof(Node));
            temp->data = p2->data;
            temp->next = NULL;
            p3->next = temp;
            p3 = p3->next;
        }
        p2 = p2->next;
    }
    return OK;
}
//输出两个无序链表的差集  p1中删除p1 p2的交集  遍历p1 判断p1 p2的交集中是否存在当前p1指向的元素
Status DiffSetList(List *plist1,List *plist2,List *plist3)
{
    List p1,p3,p2,temp;
    p1 = (*plist1)->next;
    p2 = (*plist2)->next;
    p3 = (*plist3);
    List head_temp = (List)malloc(sizeof(Node));
    // head_temp->data = 0;  head_temp->next = NULL;
    intersectionList(plist1,plist2,&head_temp);
    while(p1!=NULL)
    {
        if(isPresent(&head_temp,p1->data)==0)
        {
            if(isPresent(plist3,p1->data)==0)
            {
                temp = (List)malloc(sizeof(Node));
                temp->data = p1->data;
                temp->next = NULL;
                p3->next = temp;
                p3 = p3->next;
            }
        }
        p1 = p1->next;
    }
    return 0;
}


