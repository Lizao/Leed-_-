/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
画 n 条垂直线，使得垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
注意：你不能倾斜容器，n 至少是2。
*/


#include<stdio.h>
#include<vector>

struct Area_
{
	int x_1;
	int x_2;
	int y_1;
	int y_2;
	int Area;
};

int maxArea(int* height, int heightSize) {
	std::vector<Area_> one_;
	std::vector<std::vector<Area_>> whole_;
	int max_area = 0;
	Area_ Max_Area;
	for (int i = 0; i < heightSize; ++i)
	{
		for (int j = i+1; j < heightSize; ++j)
		{
			int s = (height[i] + height[j])*(j - i);
			if (s >= max_area)
			{
				max_area = s;
				Max_Area.x_1 = i;
				Max_Area.x_2 = j;
				Max_Area.y_1 = height[i];
				Max_Area.y_2 = height[j];
				Max_Area.Area = max_area;
			}
			one_.push_back(Max_Area); //存了最大面积的x1,x2,area
		}
		whole_.push_back(one_);
	}
	int Max_Index = 0;
	int MAXAREA = 0;
	for (int k = 0; k < whole_.size(); ++k)
	{
		if (whole_[k][k].Area >= MAXAREA)
		{
			MAXAREA = whole_[k][k].Area;
			Max_Index = k;
		}
	}
	printf("最大面积时的两个点的横坐标分别是%d,%d，最大面积为%d\n", whole_[Max_Index][Max_Index].x_1, whole_[Max_Index][Max_Index].x_2, MAXAREA);	
	printf("最大面积时的两个点的纵坐标分别是%d,%d\n", whole_[Max_Index][Max_Index].y_1, whole_[Max_Index][Max_Index].y_2);
	
	return whole_[Max_Index][Max_Index].Area;
	
}


int main()
{
	
	int height[] = {2,6,9,13,5};
	int S_max = maxArea(height, 5);
	printf("最大面积为%d\n", S_max);
	getchar();
	return 0;

}