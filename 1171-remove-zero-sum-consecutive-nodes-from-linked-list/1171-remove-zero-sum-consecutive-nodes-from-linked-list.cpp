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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        ListNode* it = new_head;
        ListNode* start = head;
        while(start != NULL)
        {
            ListNode* end = start;
            int sum = 0;
            bool found = false;
            while(end != NULL)
            {
                sum += end->val;
                if(sum == 0)
                {
                    found = true;
                    break;
                }
                end = end->next;
            }
            if(!found)
            {
                it->next = new ListNode(start->val);
                it = it->next;
                start = start->next;
            }
            else
            {
                start = end->next;
            }
        }
        it->next = NULL;
        return new_head->next;
    }
};