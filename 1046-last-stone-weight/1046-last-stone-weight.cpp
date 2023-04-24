class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
      priority_queue<int> pq;
        for(auto t: stones)
            pq.push(t);
        while(pq.size()>1)
        {
            int val1=pq.top();
            pq.pop();
            int val2=pq.top();
            pq.pop();
            if(val1==val2)
                continue;
            else
                pq.push(abs(val1-val2));
        }
        if(pq.size()==1)
        return pq.top();
        else
            return 0;
    }
};