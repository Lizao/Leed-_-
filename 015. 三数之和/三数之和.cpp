/*
����һ������ n ������������ nums���ж� nums ���Ƿ��������Ԫ�� a��b��c ��
ʹ�� a + b + c = 0 ���ҳ��������������Ҳ��ظ�����Ԫ�顣
ע�⣺���в����԰����ظ�����Ԫ�顣
����, �������� nums = [-1, 0, 1, 2, -1, -4]��
����Ҫ�����Ԫ�鼯��Ϊ��
[
   [-1, 0, 1],
   [-1, -1, 2]
]
*/

#include <stdio.h>
#include <vector>
struct result {
	int x;
	int y;
	int z;
};


int** Vector2Array(std::vector<result> A)
{ 
	int** TwoArray = new int*[3];
	for (int i = 0; i < A.size(); ++i)
	{	
			TwoArray[i][0] = A[i].x;
			TwoArray[i][1] = A[i].y;
			TwoArray[i][2] = A[i].z;	
	}
	return TwoArray;
}

int** threeSum(int* nums, int numsSize) 
{
	int  **RESULT;
	result ThreeSum;
	std::vector<result> all_;
	for (int i = 0; i < numsSize; ++i)
	{
		for (int j = i + 1; j < numsSize; ++j)
		{
			for (int k = j + 1; k < numsSize; ++k)
			{
				if ((nums[i] + nums[j] + nums[k]) == 0)
				{
					ThreeSum.x = i;
					ThreeSum.y = j;
					ThreeSum.z = k;
					printf("nums[%d]=%d,nums[%d]=%d��nums[%d]=%d", ThreeSum.x,ThreeSum.y,ThreeSum.z);
					all_.push_back(ThreeSum);
				}
			}
		}
	}
	RESULT = Vector2Array(all_);

	return RESULT;
}

int main()
{
	int nums[6] = { -1, 0, 1, 2, -1, -4 };
	int **RESULT = threeSum(nums,6);
	getchar();
	return 0;
}