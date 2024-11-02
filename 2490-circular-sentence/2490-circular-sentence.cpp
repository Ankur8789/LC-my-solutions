class Solution {
public:
    bool isCircularSentence(string s){
        bool flag=-1;
        for(int i=0;i<s.length();i++){   
            if(s[i]==' '){   
                if(s[i+1]!=s[i-1])
                    return false;
            }
        }
        if(s[s.length()-1]==s[0])
            return true;
        else
            return false;
    }
};