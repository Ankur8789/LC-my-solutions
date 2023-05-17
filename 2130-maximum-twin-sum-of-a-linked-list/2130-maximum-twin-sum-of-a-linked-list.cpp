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
    int pairSum(ListNode* head) 
    {
        vector<int> f;
        ListNode* t=head;
        while(t!=nullptr)
        {
            f.push_back(t->val);
            t=t->next;
        }
        int res=0,sum=0;
        for(int i=0;i<f.size();i++)
        {
            res=max(res,f[i]+f[f.size()-1-i]);
        }
        return res;
       
    }
};