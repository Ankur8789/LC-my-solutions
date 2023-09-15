class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> col,vis;
    map<pair<int,int>,int> mp;
    bool isPossible(int n, vector<vector<int>>& edges) 
    {
        adj.clear();
        mp.clear();
        for(auto t: edges)
        {
            adj[t[0]].push_back(t[1]);
            adj[t[1]].push_back(t[0]);
            mp[{t[0],t[1]}]++;
            mp[{t[1],t[0]}]++;
            if(min(t[0],t[1])==2 && max(t[0],t[1])==3)
                cout<<"HI"<<endl;
            // cout<<mp[{t[0],t[1]}]<<endl;
        }
        int cnt1=0,cnt2=0,cnt=0;;
        // bool bp=dfs(0,0);
        vector<int> od;
        for(int i=1;i<=n;i++)
        {
            // cout<<i<<" "<<adj[i].size()<<endl;
            if(adj[i].size()&1)
            {
                if(adj[i].size()==n-1)
                    return 0;
                // cout<<i<<endl;
                od.push_back(i);
                cnt++;
            }
        }
        // cout<<cnt<<endl;
        if(cnt&1)
            {cout<<"Hi"<<endl;return 0;}
        if(cnt==0 || cnt==2 || cnt==4)
        {
            if(cnt==0)
                return 1;
            else if(cnt==2)
            {
                // yaha pe bich me ek laga skte hai;
                // cout<<od[0]<<" "<<od[1]<<endl;
                // cout<<(mp.find({od[0],od[1]})==mp.end())<<endl;
                if(mp.find({od[0],od[1]})==mp.end())
                    return 1;
                 for(int i=1;i<=n;i++)
                 {
                     if(mp.find({od[0],i})==mp.end() && mp.find({od[1],i})==mp.end())
                         return 1;
                 }
                  return 0;
            }
            else
            {
                int a=od[0],b=od[1],c=od[2],d=od[3];
                if(mp.find({a,b})==mp.end() && mp.find({c,d})==mp.end())
                    return 1;
                if(mp.find({a,c})==mp.end() && mp.find({b,d})==mp.end())
                    return 1;
                if(mp.find({a,d})==mp.end() && mp.find({c,b})==mp.end())
                    return 1;
                // if(mp.find({a,b})==mp.end() && mp.find({c,d})==mp.end())
                //     return 1;
                return 0;
                
            }
            
                
        }
        else
            return 0;
        
        
    }
};     