#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
  思路：fast一次走两步，slow一次走一步，如果有环他们必定相遇，设环的长度为n，head到环入口的长度为x，他们在环中相遇走过的的长度为y，
  z = n-y 则fast走过的距离 = x +n(y+z) slow走过的距离为x + y（必定在slow第一次走进圈就追上）
  因为fast的速度是slow的两倍，不论slow进圈的时候fast在哪里，fast都必定在slow走完一圈之前追上slow
  则x+n(y+z) + y = 2(x + y) ---> x = n(y+z)-y--> x=(n-1)(y+z) + z,当n=1时，x=z，即slow刚刚到入口时，fast和时候再入口相遇
  由x = (n - 1)(y + z) + z可知，若设index1为快慢指针相遇的位置，index2从head开始走，index1和index2必定在环的入口相遇
  index1(z)比index2(x)多走了(n-1)*环的长度圈,当index1==index2时，环的入口就是他们所在的位置。
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