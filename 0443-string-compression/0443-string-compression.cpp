class Solution 
{
public:
    int compress(vector<char>& chars) 
    {
        if(chars.size()<=1)
            return chars.size();
        int count = 1;
        string s= "";
        for(int i=1; i<chars.size(); i++)
        {
            if(chars[i]==chars[i-1])
                count++;
            else
            {
                s+=chars[i-1];
                if(count!=1)
                    s+=to_string(count);
                count=1;
            }
        }
        s+=chars[chars.size()-1];
        if(count!=1)
            s+=to_string(count);
        chars.clear();
        for(int i=0; i<s.size(); i++)
        {
            chars.push_back(s[i]);
        }
        return s.size();
    }
};