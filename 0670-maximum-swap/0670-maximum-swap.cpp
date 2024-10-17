class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int maxi= num;
        int n = s.size();
        if(n == 1){
            return num;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(s[i],s[j]);
                int val=stoi(s);
                maxi=max(maxi,val);
                swap(s[i],s[j]);
            }
        }
        return maxi;
    }
};