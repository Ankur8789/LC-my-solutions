class Solution {
public:
    int findComplement(int num) {
        int ans=0,found=false;
        for(int i=31;i>=0;i--){
            if(found){
                if(!((num>>i)&1))
                    ans|=(1<<i);
            }
            else{
                if((num>>i)&1){
                    found=true;
                }
            }
        }
        return ans;
    }
};