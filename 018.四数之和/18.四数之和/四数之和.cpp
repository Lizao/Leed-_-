/*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，
判断 nums 中是否存在四个元素 a，b，c 和 d ，
使得 a + b + c + d 的值与 target 相等？
找出所有满足条件且不重复的四元组。

注意：
答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
满足要求的四元组集合为：
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]
*/

/**
* Return an array of arrays of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

#include<stdio.h>
#include<iostream>
#include <algorithm>

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
	int i = 0, j = 0, k = 0, l = 0;
	int** results;
	int m = 0;
	for (i; i < numsSize; ++i)
	{
		for (j = i + 1; j < numsSize; ++j)
		{
			for (k = j + 1; k < numsSize; ++k)
			{
				for (l = k + 1; l < numsSize; ++l)
				{
					if (i + j + k + l == target)
					{
						returnSize[0] = i;
						returnSize[1] = j;
						returnSize[2] = k;
						returnSize[3] = l;
						results[m] = returnSize;
						m++;
					}
				}
			}
		}
	}
	return results;
}

int main()
{
	int nums[] = { 1, 0, -1, 0, -2, 2 };
	int* returnSize;
	int** results = fourSum(nums, 6, 0, returnSize);
}