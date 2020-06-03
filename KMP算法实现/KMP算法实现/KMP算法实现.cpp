// KMP算法实现.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>

using namespace std;
char str[] = "ababaa";
int fnext[7];
int fsize = 6;

void getNext(int size,char str[])
{
	fnext[0] = size;
	fnext[1] = 0;
	int i = 0;
	int j = 1;

	while (j < size)
	{
		if((i == 0)||(str[i-1] == str[j-1]))//比较从后一位置开始
		{
			i++;
			j++;
			fnext[j] = i;
		}
		else
		{
			i = fnext[i];
		}
	}



	for (int i = 0; i <= size; i++)
	{
		cout << fnext[i];
	}

}

int KMP(char strdata[],int size,int msize)
{
	int i = 0;//指向主串
	int j = 0;//指向模式串
	while (i<msize)
	{
		if (strdata[i] == str[j])
		{
			if (j == (size-1))
			{
				return i+1;
			}
			else
			{
				i++;
				j++;
			}
		}
		else
		{
			if (fnext[j + 1] == 0)
			{
				i++;
			}
			else
			{
				j = fnext[j + 1];
				j--;
			}
		}
	}
	return 0;
}



int main()
{
	char strdata[] = "aababcaabcababaa";	
	int msize = sizeof(strdata) / sizeof(char);
	getNext(fsize, str);
	cout << endl;
	int pos = KMP(strdata, fsize, msize);
	cout << pos << endl;
}


