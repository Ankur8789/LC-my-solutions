class Solution {
public:
    int getWinner(vector<int>& arr, int k) 
    {
        map<int,int> mp;
        int i=0,j=1;
        int n=arr.size();
        while(i<n && j<n)
        {
           if(arr[i]>arr[j])
           {
               j++;
               mp[arr[i]]++;
               if(mp[arr[i]]>=k)
                   return arr[i];
           }
           else
           {
               i=j;
               mp[arr[j]]++;
               if(mp[arr[j]]>=k)
                   return arr[i];
               j++;
           }
        }
        auto it=mp.end();
        it--;
        return it->first;
    }
};