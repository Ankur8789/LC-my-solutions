class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> freq(nums.size()+1,0);
        for(auto t: nums)
            freq[t]++;
        vector<int> v;
        
        for(int i=0;i<=nums.size();i++)
        {
            bool ok=true;
            for(int j=0;j<=nums.size();j++)
            {
                if(freq[j]>0)
                {
                    v.push_back(j);
                    freq[j]--;
                    ok=false;
                }
            }
            if(ok)
                break;
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};