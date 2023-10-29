#define  _CRT_SECURE_NO_WARNINGS

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
/*
   ˼·���ҵ�������n���ڵ��ǰһ���ڵ�
   ������˫ָ�룬fast����n+1����Ȼ��fast��slowͬʱ��ֱ��fastָ����null(β������һ���ڵ�)����ʱ��slow��ָ����Ҫɾ���ڵ��ǰһ��
   size = 3 +dummy_head = 4, fastһ������size + 1��:slow����size+1-n-1 =size-n��
   n+size-n = size������slow��dummy_head��ʼ�ߣ�����slow������Ҫɾ���Ľڵ��ǰһ��λ�á�
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