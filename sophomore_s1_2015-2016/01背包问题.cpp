#include <iostream>
#include <Windows.h>
using namespace std;
typedef struct object
{
	char name;
	int weight;
	int value;
} object;

int main()
{

	int maxbagWeight, objectNum;
	int cmp;
	cin >> maxbagWeight >> objectNum;
	object *oj = new object[objectNum + 1];
	int **array = new int *[objectNum + 1]; //申请二维数组
	for (int i = 0; i <= objectNum; i++)
	{
		array[i] = new int[maxbagWeight];
	}
	for (int i = 0; i <= objectNum; i++) //初始化二维数组的值
		for (int j = 0; j <= maxbagWeight; j++)
			array[i][j] = 0;
	oj[0].weight = 0;
	oj[0].value = 0;
	for (int i = 1; i <= objectNum; i++)
	{
		cin >> oj[i].name >> oj[i].weight >> oj[i].value;
	}
	for (int j = 0; j <= maxbagWeight; j++)
	{
		for (int i = 1; i <= objectNum; i++)
		{
			if (j < oj[i].weight)
			{
				array[i][j] = array[i - 1][j];
			}
			else
			{
				cmp = array[i - 1][j - oj[i].weight] + oj[i].value; //核心算法
				array[i][j] = cmp > array[i - 1][j] ? cmp : array[i - 1][j];
			}
		}
	}
	cout << array[objectNum][maxbagWeight] << endl;
	system("pause");
	return 0;
}