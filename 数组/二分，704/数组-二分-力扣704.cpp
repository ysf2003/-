#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;


int main()
{
    /* 
       二分一：[left，right)左闭右开区间
    */

    class Solution1 {
    public:
        int search(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size();//右开，取不到size这个值
            while (left < right)//左闭右开所以left！=right，如[1,1)这就是一个非法区间
            {
                int mid = left + (right - left) / 2;//防止爆int 等价于(left+right)/2
                if (nums[mid] > target)
                    right = mid;
                //因为左闭右开，更新之前取不到right这个值，更新的时候mid就可以等于right
                else if (nums[mid] < target)
                    left = mid + 1;
                //左闭右开可以取到，更新之前可以取到left这个值，更新的时候就要排除
                else
                    return mid;
            }
            return -1;
        }
    };

    /*
       二分二：左闭右闭
    */
    class Solution2 {
    public:
        int search(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1;//右闭，size-1可以取到
            while (left <= right)//左闭右闭，left和right可以相等，所以用<=
            {
                int mid = left + (right - left) / 2;//防止爆int
                if (nums[mid] > target)
                    right = mid - 1;//右闭，更新之前可以取到right，更新之后要排除right原本的值
                else if (nums[mid] < target)
                    left = mid + 1;//同上
                else
                    return mid;
            }
            return -1;
        }
    };

	return 0;
}