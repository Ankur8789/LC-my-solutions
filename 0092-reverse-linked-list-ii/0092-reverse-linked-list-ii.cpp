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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode* p=head;
        vector<int> ans;
        int k=1;
        while(p!=NULL)
        {
           if(k<=right && k>=left)
               ans.push_back(p->val);
            k++;
            p=p->next;
        }
        reverse(ans.begin(),ans.end());
        p=head;k=1;int l=0;
        while(p!=NULL)
        {
            if(k<=right && k>=left)
            {
                p->val=ans[l];
                l++;
            }
            k++;
            p=p->next;
        }
        return head;
    }
};