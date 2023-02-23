class Solution {
public:
  
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        vector<pair<int,int>> vp;
        for(int i=0;i<profits.size();i++)
            vp.push_back({capital[i],profits[i]});
        int x=0;
        sort(vp.begin(),vp.end());
        priority_queue<int> pq;
        while(k--)
        {
            while(x<profits.size() && vp[x].first<=w)
            {
                pq.push(vp[x].second);
                x++;
            }
            if(pq.size()==0)
                break;
            w+=pq.top();
            pq.pop();
            
        }
        return w;
    }
};