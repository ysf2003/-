#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
/*
    ˫ָ�뷨�������ָ��ָ���Ԫ�أ�=val���͸�����ָ��ָ���ֵ=��ָ��ָ���ֵ��
    һ��ѭ��֮��Ϳ����ų����е���val��ֵ
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