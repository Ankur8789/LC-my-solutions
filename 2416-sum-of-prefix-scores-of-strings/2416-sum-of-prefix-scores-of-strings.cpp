class Solution {
public:
    class Trie
    {
        public:
        Trie* child[26]={nullptr};
        bool ending =false;
        int cnt=0;
    };
    vector<int> sumPrefixScores(vector<string>& words)
    {
        Trie* root=new Trie();
        for(auto t: words)
        {
            Trie* temp=root;
            for(int i=0;i<t.size();i++)
            {
                if(temp->child[t[i]-'a']==nullptr)
                {
                    temp->child[t[i]-'a']=new Trie();                    
                }
                temp->child[t[i]-'a']->cnt++;
                temp=temp->child[t[i]-'a']; 
                
            }
            temp->ending=true;   
        }
        vector<int> ans;
        for(auto t: words)
        {
            Trie* node = root;
            int cc=0;
            for(int i=0;i<t.size();i++)
            { 
                cc+=node->child[t[i]-'a']->cnt;
                node=node->child[t[i]-'a'];
            }
            ans.push_back(cc);
        }
        return ans;
        
    }
};