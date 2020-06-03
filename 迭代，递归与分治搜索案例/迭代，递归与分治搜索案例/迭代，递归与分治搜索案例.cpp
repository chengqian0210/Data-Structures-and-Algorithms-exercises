// 迭代，递归与分治搜索案例.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int Iteratesearch(int data[],int size,int key)
{
    int* first = &data[0];
    int* last = &data[size-1];
    int in = (last - first) / 2;
    int* mid = &data[in];
    while (*mid != key)
    {
        if (*mid > key)
        {
            last = mid;
            in = (last - first) / 2;
            mid = &data[in];
        }
        else if (*mid < key)
        {
            first = mid;
            in = (last - first) / 2 + in;
            mid = &data[in];
        }
    }
    return in;
}

//这里以序号为标志，不用地址。
int Recursivesearch(int a[], int key, int low, int high)
{
    int i = low;
    int j = high;
    int mid = (low + high) >> 1;
    cout <<"test"<< mid << endl;
    if (key == a[mid]) 
    {
        return mid;
    }
    else if (key > a[mid]) 
    {
        return Recursivesearch(a, key, mid + 1, j);
    }
    else 
    {
        return Recursivesearch(a, key, i, mid - 1);
    }
    return -1;
}

int main()
{
    int data[12] = { 1,2,4,5,7,8,19,23,24,27,29,35 };//递增序列

    int keyp = 0;
    //keyp = Iteratesearch(data, 12, 5);
    keyp = Recursivesearch(data, 29, 0, 11);
    cout << keyp << endl;
    std::cout << data[keyp];
}
