class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& bc) 
    {
        unordered_map<int,int> mp;
        int n=bc.size();
        priority_queue<pair<int,int>> pq;
        vector<int> ans(n);
        for(auto t:bc)
            mp[t]++;
        for(auto t: mp)
        {
           pq.push({t.second,t.first}); 
        }
        int pre=-1;
        for(int i=0;i<bc.size();i++)
        {
            pair<int,int> p1=pq.top();
            pq.pop();
            if(pq.size()==0)
            {
               ans[i]=p1.second;
               p1.first--;
                pre=p1.second;
               if(p1.first>0)
                   pq.push(p1);
               // pq.push(p2); 
                continue;
            }
            pair<int,int> p2=pq.top();
            pq.pop();
            if(pre==p1.second)
            {
               ans[i]=p2.second;
               p2.first--;
                pre=p2.second;
               if(p2.first>0)
                   pq.push(p2);
                pq.push(p1);
            }
            else
            {
                ans[i]=p1.second;
               p1.first--;
                pre=p1.second;
               if(p1.first>0)
                   pq.push(p1);
                pq.push(p2);
            }
            
            
        }
        return ans;
    }
};