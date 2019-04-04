// Sort_Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
/* 冒泡排序 */
void bubbleSort(int *a, int len)
{
	int tmp = 0;
	for (int i = 0; i < len-1; i++)
	{
		for (int j = i+1; j < len; j++)
		{
			if (a[j]<a[i])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	return;
}

/* 直接插入排序 */
void insertSort(int *a, int len)
{
	int val = 0;
	int i = 0;
	int j = 0;
	for (i = 1; i < len; i++)
	{
		val = a[i];
		for (j = i-1; j >=0 && a[j]>val; j--)
		{
			a[j + 1] = a[j];
		}

		a[j + 1] = val;
	}
	return;
}

/* 将两个数组合并为一个数组 */
void mergeArray(int *a, int start, int mid, int end)
{

	int k = 0;//k作为临时数组的下标
	int i = start;
	int j = mid+1;

	int *pTmp = (int *)malloc((end - start + 1) * sizeof(int));


	while (i<=mid&&j<=end)
	{
		if (a[i] < a[j])
		{
			pTmp[k++] = a[i++];
		}
		else
			pTmp[k++] = a[j++];
	}

	while (i<=mid)
	{
		pTmp[k++] = a[i++];
	}

	while (j <= end)
	{
		pTmp[k++] = a[j++];
	}
	// 将排序后的元素，全部都整合到数组a中。
	for (i=0;i<k;i++)
	{
		a[start+i] = pTmp[i];
	}
	free(pTmp);
	return;

}
/* 归并排序 */
void mergeSort(int *a, int low,int high)
{
	if (a==NULL || low>=high)
	{
		return;
	}


	int mid = low + (high - low) / 2;

	mergeSort(a, low, mid);
	mergeSort(a, mid + 1, high);

	mergeArray(a, low, mid, high);

}


/* 选择排序 */
void selectSort(int *a, int len)
{
	int i = 0, j = 0;
	int min = 0;
	int pos = 0;

	for (i=0;i<len-1;i++)
	{
		min = a[i];
		pos = i;

		for (j=i+1;j<len;j++)
		{
			if (a[j]<min)
			{
				min = a[j];
				pos = j;
			}
		}

		if (pos != i)
		{
			a[pos] = a[i];
			a[i] = min;
		}
	}

	return;
}

/* 将数组第一个元素寻找合适的位置 */
int findPos(int *a, int slow, int high)
{
	int i = 0;
	int j = 0;

	int base = a[slow];

	while (slow<high)
	{
		while (slow < high && a[high]>base)
		{
			high--;
		}
		a[slow] = a[high];

		while (slow<high&&a[slow]<base)
		{
			slow++;
		}
		a[high] = a[slow];
	}

	//此时slow=high
	a[slow] = base;
	return slow;
}

/* 快速排序 */
void quickSort(int*a, int start, int end)
{
	int pos = 0;

	if (a==NULL || start>=end)
	{
		return;
	}

	pos = findPos(a, start, end);
	quickSort(a, start, pos - 1);
	quickSort(a, pos + 1, end);
}


/* 遍历打印数组元素 */
void showArray(int *a, int len)
{
	printf("数组内容如下：\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


int main()
{
	int a[] = { 9,7,8,10,-3,-1,0,5,3,2,4 };
	int len = sizeof(a) / sizeof(a[0]);
	int num = 0;
	printf("原始");
	showArray(a, len);
	printf("请输入对应验证排序算法（0-冒泡，1-直接插入，2-堆排序，3-选择排序，4-快速排序）：\n");
	scanf_s("%d", &num);

	switch (num)
	{
	case 0:
		bubbleSort(a, len);
		break;
	case 1:
		insertSort(a, len);
		break;
	case 2:
		mergeSort(a, 0, len - 1);
		break;
	case 3:
		selectSort(a, len);
		break;
	case 4:
		quickSort(a, 0, len - 1);
		break;
	default:
		printf("输入命令错误");
	}

	showArray(a, len);

    std::cout << "Hello World!\n"; 
	system("pause");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
