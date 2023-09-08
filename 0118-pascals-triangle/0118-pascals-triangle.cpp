class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {   vector<vector<int>> ans;
      
        vector<int> temp;
        temp.push_back(1);
     ans.push_back(temp);
     temp.clear();
      int count=2;int k=0;
     for(int i=1;i<numRows;i++)
     {
         for(int j=0;j<count;j++)
         {
             if(j==0 || j==count-1)
                 temp.push_back(1);
             else
                 temp.push_back(ans[k][j-1]+ans[k][j]);
                 
         }
         ans.push_back(temp);
         temp.clear();
         k++;
         count++;
         
     }
        return ans;
    }
};