// 双向链表与维吉尼亚加密.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Doublylinkedlist
{
public:
    struct Dnode
    {
        char data;
        struct Dnode* prior;
        struct Dnode* next;
    };

    Dnode* getDoublylist()
    {
        char* output = NULL;
        int f = 26;
        struct Dnode* head = new Dnode;
        head->data = 'A';
        head->next = NULL;
        head->prior = NULL;

        struct Dnode* move = new Dnode;
        move = head;

        for (int i = 1; i < f; i++)
        {
            struct Dnode* empty = new Dnode;
            move->next = empty;
            empty->prior = move;
            empty->data = move->data + 1;
            move = empty;
            empty->next = NULL;
        }
        move->next = head;
        head->prior = move;       
        return head;
    }

    char* Findout( int k, char* pltext, Dnode* head)
    {
        char* output = NULL;
        int f = 26;
        
        while (head->data != *pltext)
        {
            head = head->next;
        }
        //处理命令
         int m = k % f;
         if ((m < 13))
          {
             int n = f - m;
                while (m)
                {
                    head = head->next;
                    m--;
                }
                while (f)
                {
                    head = head->next;
                    f--;
                }
                output = &head->data;
            }
         if ((m >= 13))
            {
                int n = f - m;
                while (n)
                {
                    head = head->prior;
                    n--;
                }
                while (f)
                {
                    head = head->prior;
                    f--;
                }
                output = &head->data;
            }
        return output;
    }    
};


int main()
{
    static int len = 8;


    string Plaintext;
    cout << "请输入8位明文：";
    getline(cin, Plaintext);
    cout << "您输入的明文为:"<< Plaintext << endl;

    srand((int)time(NULL));
    int Randomkey[8];    //int型数组用于存储输入变量
    cout << "随机密钥：";

    int j = 0;
    while (j <len)
    {
        Randomkey[j] = rand() % 100;
        cout <<" "<< Randomkey[j] ;
        j++;
    }
    cout << endl; 

    Doublylinkedlist Dlist;
    Doublylinkedlist::Dnode* head;
    head = Dlist.getDoublylist();

    char Ciphertext[8];
    char* m;
    for (int i = 0; i < len; i++)
    {
        char& r = Plaintext[i];
        char* singlechar = &r;
        int k = Randomkey[i];
        m = Dlist.Findout(k, singlechar, head);
        Ciphertext[i] = *m;
    }

    cout << "密文：";
    int i = 0;
    while (len)
    {
        cout << " " << Ciphertext[i];
        len--;
        i++;
    }
    cout << endl;
    
}

