class Solution {
public:
    class Trie
    {
        public:
        Trie* child[2]={nullptr};
        bool end=false;
    };
    Trie* root;
    int findMaximumXOR(vector<int>& nums) 
    {
        if(nums.size()==0)
            return 0;
        root=new Trie();
        
        for(auto t: nums)
        {
            Trie* temp=root;
            int val=t;
            for(int i=31;i>=0;i--)
            {
                int bit=(val>>i)&1;
                // cout<<bit<<" "<<i<<" "<<val<<endl;
                if(temp->child[bit]==nullptr)
                {
                    temp->child[bit]=new Trie();
                }
                temp=temp->child[bit];
            }
            temp->end=true;
        }
        int ans=0;
        for(auto t: nums)
        {
            int val=t;
            Trie* pre=root;
            int res=0;
            for(int i=31;i>=0;i--)
            {
                int bit=(val>>i)&1;
                int req=bit^1;
                if(pre->child[req]!=nullptr)
                {
                    res|=(req<<i);
                    pre=pre->child[req];
                }
                else
                {
                    res|=(bit<<i);
                    pre=pre->child[bit];
                }
            }
            // cout<<res<<endl;
            ans=max(ans,res^t);
        }
        return ans;
    }
};