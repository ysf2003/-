#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;


/*
  ˼·��ȷ���������յ㣬���ҳ�sum>=target�ĵ㣬����result��Ȼ����㿪ʼ�����������ȥ����ֵ�δ���target�����ͼ�������
  ֱ����ȥ����С��target������������յ㡣
  INT32_MAX:�������ֵ�����resultû���ı�˵���������䶼�Ҳ���sum>=target�ͷ���0
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