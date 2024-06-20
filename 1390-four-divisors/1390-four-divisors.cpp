class Solution {
public:
    int sumFourDivisors(vector<int>& nums) 
    {
       int sum=0;
       for(auto x: nums)
       {
           int cc=0,ps=0;
           for(int i=1;i*i<=x;i++)
           {
               if(x%i==0)
               {
                   cc++;
                   ps+=i;
                   if(x/i!=i)
                       cc++,ps+=x/i;
               }
           }
           if(cc==4)
               sum+=ps;
       }
        return sum;
    }
};