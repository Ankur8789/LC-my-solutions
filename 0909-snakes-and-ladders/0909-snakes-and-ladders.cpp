class Solution {
public:
    typedef long long ll;
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        queue<pair<ll,ll>> q;
        ll n=board.size();
        vector<vector<int>> x=board;
        vector<int> vis(n*n +1);
        ll k=1;
        for(int i=0;i<x.size();i++)
        {
            for(int j=0;j<x[0].size();j++)
            {
                x[i][j]=k++;
            }
        }
        // building  Boustrophedon style
        for(int i=0;i<x.size();i++)
        {
            if(i%2!=0)
                reverse(x[i].begin(),x[i].end());
        }
        reverse(x.begin(),x.end());
        
        unordered_map<ll,pair<ll,ll>> mp;
        for(ll i=0;i<x.size();i++)
        {
            for(ll j=0;j<x[0].size();j++)
            {
                 mp[x[i][j]].first=i;
                 mp[x[i][j]].second=j;
            }
            
        }
        
        
        q.push({n-1,0});
        ll t=1;
        while(q.size()>0)
        {
            ll sz=q.size();
            while(sz--)
            {
                pair<ll,ll> p=q.front();
                q.pop();
                ll a=p.first;
                ll b=p.second;
                for(ll i=1;i<=6;i++)
                {
                    if(x[a][b]+i== n*n)
                        return t;
                    ll temp=x[a][b]+i;
                    if(board[mp[temp].first][mp[temp].second]==-1 && vis[temp]==0)
                    {
                        q.push({mp[temp].first,mp[temp].second});
                        vis[temp]=1;
                    }
                    else
                    {   if(board[mp[temp].first][mp[temp].second]== n*n)
                        return t;
                        if(vis[temp]==0)
                        {
                            
                            q.push({mp[board[mp[temp].first][mp[temp].second]].first,mp[board[mp[temp].first][mp[temp].second]].second});
                            vis[temp]=1;
                        }
                    }
                }
           
            }
           t++;
        }
     
        return -1;
    }
};