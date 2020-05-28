// 链队列与逆向输出.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class queue
{
public:
    struct Qnode
    {
        char data;
        Qnode* next;
    }Deqnode;
private:
    struct Qnode* front;
    struct Qnode* rear;
public:
    Qnode* getfront()
    {
        return this->front;
    }
    Qnode* getrear()
    {
        return this->rear;
    }    
    void Initqueue()
    {
        struct Qnode* q = new Qnode;        
        this->rear = q;
        this->front = q;
        q->next = NULL;
    }
    void Enqueue(char data)
    {
        struct Qnode* q = new Qnode;
        q->data = data;
        q->next = NULL;
        this->rear->next = q;
        this->rear = q;
    }
    void Dequeue()
    {
        struct Qnode* p = new Qnode;
        p = this->front->next;
        Deqnode = *p;
        this->front->next = p->next;
        if (this->rear == p)
        {
            this->rear = this->front;
        }
        delete p;
    }
};

int main()
{
    queue que;
    char data[10] = "asdfghjkl";
    que.Initqueue();
    for (int i = 0; i < 9; i++)
    {
        que.Enqueue(data[i]);
        que.Dequeue();
        cout << que.Deqnode.data;
    }
}

