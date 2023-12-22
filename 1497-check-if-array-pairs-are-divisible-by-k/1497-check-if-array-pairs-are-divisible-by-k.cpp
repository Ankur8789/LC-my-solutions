class Solution {
public:
    bool canArrange(vector<int>& arr, int k)
    {
        map<int,int> mp;
        int cnt=0;
        for(int i=0;i<arr.size();i++)
        {
            arr[i]%=k;
            if(arr[i]<0)
                arr[i]+=k;
        }
        int zr=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0)
                {zr++;continue;}
            int req=k-arr[i];
            if(mp.find(req)!=mp.end())
            {
                cnt++;
                mp[req]--;
                if(mp[req]==0)
                    mp.erase(req);
            }
            else
            {
                mp[arr[i]]++;
            }
        }
        if(zr&1)return false;
        int left=arr.size()-2*cnt-zr;
        if(left<=zr)
        {
             zr-=left;
             if(zr&1)
                 return false;
             else
                 return true;
        }
        else
            return false;
        
    }
};