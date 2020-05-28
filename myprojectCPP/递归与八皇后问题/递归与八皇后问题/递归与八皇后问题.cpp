// 递归与八皇后问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//八皇后递归解法
#include <iostream>
using namespace std;
int queen[8] = { 0,0,0,0,0,0,0,0};//8个皇后的位置，序号表示哪个皇后
int coun = 0;
bool available(int pointi, int pointj)//判断点的位置，是否符合规则pointi：行 pointj：列
{//判断某个皇后是否与已有皇后冲突,,这是规则
	for (int i = 0; i < pointi; i++) 
	{
		if (pointj == queen[i])return false;//同一列拒绝//以往的行有没有记录pointj，记录了就说明已经放了
		if ((pointi - i) == (pointj - queen[i]))return false;//同一主对角线拒绝//行列的差相等，这个差是用queen[i]代替列值
		if ((pointi - i) + (pointj - queen[i]) == 0)return false;//同一副对角线拒绝
	}
	return true;
}
void findSpace(int queenNumber)//queenNumber：行 i：列
{//在第queenNumber行找能放皇后的位置，这是遍历递归
	for (int i = 0; i < 8; i++) 
	{//从1~8遍历这一行的八个空位
		if (available(queenNumber, i))
		{
			//如果可以放这个位置就记录下第queenNumber个皇后的位置
			queen[queenNumber] = i;
			if (queenNumber == 7) //0~7，8个皇后
			{//如果八个皇后都放满了统计一下
				coun++;
				for (int i = 0; i < 7; i++)
					cout << queen[i] << " ";
				cout << endl;
				return;
			}
			int nextNumber = queenNumber + 1;//还有皇后没放递归放下一个皇后
			findSpace(nextNumber);
		}
	}
	//queen[--queenNumber] = -1;//如果这一行没有可放的位置说明上一行皇后放的位置不行，要为上一个皇后寻找新的可放位置
	return;
}
int main() {
	findSpace(0);//从（0，0）开始递归好理解
	cout << coun << endl;
	return 0;
}

/*算法总结
* 1.初始化queen[]，表示8个皇后（行）所处的列位置；
* 2.遍历每一行的每一个元素，判断是否符合规则
* 3.符合就将该元素的列位置赋到queen数组对应位置（行对应）；
* 4.递归下一行可放置位置，而这次是从（nextnumber，0）开始
* 5.8个皇后放满后，表示一种放置方法,就结束一种遍历，进行下一行递归遍历
*/
/*00->12
* 01
* 02
* 03
*/
