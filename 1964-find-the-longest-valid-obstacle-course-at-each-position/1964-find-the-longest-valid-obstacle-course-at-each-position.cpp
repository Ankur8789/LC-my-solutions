class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) 
    {
        vector<int> ans;
        vector<int> v;
        ans.push_back(1);
        v.push_back(obs[0]);
        for(int i=1;i<obs.size();i++)
        {
            if(obs[i]>=v.back())
            {
                v.push_back(obs[i]);
                ans.push_back(v.size());
            }
            else
            {
                int l=0,r=v.size()-1;
                int anss=-1;
                while(l<=r)
                {
                    int mid=(l+r)/2;
                    if(v[mid]>obs[i])
                    {
                        anss=mid;
                        r=mid-1;
                    }
                    else
                        l=mid+1;      
                }
                ans.push_back(anss+1);
                v[anss]=obs[i];
            }
        }
        return ans;
    }
};