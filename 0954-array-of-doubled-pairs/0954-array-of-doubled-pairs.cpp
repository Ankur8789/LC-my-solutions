class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) 
    {
        multiset<int> ms;
        int n=arr.size();
        for(auto t: arr)
            ms.insert(t);
        int cnt=0;
        while(ms.size()>0)
        {
            int val=*ms.begin();
            ms.erase(ms.begin());
            if(val<0)
            {
                if(val%2!=0 || ms.find(val/2)==ms.end())
                    break;
                ms.erase(ms.find(val/2));
            }
            else
            {
                if(ms.find(val*2)==ms.end())
                    break;
                ms.erase(ms.find(2*val));
            }
            
            cnt+=2;
        }
        return (ms.size()==0);
        
    }
};