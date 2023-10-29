#define  _CRT_SECURE_NO_WARNINGS

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
/*
   思路：找到倒数第n个节点的前一个节点
   方法：双指针，fast先走n+1步，然后fast和slow同时走直到fast指向了null(尾结点的下一个节点)，这时候slow就指向了要删除节点的前一个
   size = 3 +dummy_head = 4, fast一共走了size + 1步:slow走了size+1-n-1 =size-n步
   n+size-n = size，由于slow从dummy_head开始走，所以slow会落在要删除的节点的前一个位置。
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy_head = new ListNode(0, head);
        ListNode* fast = dummy_head;
        ListNode* slow = dummy_head;
        while (n--)
            fast = fast->next;
        fast = fast->next;
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy_head->next;
    }
};