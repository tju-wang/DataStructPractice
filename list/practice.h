#ifndef _PRACTICE_H
#define _PRACTICE_H

Status Reserve(List *pList);
Status Reserve_1(List *pList);

Node *Reverse_2(List plist);
void Show_1(List plist);

Status MergeList(List *pList1,List *pList2,List *pList3);
Status IsLoop(List *pList);
Status GetLoopLength(List *pList,int *len);
Status GetLoopInPoint(List *pList,int *inPoint);

Status ListLen(List* plist,int *len);
Status IsTwoListCut(List *pList1,List *pList2,int *pos1,int *pos2);

Status Last_k(List *pList,int k,Elemtype *e);
//顺序表  求交并查
Status intersectionSeqList(int *List1,int len1,int *List2,int len2,int *List3,int *len3);
Status UnionSetSeqList(int *List1,int len1,int *List2,int len2,int *List3,int *len3);
Status DiffSetSeqList(int *List1,int len1,int *List2,int len2,int *List3,int *len3);

//有序的单链表  求交并差
Status intersectionOrderList(List *plist1,List *plist2,List *plist3);
Status UnionOrderList(List *plist1,List *plist2,List *plist3);
Status DiffSetOrderList(List *plist1,List *plist2,List *plist3);

//无序的单链表  求交并差
Status isPresent(List *plist1,Elemtype data);
Status intersectionList(List *plist1,List *plist2,List *plist3);
Status UnionList(List *plist1,List *plist2,List *plist3);
Status DiffSetList(List *plist1,List *plist2,List *plist3);
#endif
