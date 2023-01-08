class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {    
        int mx=0;   
        for(int i=0;i<points.size();i++)
        {  unordered_map<double,int> mp;
            for(int j=0;j<points.size();j++)
            {
                if(i==j)continue;
                double x=points[i][0]-points[j][0];
                double y=points[i][1]-points[j][1];
                double z =double(x)/double(y);
                mp[z]++;
            }
            int hex=0;
            for(auto t:mp)
                hex=max(hex,t.second);
         mx=max(mx,hex);
        }
        return mx+1;
    }
};