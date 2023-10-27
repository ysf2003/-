#define  _CRT_SECURE_NO_WARNINGS
#include<vector>
using namespace std;

/*
  思路1：全部平方之后存入数组然后sort，取决于排序的速度
  思路2：双指针;因为是从小到大存所以新数组倒着遍历，双指针：i从0，j从size()-1开始遍历nums，
  哪一方大哪一方就存入新数组。
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> rs(nums.size(), 0);//倒着遍历所以要提前开好空间
        int k = nums.size() - 1;
        for (int i = 0, j = nums.size() - 1; i <= j;)
        {
            if (nums[i] * nums[i] > nums[j] * nums[j])
            {
                rs[k--] = nums[i] * nums[i];
                i++;
            }
            else
            {
                rs[k--] = nums[j] * nums[j];
                j--;
            }
        }
        return rs;
    }
};