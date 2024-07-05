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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
      ListNode* pre=head;ListNode* curr=head->next;ListNode *post=curr->next;
      vector<int> rem;
      int idx=1;
      while(curr!=nullptr && post!=nullptr)
      {
          if(curr->val>pre->val && curr->val>post->val)
              rem.push_back(idx);
          if(curr->val<pre->val && curr->val<post->val)
              rem.push_back(idx);
          ++idx;
          pre=pre->next;
          curr=curr->next;
          post=post->next;
      }
      if(rem.size())
      {
         if(rem.size()==1)
             return {-1,-1};
         else
         {
             int mini=1e9,maxi=-1e9;
             maxi=max(maxi,rem.back()-rem[0]);
             for(int i=0;i<rem.size()-1;i++)
                 mini=min(mini,rem[i+1]-rem[i]);
             return {mini,maxi};
         }
      }
      else
          return {-1,-1};
    }
};