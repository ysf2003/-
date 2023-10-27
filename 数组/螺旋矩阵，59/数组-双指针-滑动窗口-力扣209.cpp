#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;


/*
  思路：确定滑动的终点，即找出sum>=target的点，更新result，然后起点开始滑动，如果减去起点的值任大于target，起点就继续动。
  直到减去起点后小于target，则继续滑动终点。
  INT32_MAX:整形最大值，如果result没被改变说明整个区间都找不到sum>=target就返回0
*/
int main()
{
    class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int result = INT32_MAX;
            int sum = 0;
            int i = 0;
            for (int j = 0; j < nums.size(); ++j)
            {
                sum += nums[j];
                while (sum >= target)
                {
                    int len = j - i + 1;
                    result = min(result, len);
                    sum -= nums[i++];
                }
            }
            return (result == INT32_MAX ? 0 : result);
        }
    };
	return 0;
}