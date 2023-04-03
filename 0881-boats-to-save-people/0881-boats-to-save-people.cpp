class Solution {
public:
    int numRescueBoats(vector<int>& pe, int lt) 
    {
        sort(pe.begin(),pe.end());
        int i=0,j=pe.size()-1;
        int cc=0;
        while(i<=j)
        {
            if(i==j)
            {
               cc++;
               break;
            }
            if(pe[j]+pe[i]>lt)
            {
                cc++;
                j--;
            }
            else
            {
                cc++;
                i++;
                j--;
            }
            
        }
        return cc;
    }
};