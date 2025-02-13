class Solution {
public:
    char findKthBit(int n, int k) {
       string s = "0";
        while (true) {
            if (k <= s.size())
                return s[k - 1];
            auto ss = s;
            reverse(begin(ss), end(ss));
            for (auto &ch : ss)
                ch = ch == '0' ? '1' : '0';
            s += "1" + ss;
        }
        return '0';
    }
};