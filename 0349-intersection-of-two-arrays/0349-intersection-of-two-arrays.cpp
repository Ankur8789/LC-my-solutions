class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
       map<int,int> m1,m2;
       for(auto t: nums1)
           m1[t]+=1;
       vector<int> ans;
       for(auto t: nums2)
       {
           if(m1.find(t)!=m1.end())
           {
               if(m2.find(t)==m2.end())
                   ans.push_back(t);
               m2[t]+=1;
           }
       }
        return ans;
    }
};