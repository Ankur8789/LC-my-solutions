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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || k==1)
            return head;
        int nodes=0;
        ListNode* dummy=new ListNode(-1);
        ListNode* pre=dummy;
        ListNode*curr=dummy;
        ListNode*nex=dummy;
        ListNode* start=head;
        dummy->next=head;
        while(start!=nullptr){
            nodes++;
            start=start->next;
        }
        while(nodes>=k){
            // group of size k
            curr=pre->next;
            nex=curr->next;
            for(int i=1;i<k;i++){
                curr->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=curr->next;
            }
            pre=curr;
            nodes-=k;
        }
        return dummy->next;
        
    }
};