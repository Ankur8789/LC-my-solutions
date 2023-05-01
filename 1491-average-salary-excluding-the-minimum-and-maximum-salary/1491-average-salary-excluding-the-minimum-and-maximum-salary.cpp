class Solution {
public:
    double average(vector<int>& salary) 
    {
       int n=salary.size();
       double sum=0;
        sort(salary.begin(),salary.end());
        for(auto t: salary)
            sum+=t;
        sum-=salary[0];
        sum-=salary[n-1];
        return sum/(n-2);
    }
};