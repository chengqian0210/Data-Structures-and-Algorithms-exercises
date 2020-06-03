// 栈与进制转换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

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

void Bin2Dec(int size,stack stk,char* data)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        //char data;
        //data = cin.get();
        stk.push(data+i);
        cout << *(stk.gettop() - 1) << " ";        
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        stk.pop();
        sum = sum + (stk.popdata - 48) * pow(2, i);
    }    
    cout << sum << endl;
}
void Bin2Hex(int size, stack stk, char* data)
{
    stack Hexstk;
    for (int i = 0; i < size; i++)
    {
        //char data;
        //data = cin.get();
        stk.push(data + i);
        cout << *(stk.gettop() - 1) << " ";
    }
    cout << endl;
    int emp = size / 4;
    if ((size % 4) > 0)
    {
        emp++;
    }
    Hexstk.setSize(emp);
    Hexstk.Initstack();
    for (int i = 0; i < emp; i++)
    {
        char Hex;
        int sum = 0;
        for (int i = 0; i < 4; i++)
        {
            stk.pop();
            sum = sum + (stk.popdata - 48) * pow(2, i);
        }
        if (sum > 9)
        {
            switch (sum)
            {
                case 10:
                    Hex = 'A';
                    Hexstk.push(&Hex);
                    break;
                case 11:
                    Hex = 'B';
                    Hexstk.push(&Hex);
                    break;
                case 12:
                    Hex = 'C';
                    Hexstk.push(&Hex);
                    break;
                case 13:
                    Hex = 'D';
                    Hexstk.push(&Hex);
                    break;
                case 14:
                    Hex = 'E';
                    Hexstk.push(&Hex);
                    break;
                case 15:
                    Hex = 'F';
                    Hexstk.push(&Hex);
                    break;
            }
        }
        else
        {
            Hex = sum+48;
            Hexstk.push(&Hex);
        }
    }
    for (int i = 0; i < emp; i++)
    {
        Hexstk.pop();
        cout << Hexstk.popdata;
    }
}


int main()
{
    char data[17] = "1110111100101001";
    stack stk;
    stk.setSize(16);
    stk.Initstack();
    Bin2Dec(stk.getSize(), stk, data);
    Bin2Hex(stk.getSize(), stk, data);
    //stk.Initstack();
    //char data = 'a';
    //stk.push(&data);
    //cout << stk.getSize() << endl;

    //data = 'b';
    //stk.push(&data);
    //cout << stk.getSize() << endl;
    //cout << *(stk.gettop() - 1) << endl;
    //stk.pop();
    //cout << stk.popdata << endl;
}