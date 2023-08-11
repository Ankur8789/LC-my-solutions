class Solution {
public:
    static bool cmp(int a,int b)
    {
        string as=to_string(a);
        string bs=to_string(b);
        return as+bs<bs+as;
        
    }
    string largestNumber(vector<int>& nums) 
    {
        if(nums.size()==0)
            return "";
        bool ok=false;
        sort(nums.begin(),nums.end(),cmp);
        reverse(nums.begin(),nums.end());
        string res="";
        for(auto t: nums)
        {
            if(t!=0)
                ok=true;
            // cout<<t<<" ";
            res+=to_string(t);
        }
        if(!ok)
            return "0";
        return res;
    }
};