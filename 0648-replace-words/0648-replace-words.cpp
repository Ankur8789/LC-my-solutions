class Solution {
public:
    class Trie
    {
       public:
       bool found=false;
       Trie* child[26]={nullptr};
    };
    
    string replaceWords(vector<string>& dict, string sen) 
    {
       Trie* root=new Trie();
       for(auto x: dict)
       {
           Trie* temp=root;
           for(int i=0;i<x.size();i++)
           {
              if(temp->child[x[i]-'a']==nullptr)
                  temp->child[x[i]-'a']=new Trie();
               temp=temp->child[x[i]-'a'];
               
           }
           
           temp->found=true;
           
       }
       
       int i=0;
       int n=sen.size();
       string str="",ans="";
       while(i<n)
       {
           while(i<n && sen[i]!=' ')
               str+=sen[i],i++;
           
           string ps="";
           bool ok=false;
           Trie* temp=root;
           for(auto x: str)
           {
               if(temp->child[x-'a']==nullptr)
                   break;
               temp=temp->child[x-'a'];
               ps+=x;
               if(temp->found==true)
               {
                   ok=true;
                   break;
               }
           }
           if(ok)
               ans+=ps;
           else
               ans+=str;
           ans+=' ';
           str="";
           i++;
       }
        ans.pop_back();
        return ans;
      
    }
};