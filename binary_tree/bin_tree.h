#ifndef _BIN_TREE_H
#define _BIN_TREE_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

void func(void);
enum {
    OK = 0,
    Error1 = 1,
    Error2 = 2,
};
enum {
    FALSE = 0,
    TRUE = 1
};


typedef char Status;
typedef unsigned char    TElemType;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

#define Max(x,y) (x>y?x:y)
#define Min(x,y) (x>y?y:x)

void CreatBiTree(BiTree *T);
void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);

int maxDepth(BiTree T);
int minDepth(BiTree T);
int isHasPathSum(BiTree T,int sum);

#endif
