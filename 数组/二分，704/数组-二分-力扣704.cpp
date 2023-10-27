#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;


int main()
{
    /* 
       ����һ��[left��right)����ҿ�����
    */

    class Solution1 {
    public:
        int search(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size();//�ҿ���ȡ����size���ֵ
            while (left < right)//����ҿ�����left��=right����[1,1)�����һ���Ƿ�����
            {
                int mid = left + (right - left) / 2;//��ֹ��int �ȼ���(left+right)/2
                if (nums[mid] > target)
                    right = mid;
                //��Ϊ����ҿ�������֮ǰȡ����right���ֵ�����µ�ʱ��mid�Ϳ��Ե���right
                else if (nums[mid] < target)
                    left = mid + 1;
                //����ҿ�����ȡ��������֮ǰ����ȡ��left���ֵ�����µ�ʱ���Ҫ�ų�
                else
                    return mid;
            }
            return -1;
        }
    };

    /*
       ���ֶ�������ұ�
    */
    class Solution2 {
    public:
        int search(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1;//�ұգ�size-1����ȡ��
            while (left <= right)//����ұգ�left��right������ȣ�������<=
            {
                int mid = left + (right - left) / 2;//��ֹ��int
                if (nums[mid] > target)
                    right = mid - 1;//�ұգ�����֮ǰ����ȡ��right������֮��Ҫ�ų�rightԭ����ֵ
                else if (nums[mid] < target)
                    left = mid + 1;//ͬ��
                else
                    return mid;
            }
            return -1;
        }
    };

	return 0;
}