class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        int l=0;
        int n=tem.size();
        vector<int> ans(n,0);
        for(int i=n-2;i>=0;i--){
            int j=i+1;
            while(true){
                if(tem[j]>tem[i]){ 
                    ans[i]=j-i;
                    break;
                }
                if(tem[j]==tem[i]){
                    if(ans[j]==0)
                        ans[i]=0;
                    else
                        ans[i]=ans[j]+j-i;
                    
                    break;
                }

                if(tem[j]<tem[i] && ans[j]==0)
                    break;
                
                if(tem[j]<tem[i]){
                    j+=ans[j];
                }
                    
                
            }

        }
        return ans;
    }
};