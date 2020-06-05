// 二叉树生成、遍历与线索化.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

enum tag {link,thread};//定义标志位属性

typedef struct bintreenode
{
    char data;
    bintreenode* rchild;
    bintreenode* lchild;
    tag rtag;
    tag ltag;
}BithrNode, *BithrTree;

BithrTree pre;


    //前序生成
void CreatBinTree(BithrTree *Tnode)
{
    char c;
    c = cin.get();

    if (c == ' ')
    {
        *Tnode = NULL;        
    }
    else
    {
        *Tnode = new bintreenode;
        (*Tnode)->data = c;
        (*Tnode)->ltag = link;
        (*Tnode)->rtag = link;
        CreatBinTree(&(*Tnode)->lchild);
        CreatBinTree(&(*Tnode)->rchild);
    }
}

//中序遍历线索化
void MidorderThread(BithrTree Tnode)
{
    if (Tnode)
    {
        MidorderThread(Tnode->lchild);
        if ( !Tnode->lchild)
        {
            Tnode->ltag = thread;
            Tnode->lchild = pre;
        }
        if ( !pre->rchild)
        {
            pre->rtag = thread;
            pre->rchild = Tnode;
        }
        pre = Tnode;
        MidorderThread(Tnode->rchild);
    }
}

void visit(BithrTree Bt)
{
    cout << Bt->data << endl;
}

//中序遍历二叉树输出
void Inorderoutput(BithrTree Bt)
{
    BithrTree p;
    p = Bt->lchild;

    while (p != Bt)
    {
        while (p->ltag == link)
        {
            p = p->lchild;
        }
        visit(p);
        while (p->rtag == thread && p->rchild != Bt)
        {
            p = p->rchild;
            visit(p);
        }
        p = p->rchild;
    }
}

void Initprenode(BithrTree *Prenode, BithrTree Tnode)
{
    *Prenode = new BithrNode;
    (*Prenode)->ltag = link;
    (*Prenode)->rtag = thread;
    (*Prenode)->rchild = (*Prenode);
    if ( !Tnode )//空树不操作；
    {
        (*Prenode)->lchild = (*Prenode);
    }
    else
    {
        (*Prenode)->lchild = Tnode;
        pre = (*Prenode);
        MidorderThread(Tnode);
        pre->rchild = (*Prenode);
        pre->rtag = thread;
        (*Prenode)->rchild = pre;
    }
}

int main()
{
    BithrTree bn = NULL;
    BithrTree prenode = NULL;
    CreatBinTree(&bn);
    Initprenode(&prenode, bn);
    Inorderoutput(prenode);
}

