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
    ListNode* f(ListNode* head,int val)
    {    if(head==nullptr)
        return nullptr;
        if(head->next==nullptr)
        {
            if(head->val==val)
                return nullptr;
            else
                return head;
        }
        ListNode* t=f(head->next,val);
        if(head->val==val)
            return t;
        head->next=t;
        return head;
    }
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* ans=f(head,val);
        return ans;
    }
};