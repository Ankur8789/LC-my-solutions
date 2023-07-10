class MapSum {
public:
    class TrieNode
    { 
        public:
         TrieNode* children[26]={nullptr};
         int wt=0;
    };
    TrieNode* root=nullptr;
    MapSum() {
        root=new TrieNode();
    }
    
    void insert(string key, int val) 
    {
        TrieNode* p=root;
        for(auto t: key)
        {
            if(p->children[t-'a']==nullptr)
                p->children[t-'a']=new TrieNode();
            p=p->children[t-'a'];
        }
        p->wt=val;
    }
    int dfs(TrieNode* p)
    {
        if(p==nullptr)
            return 0;
        int sum=0;
        sum+=p->wt;
        for(int i=0;i<26;i++)
        {
            sum+=dfs(p->children[i]);
        }
        return sum;
    }
    int sum(string prefix) 
    {
        TrieNode* p=root;
        for(auto t: prefix)
        {
            if(p->children[t-'a']==nullptr)
                return 0;
            p=p->children[t-'a'];
        }
        int ans=dfs(p);
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */