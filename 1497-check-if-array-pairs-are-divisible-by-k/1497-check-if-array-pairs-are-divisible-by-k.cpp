class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> vec(k);
        if(k==1)
            return true;
        for(auto& x: arr){
            while(x<0)
                x+=k;
            vec[x%k]+=1;
        }
        int left=0;
        for(int i=1;i<=(k+1)/2;i++){
            if(i==(k+1)/2){
                if(vec[i]&1)
                    return false;
                continue;
            }
            int x=vec[i],y=vec[k-i];
            vec[i]-=min(x,y);
            vec[k-i]-=min(x,y);
            left+=vec[i]+vec[k-i];
        }
        if(vec[0]>=left){
            vec[0]-=left;
            if(vec[0]&1)
                return false;
            else
                return true;
        }
        else{
            return false;
        }
    }
};