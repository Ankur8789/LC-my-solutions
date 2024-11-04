class Solution {
public:
    string compressedString(string w) {
        int i = 0 , n = w.size();
        string res = "";
        while(i < n){
            char pre = w[i];
            int cnt = 0;
            while(i < n && w[i] == pre && cnt < 9)
                cnt++,i++;
            res += to_string(cnt) + pre;
        }
        return res;
    }
};