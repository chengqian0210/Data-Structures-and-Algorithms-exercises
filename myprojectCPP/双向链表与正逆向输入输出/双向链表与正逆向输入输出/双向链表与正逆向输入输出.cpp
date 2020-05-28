
#include <iostream>
#include <string>

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

    void getDoublylist(int k)
    {
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

        //处理命令
        if (k > 0)
        {
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
                    std::cout << head->data << "  ";
                    head = head->next;
                    f--;
                }                
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
                    std::cout << head->data << "  ";
                    head = head->prior;
                    f--;
                }
            }
        }
        if (k < 0)
        {
            int m = abs(k) % f;
            if ((m <= 13))
            {
                int n = f - m;
                while (m)
                {
                    head = head->prior;
                    m--;
                }
                while (f)
                {
                    std::cout << head->data << "  ";
                    head = head->prior;
                    f--;
                }
            }
            if ((m > 13))
            {
                int n = f - m;
                while (n)
                {
                    head = head->next;
                    n--;
                }
                while (f)
                {
                    std::cout << head->data << "  ";
                    head = head->next;
                    f--;
                }
            }
        }
    }


};

int main()
{
    Doublylinkedlist Dlist;
    Dlist.getDoublylist(-13);
}
