class Solution {
public:
    class Trie
    {
        public:
        Trie* child[2]={nullptr};
        bool end=false;
    };
    int findMaximumXOR(vector<int>& nums) 
    {
        Trie* root=new Trie();
        for(auto t: nums)
        {
            int val=t;
            Trie* p=root;
            for(int i=31;i>=0;i--)
            {
                int bit=((val>>i)&1);
                if(p->child[bit]==nullptr)
                {
                    p->child[bit]=new Trie();
                }
                p=p->child[bit];
            }
        }
        int ans=0;
        for(auto t: nums)
        {
            int val=t;
            Trie* p=root;
            int res=0;
            for(int i=31;i>=0;i--)
            {
                int bit=((val>>i)&1);
                int req=bit^1;
                if(p->child[req]==nullptr)
                {
                    res|=(bit<<i);
                    p=p->child[bit];
                }
                else
                {
                    res|=(req<<i);
                    p=p->child[req];
                }
            }
            ans=max(ans,res^t);
        }
        return ans;
    }
};