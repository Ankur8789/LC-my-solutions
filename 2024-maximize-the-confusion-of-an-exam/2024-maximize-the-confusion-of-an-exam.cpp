class Solution {
public:
    int maxConsecutiveAnswers(string ak, int k) 
    {
        int res=0,i=0,j=0,n=ak.size();
        int ps=0;
        while(j<n)
        {
            if(ak[j]=='F')
                ps++;
            while(ps>k)
            {
                if(ak[i]=='F')
                    ps--;
                i++;
            }
            res=max(res,j-i+1);
            j++;
        }
        i=0;
        j=0;
        ps=0;
        while(j<n)
        {
            if(ak[j]=='T')
                ps++;
            while(ps>k)
            {
                if(ak[i]=='T')
                    ps--;
                i++;
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};