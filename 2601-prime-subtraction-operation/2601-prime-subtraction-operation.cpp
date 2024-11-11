vector<bool> soe(1005, 1);
void sieve(){
    for (int i = 2; i * i <= 1004; i++){
        if (soe[i] == true){
            for (int j = i * i; j <= 1004; j += i)
                soe[j] = false;
        }
    }
}
int find(vector<int>& primes,int val){
    int l=0,r=primes.size()-1,res=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(primes[mid]<val){
            res=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return res;
}
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        sieve();
        vector<int> primes;
        for(int i=2;i<1005;i++){
            if(soe[i])
                primes.push_back(i);
        }
        int n=nums.size();
        if(n==1)
            return 1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>=nums[i+1]){
                int index=find(primes,nums[i]);
                if(index==-1)
                    return 0;
                int l=0,r=index,res=-1;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(nums[i]-nums[i+1]<primes[mid]){
                        res=mid;
                        r=mid-1;
                    }
                    else{
                        l=mid+1;
                    }
                }
                if(res==-1)
                    return 0;
                nums[i]-=primes[res];
            }
        }
        // for(int i=0;i<n;i++)
        //     cout<<nums[i]<<" ";
        cout<<endl;
        return 1;
    }
};