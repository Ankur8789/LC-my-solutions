/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* f(ListNode* head)
    {
        if(head==nullptr)
            return nullptr;
        if(head->next==nullptr)
            return head;
        ListNode* temp=f(head->next);
        head->next->next=head;
        head->next=nullptr;
        return temp;
    }
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* s=f(head);
        return s;
    }
};