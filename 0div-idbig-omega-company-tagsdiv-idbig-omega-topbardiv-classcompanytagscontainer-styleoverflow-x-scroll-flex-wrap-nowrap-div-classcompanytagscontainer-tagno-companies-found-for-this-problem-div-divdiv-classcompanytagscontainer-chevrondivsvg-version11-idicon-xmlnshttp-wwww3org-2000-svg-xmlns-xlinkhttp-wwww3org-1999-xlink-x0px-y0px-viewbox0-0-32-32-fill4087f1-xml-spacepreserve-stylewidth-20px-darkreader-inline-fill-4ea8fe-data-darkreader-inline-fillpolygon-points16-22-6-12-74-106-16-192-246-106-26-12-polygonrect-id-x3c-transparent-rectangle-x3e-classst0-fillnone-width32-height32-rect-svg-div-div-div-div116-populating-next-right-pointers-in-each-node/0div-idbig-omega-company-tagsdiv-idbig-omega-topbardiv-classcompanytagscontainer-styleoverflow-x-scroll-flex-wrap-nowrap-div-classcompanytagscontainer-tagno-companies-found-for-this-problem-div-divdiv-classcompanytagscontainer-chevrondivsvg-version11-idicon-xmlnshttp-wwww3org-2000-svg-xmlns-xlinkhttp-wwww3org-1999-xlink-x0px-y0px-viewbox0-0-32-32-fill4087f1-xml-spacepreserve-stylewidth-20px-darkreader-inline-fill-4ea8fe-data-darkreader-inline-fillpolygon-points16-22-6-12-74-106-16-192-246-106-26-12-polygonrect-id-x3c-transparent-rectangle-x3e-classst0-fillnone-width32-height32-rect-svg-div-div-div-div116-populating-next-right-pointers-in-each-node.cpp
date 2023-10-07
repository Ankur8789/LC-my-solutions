/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root==nullptr)return root;
        queue<Node*> q;
        q.push(root);
        while(q.size()>0)
        {
            int sz=q.size();
            vector<Node*> v;
            while(sz--)
            {
                auto x=q.front();
                q.pop();
                v.push_back(x);
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
            }
            int n=v.size();
            for(int i=0;i<n-1;i++)
                v[i]->next=v[i+1];
            v[n-1]->next=nullptr;
        }
        return root;
    }
};