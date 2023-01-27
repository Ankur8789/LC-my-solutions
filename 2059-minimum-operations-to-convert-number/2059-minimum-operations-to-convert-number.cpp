class Solution {
public:
    // this is the type of bfs sokution that i had to do...glad i found it
   // .......
    //intuition-->agar ko number pahle aaya hua hai...to usko firse operation krne ka koi jrurat nahi hai
    //kyu---> kyuki wo infinite loop me fsega hi fsega.....isiliye think optimally
    typedef long long ll;
    int minimumOperations(vector<int>& nums, int start, int end) 
    {
        unordered_map<ll,ll> mp;
        mp[start]++;
        queue<ll> q;
        q.push(start);
        ll xx=1;
        while(q.size()>0)
        {
            ll sz=q.size();
            while(sz--)
            {
                ll x=q.front();
                q.pop();
                // addition
                for(auto t: nums)
                {
                   ll tmp=x+t;
                    if(tmp==end)
                        return xx;
                    if(tmp>1000 || tmp<0)
                        continue;
                   if(mp.find(tmp)==mp.end())
                   {
                       mp[tmp]++;
                       q.push(tmp);
                   }
                }
                //sub
                for(auto t: nums)
                {
                    ll tmp=x-t;
                    
                    if(tmp==end)
                        return xx;
                    if(tmp>1000 || tmp<0)
                        continue;
                    if(mp.find(tmp)==mp.end())
                    {
                        mp[tmp]++;
                        q.push(tmp);
                    }
                }
                //xor
                for(auto t: nums)
                {
                    ll tmp=x^t;
                    
                    if(tmp==end)
                        return xx;
                    if(tmp>1000 || tmp<0)
                        continue;
                    if(mp.find(tmp)==mp.end())
                    {
                         mp[tmp]++;
                        q.push(tmp);    
                    }
                }
                
            }
            xx++;
        }
        return -1;
    }
};