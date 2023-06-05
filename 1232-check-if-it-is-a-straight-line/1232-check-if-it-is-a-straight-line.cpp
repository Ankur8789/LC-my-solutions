class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        unordered_map<double,int> mp;
        for(int i=0;i<coordinates.size()-1;i++)
        {
            double num=coordinates[i][0]-coordinates[i+1][0];
            double den=coordinates[i][1]-coordinates[i+1][1];
            if(den==0)
                mp[INT_MAX]++;
            else
                mp[(num/den)]++;
        }
        return mp.size()==1;
    }
};