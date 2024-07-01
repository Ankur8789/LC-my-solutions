class Solution {
public:
    
    
    
    void solve(int i ,int k , vector<int> &v, int &ans)
    {
        if(v.size()==1)
        {
            ans = v[0];
            return;
        }
        
        
        i = (i+k)%v.size();
        v.erase(v.begin() + i);        
        
        solve( i, k , v ,ans);
        
    }
    
    int findTheWinner(int n, int k) {
        
    vector<int> v(n,0);
    
    for(int i =0; i<n; i++) v[i] = i+1;
    k--;
    
    int ans;
    
    solve(0,k,v,ans);
    return ans;
        
    }
};