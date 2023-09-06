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
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        ListNode *temp = head;
        int len = 0;
        vector<ListNode*> ans;
        while(temp) 
        {
            temp = temp->next;
            len++;
        }
        if(len < k)
        {
            int i = 0;
            while(head) 
            {
                ListNode *q = new ListNode(head->val);
                ans.push_back(q);
                head = head->next;
                i++;
            }
            while(i < k) 
            {
                ans.push_back({});
                i++;
            }
        }
        int ele = len / k, add = len % k;
        while(head) 
        {
            ListNode *p = head, *q = head;
            for(int i = 0; i < ele && head; i++) 
            {
                q = head;
                head = head->next;
            }
            if(add) 
            {
                q = head;
                head = head->next;
                --add;
            }
            if(q)
                q->next = NULL;
            ans.push_back(p);
        }
        return ans;
    }
};