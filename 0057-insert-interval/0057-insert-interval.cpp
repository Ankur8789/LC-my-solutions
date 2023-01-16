class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& it, vector<int>& nit) 
    {
        it.push_back(nit);
        sort(it.begin(),it.end());
        int k=0;
        vector<vector<int>> ans;
        ans.push_back(it[0]);
        for(int i=0;i<it.size();i++)
        {
            if(ans[k][1]>=it[i][0])
            {
                ans[k][1]=max(it[i][1],ans[k][1]);
            }
            else
            {
                ans.push_back(it[i]);
                k++;
            }   
                
        }
        return ans;
    }
};