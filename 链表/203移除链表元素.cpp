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
  * 写法一：以统一的方式来删除，设置一个虚拟head，然后从虚拟head的next开始判断
  * 写法二：分两种情况，一种是head->val==val; 另一种情况是非head->val==val;
  */

  class Solution1 {
  public:
      ListNode* removeElements(ListNode* head, int val) {
          ListNode* dummy_head = new ListNode(0, head);
          ListNode* cur = dummy_head;
          while (cur !=nullptr && cur->next != nullptr)
          {
              if (cur->next->val == val)
              {
                  ListNode* tmp = cur->next;
                  cur->next = cur->next->next;
                  delete tmp;
              }
              else
                  cur = cur->next;
          }

          head = dummy_head->next;
          delete dummy_head;
          return head;

      }
  };
  class Solution2 {
  public:
      ListNode* removeElements(ListNode* head, int val) {

          while (head != nullptr && head->val == val)
          {
              head = head->next;
          }
          ListNode* cur = head;
          while (cur != nullptr && cur->next != nullptr)
          {
              if (cur->next->val == val)
              {
                  ListNode* tmp = cur->next;
                  cur->next = cur->next->next;
                  delete tmp;
              }
              else
                  cur = cur->next;
          }
          return head;
      }
  };