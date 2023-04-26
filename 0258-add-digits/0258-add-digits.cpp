class Solution {
public:
    int addDigits(int num) 
    {
        while(to_string(num).size()>1)
        {
            int sum=0;
            while(num>0)
            {
               int d=num%10;
                sum+=d;
                num/=10;
            }
            num=sum;
        }
      return num;
    }
};