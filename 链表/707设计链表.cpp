#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


class MyLinkedList {
public:
    typedef struct ListNode
    {
        int val;
        ListNode* next;
        ListNode(int val = 0, ListNode* next = nullptr)
            :val(val), next(next) {}
    }Node;

    MyLinkedList() {
        dummy_head = new Node(0);
    }

    int get(int index) {
        if (index < 0 || index >(size - 1))//size初始为0，head加完之后为1,但是head下标为0
            return -1;
        Node* cur = dummy_head;
        while (index--)
        {
            cur = cur->next;
        }
        return cur->next->val;
    }

    void addAtHead(int val) {
        Node* new_head = new Node(val, dummy_head->next);
        dummy_head->next = new_head;
        size++;
    }

    void addAtTail(int val) {
        Node* cur = dummy_head;
        while (cur->next != nullptr)
            cur = cur->next;

        Node* add = new Node(val);
        cur->next = add;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size || index < 0)return;//==就是添加到结尾，>就非法
        Node* cur = dummy_head;
        while (index--)
            cur = cur->next;

        Node* add = new Node(val, cur->next);
        cur->next = add;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;

        Node* cur = dummy_head;
        while (index--)
            cur = cur->next;

        Node* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        tmp = nullptr;
        size--;
    }

private:
    int size = 0;
    Node* dummy_head;
};