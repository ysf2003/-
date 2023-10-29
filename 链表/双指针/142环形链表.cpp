#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
  ˼·��fastһ����������slowһ����һ��������л����Ǳض��������軷�ĳ���Ϊn��head������ڵĳ���Ϊx�������ڻ��������߹��ĵĳ���Ϊy��
  z = n-y ��fast�߹��ľ��� = x +n(y+z) slow�߹��ľ���Ϊx + y���ض���slow��һ���߽�Ȧ��׷�ϣ�
  ��Ϊfast���ٶ���slow������������slow��Ȧ��ʱ��fast�����fast���ض���slow����һȦ֮ǰ׷��slow
  ��x+n(y+z) + y = 2(x + y) ---> x = n(y+z)-y--> x=(n-1)(y+z) + z,��n=1ʱ��x=z����slow�ոյ����ʱ��fast��ʱ�����������
  ��x = (n - 1)(y + z) + z��֪������index1Ϊ����ָ��������λ�ã�index2��head��ʼ�ߣ�index1��index2�ض��ڻ����������
  index1(z)��index2(x)������(n-1)*���ĳ���Ȧ,��index1==index2ʱ��������ھ����������ڵ�λ�á�
*/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return nullptr;
    }
};