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
    unordered_map<int,int> m;
    int l;
    Solution(ListNode* head) 
    {
        ListNode* cur = head;
        l = 0;
        while(cur)
        {
            m[l] = cur->val;
            ++l;
            cur = cur->next;
        }
    }
    
    int getRandom() 
    {
        int x = rand()%l;
        return m[x];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */