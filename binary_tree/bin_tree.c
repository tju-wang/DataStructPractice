#include "bin_tree.h"

/*
实现关于二叉树的基础操作
*/
void func(void)
{
    int maxdepth,mindepth;
    printf("func...\n");
    BiTNode *Troot;
    Troot = (BiTNode*)malloc(sizeof(BiTNode));

    CreatBiTree(&Troot);

    PreOrderTraverse(Troot);
    printf("\n");
    InOrderTraverse(Troot);
    printf("\n");
    maxdepth = maxDepth(Troot);
    printf("the max depth of this tree is %d\n",maxdepth);
    mindepth = minDepth(Troot);
    printf("the min depth of this tree is %d\n",mindepth);
}


//前序遍历 创建二叉树  递归调用  AC#
void CreatBiTree(BiTree *T)
{
    TElemType ch,temp;
    scanf("%c",&ch);    /*scanf 会将\n回车符作为下一次scanf输入  加getchar()会丢掉temp 即回车符
    不加丢掉回车符的操作时，需要将二叉树的内容在一行上输入  eg.  ACD##F##MKNE##G###B## 创建一个五层的二叉树
    前序遍历结构就是 ACDFMKNEGB */
    // temp = getchar();
    if(ch=='#')
        *T = NULL;
    else    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if(!*T)
            exit(1);
        (*T) ->data = ch;
        CreatBiTree(&((*T)->lchild));
        CreatBiTree(&((*T)->rchild));
    }
}

//前序遍历 显示二叉树
void PreOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    printf("%c",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}
//中序遍历二叉树  前序与中序结合 后序于中序结合  可以唯一确定二叉树
void InOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    InOrderTraverse(T->lchild); //中序遍历左子树
    printf("%c",T->data);
    InOrderTraverse(T->rchild); //中序遍历右子树
}


/*
Leetcode 104
找到二叉树的大深度
*/
int maxDepth(BiTree T)
{
    if(T==NULL)
        return 0;
    int lDepth = maxDepth(T->lchild)+1;
    int rDepth = maxDepth(T->rchild)+1;
    return lDepth > rDepth ? lDepth : rDepth;
}

/*Leetcode 111
找到二叉树的最小深度  需要找到叶节点  才算遍历了完整的路径
需要注意  一定要检索到了叶子节点才算  即节点的左右孩子均为NULL
*/
int minDepth(BiTree T)
{
    if(T==NULL)
        return 0;
    if(T->lchild==NULL)
        return (minDepth(T->rchild)+1);
    if(T->rchild==NULL)
        return (minDepth(T->lchild)+1);
    return (Min(minDepth(T->lchild),minDepth(T->rchild))+1);
}
/*Leetcode 112
给定一棵树和一个整数  决定是否该数有从根节点到叶节点的一条路径上的和等于给定的这个整数
思路： 判断是否为叶节点  不是叶节点继续向下叠加求节点的和  是叶节点则判断是否等于给定的整数
*/
int isHasPathSum(BiTree T,int sum)
{
    if(T==NULL)
        return FALSE;
    if(T->lchild==NULL && T->rchild==NULL && sum==T->data)  //左右节点都为NULL  叶节点
        return TRUE;
    return (isHasPathSum(T->lchild,sum-(T->data))||isHasPathSum(T->rchild,sum-(T->data)));
}





