int parent[200001];
int siz[200001];
void make(int v){
    parent[v] = v;
    siz[v] = 1;
}
int find(int v){
    if (parent[v] == v)
        return v;
    else // path compresssion
        return parent[v] = find(parent[v]);
}
void Union(int a, int b){
    a = find(a);
    b = find(b);
    if (a != b){ 
        // union by size
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}
vector<pair<int,int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
class Solution {
public:
    int largestIsland(vector<vector<int>>& v) {
        vector<vector<int>> grid=v;
        int m=v.size(),n=v[0].size();
        map<pair<int,int>,int> mp;
        int k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;++j){
                if(v[i][j]==1){
                    mp[{i,j}]=k++;
                }
            }
        }
        for(int i=0;i<k;i++){
             make(i);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(auto x : dirs){
                        int nx=i+x.first,ny=j+x.second;
                        if(nx>=0 && ny>=0 && nx<m && ny<n && v[nx][ny]==1){
                            int a=mp[{i,j}],b=mp[{nx,ny}];
                            Union(a,b);
                        }
                    }
                }
            }
        }
        int ans=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_map<int,int> fre;
                    for(auto x :dirs){
                        int nx=i+x.first,ny=j+x.second;
                        if(nx>=0 && ny>=0 && nx<m && ny<n && v[nx][ny]==1){
                            int a=mp[{nx,ny}];
                            fre[find(a)]+=1;
                        }
                    }
                    int cnt=1;
                    for(auto x: fre){
                        cnt+=siz[find(x.first)];
                    }
                    ans=max(ans,cnt);
                }
            }
        }
        for(int i=0;i<k;i++)ans=max(ans,siz[i]);
        return ans;
    }
};