class Solution {
public:
    unordered_set<string> st;
    string res="";
    void f(int i,int n,string s)
    {
        if(i==n)
        {
            if(st.find(s)==st.end())
                res=s;
           return ;
        }
        f(i+1,n,s+'0');
        f(i+1,n,s+'1');
    }
    string findDifferentBinaryString(vector<string>& nums) 
    {
        for(auto t: nums)
            st.insert(t);
        f(0,nums[0].size(),"");
        return res;
        
    }
};