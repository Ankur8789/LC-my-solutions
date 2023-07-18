/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
       // checking if cycle exists 
        ListNode* one=head;
        ListNode* two=head;
        bool ok=false;
        while(one!=nullptr && two!=nullptr && two->next!=nullptr && two->next->next!=nullptr)
        {
            one=one->next;
            two=two->next->next;
            if(one==two)
            {
                ok=true;
                break;
            }
        }
        if(!ok)
            return nullptr;
        ListNode* st=head;
        while(st!=one)
        {
            st=st->next;
            one=one->next;
        }
        return one;
    }
};