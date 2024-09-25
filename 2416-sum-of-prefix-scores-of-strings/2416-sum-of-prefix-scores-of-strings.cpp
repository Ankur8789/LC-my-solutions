class Solution {
public:
    class Trie{
        public:
        Trie* child[26]={nullptr};
        int end=0;
    };
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* root=new Trie();
        for(auto x: words){
            Trie* temp=root;
            for(auto y:x){
                if(temp->child[y-'a']==nullptr)
                    temp->child[y-'a']=new Trie();
                temp=temp->child[y-'a'];
                temp->end++;
            }
        }
        vector<int> ans;
        for(auto x: words){
            int cnt=0;
            Trie* temp=root;
            for(auto y: x){
                cnt+=temp->child[y-'a']->end;
                temp=temp->child[y-'a'];
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};