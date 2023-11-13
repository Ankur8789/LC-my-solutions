class Solution {
public:
    bool f(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return 1;
        if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            return 1;
        return 0;
    }
    string sortVowels(string s) 
    {
        string vec="";
        for(auto t: s)
        {
            if(f(t))
                vec+=t;
        }
        sort(vec.begin(),vec.end());
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(f(s[i]))
            s[i]=vec[j++];
        }
        return s;
        
    }
};