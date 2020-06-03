// 循环链表与动态约瑟夫问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <ctime>

using namespace std;

class Randomcircularlist
{
public:
    struct node
    {
        int data;
        struct node* next;
    };
    node* getRandomcircularlist(int list_length)
    {
        srand((int)time(NULL));
        struct node* node_now = new node;
        node_now->data = 2;// rand() % 5 + 1;//现在的头节点是有值的可以指向的
        node_now->next = NULL;//头节点指向空

        struct node* node_next = new node;//游节点指向最后
        node_next = node_now;//开始的时候，游节点指向头节点

        int i = 1;
        list_length -= 1;
        while (list_length)
        {

            struct node* node_p = new node;//要创建的节点
            node_p->data = i+2;//rand() % 5 + 1;//赋值

            node_next->next = node_p;//最后的节点指向新节点
            node_p->next = NULL;//新节点指向头指针

            node_next = node_p;//最后节点

            list_length--;

            i++;
        }
        node_next->next = node_now;//游节点指向头节点
        return node_now;
    }
    node* deletenode(int i, node* head)
    {

        i = i - 2;
        while (i)
        {
            head = head->next;
            i--;
        }
        cout << "\n 删除：" << head->next->data << endl;
        head->next = head->next->next;  
        return head->next;
    }
    void Josephsequence(node* Head)
    {
        while ((Head != NULL) && (Head->next != Head))
        {
            cout << Head->data << endl;
            Head = deletenode(Head->data, Head);
        }
        cout << "最后剩下：" << Head->data << endl;
    }
    void Josephsequence_killvalue(node* Head)
    {
        int i;
        int j = 1;
        while ((Head != NULL) && (Head->next != Head))
        {           
            while (j)
            {
                i = Head->data;
                j--;
            }
            i = i - 2;
            while (i)
            {
                Head = Head->next;
                i--;
            }
            cout << "\n 删除：" << Head->next->data << endl;
            i = Head->next->data;

            Head->next = Head->next->next;

            Head = Head->next;
        }
        cout << "最后剩下：" << Head->data << endl;
    }
};


int main()
{
    Randomcircularlist list;
    Randomcircularlist::node head;
    head.next = list.getRandomcircularlist(10);
    
    int i = 10;
    while (i)
    {
        std::cout << head.next->data << "  " << endl;
        head.next = head.next->next;
        i--;
    }

    list.Josephsequence_killvalue(head.next);
}

