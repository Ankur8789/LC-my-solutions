class Solution {
public:
    string firstPalindrome(vector<string>& wd) 
    {
        string ans="";
        for(int i=0;i<wd.size();i++)
        {
            string temp=wd[i];
            reverse(temp.begin(),temp.end());
            if(wd[i]==temp)
                return wd[i];
        }
        return ans;
    }
};