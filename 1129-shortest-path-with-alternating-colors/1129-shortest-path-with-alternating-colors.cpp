class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b)
    {
        vector<vector<pair<int,int>>>v(n);
        vector<vector<int>>dis(n,vector<int>(2,1e9));
        queue<pair<int,int>>q;
        
        for(auto i:r)
        {
            v[i[0]].push_back({i[1],0});
        }
        for(auto i:b)
        {
            v[i[0]].push_back({i[1],1});
        }
        dis[0][0]=0;
        dis[0][1]=0;
        q.push({0,0});
        q.push({0,1});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int node=it.first,color=it.second;
            for(auto i:v[node])
            {
                int new_node=i.first,new_color=i.second;
                if(dis[new_node][new_color]>dis[node][color]+1 && color!=new_color)
                {
                    dis[new_node][new_color]=dis[node][color]+1;
                    q.push(i);
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int temp=min(dis[i][0],dis[i][1]);
            if(temp==1e9)
               temp=-1;
            ans.push_back(temp);   
        }
        return ans;
    }
};