class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<pair<double,pair<int,int>>> pq;
        for(auto t: points)
        {
            double dist=(t[0]*t[0] + t[1]*t[1]);
            pq.push({dist,{t[0],t[1]}});
        }
        vector<vector<int>> ans;
        while(pq.size())
        {
            pair<int,pair<int,int>> p=pq.top();
            pq.pop();
            ans.push_back({p.second.first,p.second.second});
        }
        int n=ans.size()-1;
        int i=n;
        vector<vector<int>> sex;
        while(k--)
        {
            sex.push_back(ans[i]);
            i--;
        }
        
        return sex;
        
    }
};