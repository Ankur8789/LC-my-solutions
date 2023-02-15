class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> knum;
        while(k != 0){
            knum.push_back(k % 10);
            k /= 10;
        }
        int carry = 0;
        reverse(num.begin(), num.end());
        if(knum.size()>num.size())swap(knum, num);
        vector<int> ans;
        for(int i=0; i<num.size(); i++){
            int sum = carry + num[i] + (i<knum.size()? knum[i] : 0);
            ans.push_back(sum%10);
            carry = sum /10;
        }
        if(carry>0)ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};