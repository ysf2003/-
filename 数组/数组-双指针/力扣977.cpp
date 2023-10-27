#define  _CRT_SECURE_NO_WARNINGS
#include<vector>
using namespace std;

/*
  ˼·1��ȫ��ƽ��֮���������Ȼ��sort��ȡ����������ٶ�
  ˼·2��˫ָ��;��Ϊ�Ǵ�С��������������鵹�ű�����˫ָ�룺i��0��j��size()-1��ʼ����nums��
  ��һ������һ���ʹ��������顣
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> rs(nums.size(), 0);//���ű�������Ҫ��ǰ���ÿռ�
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