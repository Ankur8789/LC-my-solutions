
class WordDictionary {
public:
    class Trie
    {
        public:
        Trie* children[26]={nullptr};
        bool ending=false;
    };
    Trie* root=nullptr;
    WordDictionary() 
    {
      root=new Trie() ; 
    }
    
    void addWord(string word)
    {
        Trie* fuck=root;
        for(auto t: word)
        {
            if(fuck->children[t-'a']==nullptr)
                fuck->children[t-'a']=new Trie();
            fuck=fuck->children[t-'a'];
        }
        fuck->ending=true;
        
    }
    
    bool search(string word)
    {
        bool ans=f(0,word,root);
        return ans; 
    }
    bool f(int i,string& word,Trie* root)
{
    if(i==word.size())
    {
        if(root->ending)
            return true;
        else
            return false;
    }
    if(word[i]=='.')
    {
        bool ans=false;
        for(int idx=0;idx<26;idx++)
        {
            if(root->children[idx]!=nullptr)
            {
                ans|=f(i+1,word,root->children[idx]);
                if(ans)
                    return true;
            }
        }
        return false;
    }
    else
    {
        if(root->children[word[i]-'a']==nullptr)
            return false;
        else
            return f(i+1,word,root->children[word[i]-'a']);
    }
}
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */