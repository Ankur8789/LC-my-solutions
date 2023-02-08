#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
class Solution {
public:
    int minJumps(vector<int>& arr) 
    {   fastio()   ;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]].push_back(i);
        }
        int n=arr.size();
        vector<int> vis(n);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        int cnt=0;
        while(q.size()>0)
        {
            int sz=q.size();
            while(sz--)
            {
                int x=q.front();
                q.pop();
                if(x==n-1)
                    return cnt;
                if(x-1>=0 && vis[x-1]==0)
                {   
                    q.push(x-1);
                    vis[x-1]=1;
                }
                if(x+1<n && vis[x+1]==0)
                {
                    q.push(x+1);
                    vis[x+1]=1;
                }
                vector<int> f=mp[arr[x]];
                for(int i=0;i<f.size();i++)
                {
                    if(vis[f[i]]==1)
                        continue;
                    if(x==f[i])
                        continue;
                    q.push(f[i]);
                    vis[f[i]]=1;
                }
                mp[arr[x]].clear();
            }
            ++cnt;
        }
        return 0;
    }
};