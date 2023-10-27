#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
/*
    双指针法，如果快指针指向的元素！=val，就更新慢指针指向的值=快指针指向的值，
    一个循环之后就可以排除所有等于val的值
*/
int main()
{
    class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int slow = 0;
            for (int fast = 0; fast < nums.size(); ++fast)
            {
                if (nums[fast] != val)
                {
                    nums[slow++] = nums[fast];
                }
            }
            return slow;
        }
    };
	return 0;
}