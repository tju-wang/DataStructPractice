#include "bin_tree.h"

/*
实现关于二叉树的基础操作
*/
void func(void)
{
    printf("func...\n");
    BiTNode *Troot;
    Troot = (BiTNode*)malloc(sizeof(BiTNode));

    CreatBiTree(&Troot);

    PreOrderTraverse(Troot);
    printf("\n");
    InOrderTraverse(Troot);
    printf("\n");
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


//找到二叉树的大深度




