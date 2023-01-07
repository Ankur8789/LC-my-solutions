class Solution {
public:
    
    int maximumScore(int a, int b, int c) 
    {
       priority_queue<int> pq;
       pq.push(a);
        pq.push(b);
        pq.push(c);
        int cnt=0;
        while(1)
        {
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            int z=pq.top();
            pq.pop();
            if((x==0 && y==0) || (x==0 && z==0 ) || (y==0 && z==0))
                break;
            x--;
            y--;
            cnt++;
            pq.push(x);
            pq.push(y);
            pq.push(z);
            
        }
        return cnt;
    }
};