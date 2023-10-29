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
   思路：dummy_head 1 2 3 4 5
   终止条件:cur从虚拟头结点dummy_head开始，交换1,2然后交换3,4 如果是奇数，5就不用交换
   cur指向4，cur->next->next == nullptr就终止
   偶数时cur->next == nullprt就终止
   从dummy_head开始，用tmp保存1,3(cur->next和cur->next->next->next)
   然后2指向1，dummy_head指向2,1(tmp1)指向3即可
   最后改变cur位置--cur = cur->next->next
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