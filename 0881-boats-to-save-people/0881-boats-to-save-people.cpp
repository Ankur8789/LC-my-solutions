class Solution {
public:
    int numRescueBoats(vector<int>& pe, int lt) 
    {
       sort(pe.begin() , pe.end());
       int cnt = 0;
       int i = 0, j = 0;
       int n = pe.size();
       j = n-1;
       while(i <= j)
       {
           if(i == j)
           {
               cnt++;
               break;
           }
           if(pe[i] + pe[j] <= lt)
           {
               cnt++;
               i++;
               j--;
           }
           else
           {
               cnt++;
               j--;
           }
       }
        return cnt;
       
    }
};