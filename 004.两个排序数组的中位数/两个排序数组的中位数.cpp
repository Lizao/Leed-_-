/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。
请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。

示例 1:
nums1 = [1, 3]
nums2 = [2]

中位数是 2.0

示例 2:
nums1 = [1, 2]
nums2 = [3, 4]

中位数是 (2 + 3)/2 = 2.5

*/

#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<algorithm>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	std::vector<int> AfterMerge;
	double result;
	for (int i = 0; i < nums1Size; ++i)
	{
		AfterMerge.push_back(nums1[i]);
	}
	for (int j = 0; j < nums2Size; ++j)
	{
		AfterMerge.push_back(nums2[j]);
	}
	sort(AfterMerge.begin(), AfterMerge.end());//实际上题意已经规定了两给定序列是有序数列
	
	int nums3 = nums1Size + nums2Size;
	if ((nums3 + 1) % 2 != 0)
	{
		result = 0.5* (AfterMerge[(nums3 + 1) / 2 - 1] + AfterMerge[(nums3 + 1) / 2]);
		return result;
	}
	else
	{
		result = AfterMerge[(nums3 - 1) / 2];
		return result;

	}

}

int main()
{
	int a[2] = { 1 , 9 };
	int b[2] = { 5, 6 };
	double res = findMedianSortedArrays(a,2,b,2);
	printf("res = %f\n",res);
	getchar();
	return 0;
}
