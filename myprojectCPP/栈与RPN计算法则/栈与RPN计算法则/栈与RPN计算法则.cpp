// 栈与RPN计算法则.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#define arraysize 12
class stack
{

    int stacksize;//栈的大小,当前最大可使用
    int maxsize;
    char* base;
    char* top;
public:
    char popdata;
    //struct node
    //{
    //    char data;
    //    struct node* next;
    //};
    char* getbase()
    {
        return this->base;
    }
    char* gettop()
    {
        return this->top;
    }
    void setSize(int maxsize)
    {
        this->maxsize = maxsize;
    }
    int getSize()
    {
        this->stacksize = this->maxsize - (top - base);
        return this->stacksize;
    }
    //void Initstack(node* head)
    //{        
    //    struct node* base = new node;
    //    base = head;

    //    for (int i = 0; i < this->maxsize; i++)
    //    {
    //        struct node* newnode = new node;
    //        base = base->next;
    //    }

    //    this->base = &(head->data);
    //    this->top = &(head->data);
    //}
    void Initstack()
    {
        char* Data = new char[this->maxsize];
        this->base = Data;
        this->top = Data;
    }
    bool push(char* data)
    {
        if (this->stacksize == 0)
        {
            cout << "error" << endl;
            return 0;
        }
        *this->top = *data;
        this->top = this->top + 1;
        this->stacksize -= 1;
    }
    bool pop()
    {
        if (this->stacksize == this->maxsize)
        {
            cout << "error" << endl;
            return 0;
        }
        this->top -= 1;
        popdata = *this->top;
        this->stacksize += 1;
    }
};


void RPNexample(int size, stack stk, char* data)
{
    int m;
    for (int i = 0; i < size; i++)
    {
        if (data[i] != '+' && data[i] != '-' && data[i] != '*' && data[i] != '/')
        {
            stk.push(&data[i]);
        }
        else
        {
            switch (data[i])
            {
            case '+':
                stk.pop();
                m = (stk.popdata - 48);
                stk.pop();
                stk.popdata = ( (stk.popdata - 48) + m) + 48;
                stk.push(&stk.popdata);
                break;
            case '-':
                stk.pop();
                m = (stk.popdata - 48);
                stk.pop();
                stk.popdata = ((stk.popdata - 48) - m) + 48;
                stk.push(&stk.popdata);
                break;
            case '*':
                stk.pop();
                m = (stk.popdata - 48);
                stk.pop();
                stk.popdata = ((stk.popdata - 48) * m) + 48;
                stk.push(&stk.popdata);
                break;
            case '/':
                stk.pop();
                m = (stk.popdata - 48);
                stk.pop();
                stk.popdata = ((stk.popdata - 48) / m) + 48;
                stk.push(&stk.popdata);
                break;
            }
        }
    }
    stk.pop();
    cout << (stk.popdata - 48) << endl;
}

int main()
{
    char data[arraysize];
    for (int i = 0; i < arraysize-1; i++)
    {
        cin >> data[i];
    }
    //char data[arraysize] = "68*12-45+*+";
    stack stk;
    stk.setSize(arraysize-1);
    stk.Initstack();
    RPNexample(arraysize-1, stk, data);
}

