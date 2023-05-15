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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        int cnt=0;
        ListNode* t=head;
        ListNode* a;
        ListNode* b;
        while(t!=nullptr)
        {
             t=t->next;
             cnt++;
        }
        int ck=1;
        t=head;
        while(t!=nullptr)
        {
            if(ck==k)
            {
                a=t;
                break;
            }
            t=t->next;
            ck++;
        }
        t=head;
        ck=1;
        while(t!=nullptr)
        {
            if(ck==cnt-k+1)
            {
                b=t;
                break;
            }
            t=t->next;
            ck++;
        }
        swap(a->val,b->val);
        return head;
        
    }
};