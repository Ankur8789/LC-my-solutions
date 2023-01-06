class Solution {
public:
     static bool cmp(string& a,string& b)
     {
         if(a.length()!=b.length())
             return a.length()<b.length();
          if(a.length()==b.length())
          {
              for(int i=0;i<a.length();i++)
              {
                  if(a[i]-'0'<b[i]-'0')
                      return a<b;
                      
              }
          }
         return false;
     }
    string kthLargestNumber(vector<string>& nums, int k) 
    {
       sort(nums.begin(),nums.end(),cmp);
        reverse(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
            cout<<nums[i]<<" ";
        return nums[k-1];
    }
};