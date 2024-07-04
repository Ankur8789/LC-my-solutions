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
    ListNode* mergeNodes(ListNode* head) 
    {
       vector<int> pre;
       int sum=0;
       ListNode* t=head;
       t=t->next;
       while(t!=nullptr)
       {
           while(t->val)
           {
               sum+=t->val;
               t=t->next;
           }
           pre.push_back(sum);
           sum=0;
           t=t->next;
       }
        ListNode* temp=new ListNode();
        ListNode* nhead=temp;
        for(int i=0;i<pre.size();i++)
        {
            temp->val=pre[i];
            if(i!=pre.size()-1)
            {
                temp->next=new ListNode();
                temp=temp->next;
            }
            else
                temp->next=nullptr;
        }
        return nhead;
    }
};