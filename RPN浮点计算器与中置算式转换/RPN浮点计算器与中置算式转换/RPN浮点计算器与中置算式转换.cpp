// 栈与RPN计算法则.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#define arraysize 16
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
            return 0;
        }
        *this->top = *data;
        this->top = this->top + 1;
        this->stacksize -= 1;
        return 1;
    }
    bool pop()
    {
        if (this->stacksize == this->maxsize)
        {
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
                stk.popdata = ((stk.popdata - 48) + m) + 48;
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

void inf2suf(int size, stack stk, char* data)
{
    stack outstk;
    outstk.setSize(arraysize - 1);
    outstk.Initstack();
    for (int i = 0; i < size-1; i++)
    {
        if (isdigit(data[i]))
        {
            cout << data[i];
            outstk.push(&data[i]);
        }
        else if (data[i] == '(')
        {
            stk.push(&data[i]);
        }
        else if (data[i] == ')')
        {
            while (*(stk.gettop() - 1) != '(')
            {
                stk.pop();
                cout << stk.popdata;
                outstk.push(&(stk.popdata));
            }
            stk.pop();
        }
        else if (data[i] == '/' || data[i] == '*')
        {
            while (*(stk.gettop() - 1) == '/' || *(stk.gettop() - 1) == '*')
            {
                stk.pop();
                cout << stk.popdata;
                outstk.push(&(stk.popdata));
            }
            while ((*(stk.gettop() - 1) == '-') || (*(stk.gettop() - 1) == '+'))
            {
                stk.push(&data[i]);
            }
            if (stk.gettop() == stk.getbase())
            {
                stk.push(&data[i]);
            }
        }
        else if (data[i] == '+' || data[i] == '-')
        {
            while (*(stk.gettop() - 1) == '/' || *(stk.gettop() - 1) == '*')
            {
                stk.pop();
                cout << stk.popdata;
                outstk.push(&(stk.popdata));
            }
            while (*(stk.gettop() - 1) == '+' || *(stk.gettop() - 1) == '-')
            {
                stk.pop();
                cout << stk.popdata;
                outstk.push(&(stk.popdata));
            }
            //if (stk.gettop() == stk.getbase())
            //{
                stk.push(&data[i]);
            //}
        }
        else
        {
            stk.push(&data[i]);
        }
    }
    for (int i = 0; i < stk.getSize(); i++)
    {
        if (stk.pop() == 0)
        {
            break;
        }
        cout << stk.popdata;
        if (outstk.push(&(stk.popdata)) == 0)
        {
            break;
        }
    }
    cout << endl;

    stack nstk;
    nstk.setSize(11);
    nstk.Initstack();

    char outdata[12];
    
    for (int i = 0; i < outstk.getSize(); i++)
    {
        if (outstk.pop() == 0)
        {
            break;
        }
        outdata[10 - i] = outstk.popdata;
        cout << outstk.popdata;
    }
    cout << endl;
    RPNexample(11, nstk, outdata);
}


int main()
{
    
    //char data[arraysize];
    //for (int i = 0; i < arraysize - 1; i++)
    //{
    //    cin >> data[i];
    //}
    ////char data[arraysize] = "68*12-45+*+";
    
    //RPNexample(arraysize - 1, stk, data);
    char data[arraysize] = "6*8+(1-2)*(4+5)";
    stack stk;
    stk.setSize(arraysize - 1);
    stk.Initstack();    
    inf2suf(arraysize, stk, data);
    
}

