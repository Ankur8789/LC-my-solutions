class Solution {
public:
    string gcdOfStrings(string str1, string str2) 
    {
        string ans;
        int l=min(str1.length(),str2.length());
        for(int i=0;i<l;i++)
        {
            if(str1.length()%(i+1)==0 && str2.length()%(i+1)==0)
            {
                string temp=str1.substr(0,i+1);
                int x=str1.length()/(i+1);
                int y=str2.length()/(i+1);
                string fstr1="";
                string fstr2="";
                for(int i=0;i<x;i++)
                    fstr1+=temp;
                for(int i=0;i<y;i++)
                    fstr2+=temp;
                if(fstr1==str1 && fstr2==str2)
                    ans=temp;
            }
        }
        return ans;
    }
};