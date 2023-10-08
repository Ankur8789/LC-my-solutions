
class WordDictionary {
public:
    class Trie
    {
        public:
       Trie* child[26]={nullptr};
       bool end=false;
    };
    Trie* root;
    WordDictionary() 
    {
       root=new Trie();  
    }
    
    void addWord(string word) 
    {
       Trie* temp=root;
       for(auto t: word)
       {
           if(temp->child[t-'a']==nullptr)
               temp->child[t-'a']=new Trie();
           temp=temp->child[t-'a'];
       }
       temp->end=true;
    }
    
    bool search(string word) 
    {
         Trie* temp=root;
         return f(0,word,temp);
    }
    bool f(int i,string& word,Trie* root)
    {
        if(i==word.size())
            return root->end;
        if(word[i]=='.')
        {
            bool ans=false;
            for(int idx=0;idx<26;idx++)
            {
                if(root->child[idx]!=nullptr)
                {
                    ans|=f(i+1,word,root->child[idx]);
                    if(ans)
                        return true;
                }
            }
            return false;
        }
        else
        {
            if(root->child[word[i]-'a']==nullptr)
                return false;
            else
                return f(i+1,word,root->child[word[i]-'a']);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */