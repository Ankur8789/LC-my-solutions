class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        int n=p.size();
        for(int i=0;i<n;i++){
            int res=0;
            for(int j=i+1;j<n;j++){
                if(p[j]<=p[i]){
                    res=p[j];
                    break;
                }
            }
            p[i]-=res;
        }
        return p;
    }
};