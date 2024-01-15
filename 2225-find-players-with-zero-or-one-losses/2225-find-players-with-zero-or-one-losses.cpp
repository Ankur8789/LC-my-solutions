class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        map<int,int> tot,loss;
        for(auto t: matches)
        {
            int a=t[0];
            int b=t[1];
            tot[a]++;
            tot[b]++;
            loss[b]++;
        }
        vector<int> noloss,oneloss;
        for(auto t: tot)
        {
            if(loss.find(t.first)==loss.end())
                noloss.push_back(t.first);
            else if(loss[t.first]==1)
                oneloss.push_back(t.first);     
        }
        return {noloss,oneloss};
    }
};