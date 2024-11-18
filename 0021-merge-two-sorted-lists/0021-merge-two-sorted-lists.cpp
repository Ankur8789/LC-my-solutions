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
    ListNode* mergeTwoLists(ListNode* t1, ListNode* t2) {
        if(t1==nullptr)
            return t2;
        if(t2==nullptr)
            return t1;
        ListNode* tem=new ListNode(-1);
        ListNode* ini =tem;
        while(t1!=nullptr && t2!=nullptr){
            if(t1->val<t2->val){
                tem->next=t1;
                tem=tem->next;
                t1=t1->next;
            }
            else{
                tem->next=t2;
                tem=tem->next;
                t2=t2->next;
            }
        }
        if(t1)
            tem->next=t1;
        else if(t2)
            tem->next=t2;
        return ini->next;
    }
};