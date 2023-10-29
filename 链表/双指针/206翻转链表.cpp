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
  解法1：双指针： pre=null ，cur = head， 结束条件：cur->null,pre--5,
                  pre(null)       head      1   2  3  4  5  null
  tmp = cur-next() --1,cur->next = pre, pre = cur, cur = tmp;
  解法2：递归
  结束条件(cur == null)
  初始传入reverse(head, null)
  递归传入reverse(tmp,  cur);
  递归代码：tmp = cur->next, cur->next = pre;
*/
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;

        while (cur != nullptr)
        {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

class Solution2{
public:
    ListNode* reverse(ListNode* cur, ListNode* pre)
    {
        if (cur == nullptr)return pre;
        ListNode* tmp = cur->next;
        cur->next = pre;
        return reverse(tmp, cur);;
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(head, nullptr);
    }
};