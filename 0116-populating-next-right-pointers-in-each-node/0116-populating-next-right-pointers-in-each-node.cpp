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
    Node* connect(Node* root) {
        if(root==nullptr)
            return root;
        queue<Node*> q;
        q.push(root);
        while(q.size() > 0){
            int sz=q.size();
            vector<Node*> vec;
            while(sz--){
                auto r=q.front();
                q.pop();
                vec.push_back(r);
                if(r->left)
                    q.push(r->left);
                if(r->right)
                    q.push(r->right);
            }
            int m = vec.size();
            for(int i=0;i < m-1;i++)
                vec[i] -> next = vec[i+1];
            vec[m-1]->next=nullptr;
        }
        return root;
    }
};