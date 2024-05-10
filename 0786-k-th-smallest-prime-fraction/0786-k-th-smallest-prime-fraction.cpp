class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) 
    {
       vector<pair<double,pair<int,int>>> vp;
       int n=arr.size();
       for(int i=0;i<n;i++)
       {
           for(int j=i+1;j<n;j++)
           {
               double ref=(double)arr[i]/(double)arr[j];
               vp.push_back({ref,{arr[i],arr[j]}});
           }
       }
       sort(begin(vp),end(vp));
       vector<int> ans;
       for(int i=0;i<vp.size();i++)
       {
           // cout<<vp[i].first<<" "<<vp[i].second.first<<" "<<vp[i].second.second<<endl;
           if(i==k-1)
           {
               ans.push_back(vp[i].second.first);
               ans.push_back(vp[i].second.second);
           }
       }
       return ans;
    }
};