/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
找出 nums 中的三个整数，使得它们的和与 target 最接近。
返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/

#include<stdio.h>
#include<iostream>
#include<vector>

struct INDEXVALUE {
	int i;
	int j;
	int k;
	int sum;

};

int threeSumClosest(int* nums, int numsSize, int target) {
	int i = 0, j = 0, k = 0;
	std::vector<INDEXVALUE> sum;
	int min = 100000;
	int index = 0;
	int s = 0;
	INDEXVALUE result;
	for (i; i < numsSize; i++)
	{
		for (j=i+1; j < numsSize; j++)
		{
			for (k=j+1; k < numsSize; k++)
			{
				s = nums[i] + nums[j]+ nums[k];
				result.i = i;
				result.j = j;
				result.k = k;
				result.sum = s;
				printf("i=%d,j=%d,k=%d,sum = %d\n", i,j,k,s);
				sum.push_back(result);
			}
		}
	}

	for (int i = 0; i < sum.size(); i++)
	{
		int dif = abs(sum[i].sum - target);
		printf("i=%d，sum = %d\n", sum[i].i, sum[i].sum);
		if (dif < min)
		{
			min = dif;
			index = i;
		}
			
	}
	printf("三数与target之差最小是%d,取最小值时的索引是%d\n", min, index);
	printf("取最小值时三值分别为%d，%d，%d\n", nums[sum[index].i], nums[sum[index].j], nums[sum[index].k]);
	

	return sum[index].sum;
}

int main()
{
	int array[] = {1,-1,5,8};
	int a = threeSumClosest(array, 4, 12);
	printf("a=%d\n",a);
	getchar();
	return 0;
}