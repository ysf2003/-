#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;


int main()
{
    class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size();
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (nums[mid] > target)
                    right = mid;
                else if (nums[mid] < target)
                    left = mid + 1;
                else
                    return mid;
            }
            return -1;
        }
    };


	return 0;
}