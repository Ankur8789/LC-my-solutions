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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        ListNode* temp=new ListNode(0);
        int cnt=0;
        ListNode* hey=temp;
        ListNode* pre=temp;
        map<int,int> mp;
        for(auto x: nums)mp[x]+=1;
        while(head!=nullptr)
        {
           if(!mp.count(head->val))
           {
               hey->val=head->val;
               hey->next=new ListNode(0);
               pre=hey;
               hey=hey->next;
               cnt++;
           }
           head=head->next;
           
        }
        pre->next=nullptr;
        if(cnt==0)
            return nullptr;
        else
            return temp;
    }
};