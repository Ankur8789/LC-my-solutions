class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
       vector<int> temp=score;
       sort(begin(score),end(score));
       reverse(begin(score),end(score));
       int cnt=1;
       vector<string> ans;
       map<int,string> mp;
       for(auto x:score)
       {
           if(cnt<=3)
           {
               if(cnt==1)
                   mp[x]="Gold Medal";
               else if(cnt==2)
                   mp[x]="Silver Medal";
               else
                   mp[x]="Bronze Medal";
           }
           else
               mp[x]=to_string(cnt);
           cnt++;
       }
       for(auto x:temp)
           ans.push_back(mp[x]);
       return ans;
    }
};