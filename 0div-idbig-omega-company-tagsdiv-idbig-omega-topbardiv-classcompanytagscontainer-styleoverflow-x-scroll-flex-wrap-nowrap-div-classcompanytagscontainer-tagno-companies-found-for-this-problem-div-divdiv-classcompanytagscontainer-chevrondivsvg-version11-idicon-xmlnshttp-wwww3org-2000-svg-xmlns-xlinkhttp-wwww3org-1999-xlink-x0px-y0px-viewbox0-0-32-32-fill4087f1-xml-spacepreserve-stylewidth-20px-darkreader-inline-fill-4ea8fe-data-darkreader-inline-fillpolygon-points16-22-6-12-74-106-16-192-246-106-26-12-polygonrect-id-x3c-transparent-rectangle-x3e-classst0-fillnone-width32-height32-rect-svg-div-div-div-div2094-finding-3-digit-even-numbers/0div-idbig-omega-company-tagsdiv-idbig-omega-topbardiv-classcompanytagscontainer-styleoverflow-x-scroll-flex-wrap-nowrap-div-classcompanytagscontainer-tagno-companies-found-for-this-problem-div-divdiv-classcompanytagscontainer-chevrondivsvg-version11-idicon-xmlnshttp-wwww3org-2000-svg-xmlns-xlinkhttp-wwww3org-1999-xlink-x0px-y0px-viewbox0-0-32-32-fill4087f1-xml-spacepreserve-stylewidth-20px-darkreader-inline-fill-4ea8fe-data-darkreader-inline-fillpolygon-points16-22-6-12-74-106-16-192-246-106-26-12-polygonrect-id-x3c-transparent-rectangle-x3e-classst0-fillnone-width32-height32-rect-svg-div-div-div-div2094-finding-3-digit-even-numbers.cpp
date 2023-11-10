class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) 
    {
        vector<int> freq(10);
        for(auto t: digits)
            freq[t]++;
        vector<int> ans;
        for(int c=0;c<=9;c++)
        {
            for(int b=0;b<=9;b++)
            {
                for(int a=1;a<=9;a++)
                {
                    // abc
                    if(c&1)
                        continue;
                    if(freq[a]==0 || freq[b]==0 || freq[c]==0)
                        continue;
                    if(a==b && b==c)
                    {
                        if(freq[a]>=3)
                        {
                            int rem=a*100+b*10+c;
                            ans.push_back(rem);
                        }
                    }
                    else if(a==b && b!=c)
                    {
                        if(freq[a]>=2 && freq[c]>0)
                        {
                            int rem=a*100+b*10+c;
                            ans.push_back(rem);  
                        }
                    }
                    else if(b==c && a!=b)
                    {
                       if(freq[a]>0 && freq[b]>=2)
                       {
                          int rem=a*100+b*10+c;
                          ans.push_back(rem);  
                       }
                    }
                    else if(a==c && a!=b)
                    {
                        if(freq[a]>=2 && freq[b]>0)
                        {
                          int rem=a*100+b*10+c;
                          ans.push_back(rem);  
                        }
                    }
                    else
                    {
                        if(freq[a]>0 && freq[b]>0 && freq[c]>0)
                        {
                            int rem=a*100+b*10+c;
                            ans.push_back(rem); 
                        }
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};