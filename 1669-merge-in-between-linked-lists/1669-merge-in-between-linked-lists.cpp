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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*tail=list2;
        while(tail!=NULL&&tail->next!=NULL)
        {
            tail=tail->next;
        }
       ListNode*temp=list1;
       int c=0;
       ListNode*p=list1;
       while(temp!=NULL&&c<a)
       {
         p=temp;
         temp=temp->next;
         c++;
       }
       while(temp!=NULL&&c<=b)
       {
         temp=temp->next;
         c++;
       } 
     p->next=list2;
     tail->next=temp;
     return list1;
    }
};