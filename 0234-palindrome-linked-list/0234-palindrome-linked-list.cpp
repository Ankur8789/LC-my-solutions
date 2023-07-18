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
ListNode* reverse(ListNode* ptr)
{
    ListNode* pre=NULL;
    ListNode* nex=NULL;
    while(ptr!=NULL) 
    {
        nex = ptr->next;
        ptr->next = pre;
        pre=ptr;
        ptr=nex;
    }
    return pre;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        if(head==nullptr || head->next==nullptr)
            return true;
        ListNode* one=head;
        ListNode* two=head;
        while(one!=nullptr && two!=nullptr && two->next!=nullptr && two->next->next!=nullptr)
        {
             one=one->next;
             two=two->next->next;
        }
        one->next=reverse(one->next);
        ListNode* a=head;
        ListNode* b=one->next;
        while(a!=nullptr && b!=nullptr)
        {
            if(a->val!=b->val)
                return false;
            a=a->next;
            b=b->next;
        }
        return true;
    }
};