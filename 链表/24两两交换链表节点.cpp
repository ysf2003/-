#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

/*
   ˼·��dummy_head 1 2 3 4 5
   ��ֹ����:cur������ͷ���dummy_head��ʼ������1,2Ȼ�󽻻�3,4 �����������5�Ͳ��ý���
   curָ��4��cur->next->next == nullptr����ֹ
   ż��ʱcur->next == nullprt����ֹ
   ��dummy_head��ʼ����tmp����1,3(cur->next��cur->next->next->next)
   Ȼ��2ָ��1��dummy_headָ��2,1(tmp1)ָ��3����
   ���ı�curλ��--cur = cur->next->next
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy_head = new ListNode(0, head);
        ListNode* cur = dummy_head;
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode* tmp1 = cur->next;
            ListNode* tmp2 = cur->next->next->next;
            cur->next->next->next = tmp1;
            cur->next = cur->next->next;
            tmp1->next = tmp2;
            cur = cur->next->next;
        }
        return dummy_head->next;
    }
};