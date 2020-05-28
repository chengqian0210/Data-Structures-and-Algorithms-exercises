// 随机链表与查找中间值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <ctime>

using namespace std;
class RandomList
{
public:
    struct node
    {
        int data;
        struct node* next;
    };
    node* getrandomlist(int list_length)
    {
        struct node* node_now = new node;
        node_now->next = NULL;//头节点指向空

        struct node* node_next = new node;//游节点指向最后
        node_next = node_now;//开始的时候，游节点指向头节点

        srand((int)time(NULL));

        int i = 1;

        while (list_length)
        {
 
            struct node* node_p = new node;//要创建的节点
            node_p->data = rand() % 100;//赋值

            node_next->next = node_p;//最后的节点指向新节点
            node_p->next = NULL;//新节点指向空

            node_next = node_p;//最后节点

            list_length--;

            cout <<"第"<<i<< "个节点的值：" << node_next->data << " " << endl;

            i++;
        }
        return node_now;
    }   
    node* insertnode(int i,int data, node* head)
    {
        struct node* Head = new node;
        Head = head;
        struct node* node_insert = new node;
        i = i - 1;
        while (i)
        {
            head = head->next;
            i--;
        }
        node_insert->next = head->next;
        node_insert->data = data;
        head->next = node_insert;
        return Head;
    }
    node* deletenode(int i, node* head)
    {
        struct node* Head = new node;
        Head = head;
        i = i - 1;
        while (i)
        {
            head = head->next;
            i--;
        }
        head->next = head->next->next;
        return Head;
    }
    node* searchmidnode(node* head)
    {
        node mid, search;
        search.next = mid.next = head->next;


        while (search.next->next != NULL)
        {

            if (search.next->next->next != NULL)
            {
                search.next = search.next->next->next;
                mid.next = mid.next->next;
            }
            else
            {
                search.next = search.next->next;

            }
        }
        return mid.next;
    }
};




int main()
{
    RandomList list1;
    RandomList::node head,mid,search,Head;

    head.next = list1.getrandomlist(20);

    Head.next = list1.insertnode(3,100,head.next);
    //Head.next = list1.deletenode(2, head.next);


    cout << "1：" << Head.next->next->data << " " << endl;
    cout << "2：" << Head.next->next->next->data << " " << endl;
    cout << "3：" << Head.next->next->next->next->data << " " << endl;
    cout << "4：" << Head.next->next->next->next->next->data << " " << endl;
    
    cout << "中间节点的值：" << list1.searchmidnode(head.next)->data<< " " << endl;
}

