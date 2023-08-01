class Solution {
public:
    vector<vector<int>> res;
    void f(int i,int k,vector<int>& v,vector<int>& temp)
    {
        if(k==0)
        {
            res.push_back(temp);
            return ;
        }
        if(i==v.size())
            return;
        temp.push_back(v[i]);
        f(i+1,k-1,v,temp);
        temp.pop_back();
        f(i+1,k,v,temp);
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> v;
        for(int i=1;i<=n;i++)
            v.push_back(i);
        vector<int> temp;
        f(0,k,v,temp);
        return res;
    }
};