#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
//#include<bits/stdc++.h>
#define ll long long
#define N 10
#include <time.h>
#include<limits.h>
typedef struct Array_Message
{
	int low;
	int high;
	int sum;
} array_info;

array_info* Max_Cross_Array(int data[], int low, int mid, int high)
{
	int left_sum = INT_MIN;
	int max_left = 0;
	int sum = 0;

	for (int i = mid; i >= low; --i)
	{
		sum += data[i];
		if (sum > left_sum)
		{
			left_sum = sum;
		}
		max_left = i;
	}

	int right_sum = INT_MIN;
	int max_right = 0;
	sum = 0;

	for (int i = mid + 1; i <= high; ++i)
	{
		sum += data[i];
		if (sum > right_sum)
		{
			right_sum = sum;
		}
		max_right = i;
	}

	array_info* answer = (array_info*)malloc(sizeof(array_info));

	if (answer == NULL)
	{
		printf("Out of space!");
	}
	else
	{
		answer->low = max_left;

		answer->high = max_right;

		answer->sum = left_sum + right_sum;
	}
	return answer;
}

array_info* Max_Child_Array(int data[], int low, int high)
{
	int mid;
	if (high == low)//特判，递归尾部
	{
		array_info* Max_Array = (array_info*)malloc(sizeof(array_info));
		if (Max_Array == NULL)
		{
			printf("Out of space!");
		}
		else  //感觉很像搜索树了
		{
			Max_Array->low = low;
			Max_Array->high = high;
			Max_Array->sum = data[low];
		}
		return Max_Array;
	}
	else//正常执行算法
		mid = (high + low) / 2;
	//接下来沿着mid将array划分为两半，调用三个函数

	array_info* left_array = Max_Child_Array(data, low, mid);

	array_info* right_array = Max_Child_Array(data, mid + 1, high);

	array_info* mid_array = Max_Cross_Array(data, low, mid, high);

	//将最大数组返回
	if (left_array->sum >= mid_array->sum && left_array->sum >= right_array->sum)
	{
		return left_array;
	}
	else if (right_array->sum >= mid_array->sum && right_array->sum >= left_array->sum)
	{
		return right_array;
	}
	else return mid_array;
}

int* random_list()
{
	static int a[N], aa;
	int i;
	srand((unsigned)time(NULL));

	for (i = 0; i < N - 1; i++)
	{
		scanf("%d", &aa);
		a[i] = aa;
	}
	return a;
}


int func_free(array_info** p)
{
	free(*p);
	p = NULL;
	return 0;
}

int main()
{
	int* num;

	num = random_list();

	array_info* MaxArray = Max_Child_Array(num, 0, N - 1);

	printf("[%d, %d, %d]", MaxArray->low, MaxArray->high, MaxArray->sum);

	//func_free(MaxArray);

	return 0;
}
//嵌套malloc写的不是很好,可能会引起内存泄漏.


/*
  int n = 0;
  while(scanf("%d",&n)!=EOF){}
 */
