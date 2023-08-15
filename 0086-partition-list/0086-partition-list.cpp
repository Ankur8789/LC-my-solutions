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
    ListNode* partition(ListNode* head, int x) 
    {
        if(head==nullptr)
            return nullptr;
       vector<int> less,great;
       ListNode* temp=head;
       while(temp!=nullptr)
       {
           if(temp->val<x)
               less.push_back(temp->val);
           else
               great.push_back(temp->val);
           temp=temp->next;
       }
       ListNode* neww=new ListNode();
       ListNode* h=neww;
       ListNode* last=neww;
       int i=0;
       while(i<less.size())
       {
           neww->val=less[i];
           if(i==less.size()-1 && great.size()==0)
               break;
           neww->next=new ListNode();
           neww=neww->next;
           i++;
       }
       i=0;
       while(i<great.size())
       {
           neww->val=great[i];
           if(i!=great.size()-1)
           neww->next=new ListNode();
           neww=neww->next;
           i++;
       }
       
        return h;
        
    }
};