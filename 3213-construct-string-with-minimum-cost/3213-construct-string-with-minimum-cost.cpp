class Solution {
public:
    int dp[50001];
    class Trie
    {
      public:
        Trie* child[26]={nullptr};
        bool end=false;
        int cost=1e9;
    };
    Trie* hex;
    int f(int i,string& target)
    {
        if(i>=target.size())
            return 0;
        auto&x=dp[i];
        if(x!=-1)
            return x;
        int ans=1e9;
        int idx=i;
        Trie* trie=hex;
        // string str="";
        for(int j=idx;j<target.size();j++)
        {
            if(trie->child[target[j]-'a']==nullptr)
                break;
            // str+=target[j];
            trie=trie->child[target[j]-'a'];
            if(trie->end)
            {
                // cout<<str<<" "<<trie->cost<<endl;
                ans=min(ans,trie->cost+f(j+1,target));
            }
        }
        return x=ans;
    }
    int minimumCost(string target, vector<string>& words, vector<int>& costs) 
    {
        Trie* root=new Trie();
        int cnt=0;
        for(auto x: words)
        {
            Trie* temp=root;
            for(auto w: x)
            {
                if(temp->child[w-'a']==nullptr)
                    temp->child[w-'a']=new Trie();
                temp=temp->child[w-'a'];
            }
            temp->end=true;
            // cout<<x<<" "<<costs[cnt]<<endl;
            temp->cost=min(costs[cnt++],temp->cost);
            // cout<<temp->cost<<endl;
        }
        hex=root;
        memset(dp,-1,sizeof(dp));
        int ans=f(0,target);
        if(ans==1e9)
            ans=-1;
        return ans;
        
    }
};