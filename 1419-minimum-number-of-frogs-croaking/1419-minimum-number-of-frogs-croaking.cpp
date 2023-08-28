class Solution {
public:
    int minNumberOfFrogs(string s) 
    {
        string temp="croak";
        vector<int> freq(5);
        for(auto t:s)
        {
            int idx=temp.find(t);
            // if(idx==-1)return -1;
            if(t=='c')
            {
               freq[0]++;
               if(freq[4]!=0)
               freq[4]--;
            }
            else
            {
                if(freq[idx-1]<=0)
                    return -1;
                freq[idx-1]--;
                freq[idx]++;
            }
        }
        if(freq[0]!=0 || freq[1]!=0 || freq[2]!=0 || freq[3]!=0)
            return -1;
        return freq[4];
        
    }
};