// 魔术师发牌问题与拉丁方阵问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <ctime>

using namespace std;

class Randomcircularlist
{
public:
    int list_length;
    struct node
    {
        int data;
        struct node* next;
    };
    node* getRandomcircularlist(int list_length)
    {
        this->list_length = list_length;
        srand((int)time(NULL));
        struct node* node_now = new node;
        node_now->data = 1;// rand() % 5 + 1;//现在的头节点是有值的可以指向的
        node_now->next = NULL;//头节点指向空

        struct node* node_next = new node;//游节点指向最后
        node_next = node_now;//开始的时候，游节点指向头节点

        int i = 1;
        list_length -= 1;
        while (list_length)
        {

            struct node* node_p = new node;//要创建的节点
            node_p->data = i + 1;//rand() % 5 + 1;//赋值

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

void Magicianlicensing(Randomcircularlist::node* head, Randomcircularlist list)
{
    head->data = 1;
    Randomcircularlist::node* fig;
    fig = head;

        int countnumber;
        for (countnumber = 2; countnumber < list.list_length+1; ++countnumber)
        {
            int data = countnumber;
            int i = countnumber;
            while (i)
            {
                if (fig->next->data == 0)
                {
                    fig = fig->next;
                    i--;
                }
                else
                {
                    fig = fig->next;
                }
            }
            fig->data = data;            
        }
        int i = list.list_length;
        while (i)
        {
            std::cout << head->data << "  " << endl;
            head = head->next;
            i--;
        }
}

void Latinsquare(Randomcircularlist::node* head, Randomcircularlist list)
{
    
    for (int i = 0; i < list.list_length; i++)//i为行数标记
    {
        if (i > 0)
        {
            head = head->next;
        }
        for (int j = i; j < list.list_length+i; j++)
        {            
            std::cout << head->data << "  " ;
            head = head->next;
        }
        cout <<" "<< endl;
    }        
}

int main()
{
    Randomcircularlist list1;
    Randomcircularlist::node* head;
    head = list1.getRandomcircularlist(10);
    //Magicianlicensing(head, list1);
    Latinsquare(head, list1);
    std::cout << "Hello World!\n";
}

