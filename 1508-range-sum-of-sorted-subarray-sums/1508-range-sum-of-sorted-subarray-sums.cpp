class Solution {
public:
    const int mod=1e9+7;
    typedef long long ll;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sum;
        for(int i=0;i<n;i++){
            int ps=0;
            for(int j=i;j<n;j++){
                ps+=nums[j];
                ps%=mod;
                sum.push_back(ps);
            }
        }
        --left;
        --right;
        sort(begin(sum),end(sum));
        int m=sum.size();
        for(int i=1;i<m;i++)
            sum[i]+=sum[i-1],sum[i]%=mod;
        return sum[right]-(left>0?sum[left-1]:0);
    }
};