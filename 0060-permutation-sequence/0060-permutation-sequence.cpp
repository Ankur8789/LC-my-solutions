class Solution {
public:
    string getPermutation(int n, int k) {
        string res="";
        vector<int> fac(10);
        fac[0]=1,fac[1]=1;
        for(int i=2;i<10;i++)
            fac[i]=fac[i-1]*i;
        vector<int> taken(10);
        for(int i=0;i<n;i++){
            char last='0';
            int cost=0;
            for(char c='1';c<=char(n+'0');c++){
                int val=fac[n-i-1];
                if(taken[c-'0'])
                    continue;
                  cost+=val;
                  last=c;
                if(cost>=k){
                    k-=cost-val;
                    break;
                }
            }
            taken[last-'0']=1;
            res+=last;
        }
        return res;
    }
};