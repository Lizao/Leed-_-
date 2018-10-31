#include "twoSum.h"
#include<vector>
#include<algorithm>
using namespace std;

struct Node {
	// 保存数组中每个数的值和排序前所在下标
	int index, val;
	bool operator <(Node &n) {
		return val < n.val;
	}
};

std::vector<int> TwoSum::twoSum(std::vector<int>& nums, int target) {
	std::vector<int> res;
	int size = nums.size();
	Node *nodes = new Node[size];
	for (int i = 0; i < size; i++) {
		nodes[i].val = nums[i], nodes[i].index = i;
	}
	sort(nodes, nodes + size);
	int start = 0, end = size - 1, t;
	while (start < end) {
		t = nodes[start].val + nodes[end].val;
		// 等于
		if (t == target) {
			res.push_back(nodes[start].index);
			res.push_back(nodes[end].index);
			return res;
			// 小于， start 指针后移
		}
		else if (t < target) {
			start++;
			// 大于，end 指针前移
		}
		else {
			end--;
		}
	}
	delete[] nodes;
	return res;
}