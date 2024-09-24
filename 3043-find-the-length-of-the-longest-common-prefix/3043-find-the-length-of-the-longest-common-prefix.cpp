class Solution {
public:
    class Trie{
        public:
        Trie* child[10]={nullptr};
        int end = 0;
    };
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* root=new Trie();
        for(auto x: arr1){
            Trie* temp = root;
            string s=to_string(x);
            int cnt=1;
            for(auto y: s){
                if(temp->child[y-'0']==nullptr)
                    temp->child[y-'0']=new Trie();
                temp->end=cnt;
                temp=temp->child[y-'0'];
                cnt++;
                
            }
            temp->end=cnt;
        }
        int ans=0;
        for(auto x: arr2){
            Trie* temp=root;
            string s=to_string(x);
            for(auto y: s){
                if(temp->child[y-'0']==nullptr)
                    break;
                else
                    ans=max(ans,temp->end),temp=temp->child[y-'0'];
            }
        }
        return ans;
    }
};