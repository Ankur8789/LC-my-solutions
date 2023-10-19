
class Solution
{
public:
    string largestMultipleOfThree(vector<int> &digits)
    {
        string res = "";
        sort(digits.begin(), digits.end());
        reverse(digits.begin(), digits.end());
        int sum = 0;
        for (auto t : digits)
            sum += t;
        map<int, int> mp;
        for (auto t : digits)
            mp[t % 3]++;
        if (sum % 3 == 0)
        {
            string res = "";
            // int zr=0;
            for (auto t : digits)
            {
                res += char(t + '0');
            }
            int zr = 0;
            for (auto t : res)
                zr += (t == '0');
            res = (zr == res.size()) ? "0" : res;
            return res;
        }
        else if (sum % 3 == 1)
        {

            if (mp[1])
            {
                string res = "";
                int idx = digits.size() - 1;
                for (; idx >= 0; idx--)
                {
                    if (digits[idx] % 3 == 1)
                        break;
                    res += char('0' + digits[idx]);
                }
                for (int i = 0; i < idx; i++)
                    res += char('0' + digits[i]);
                sort(res.begin(), res.end());
                reverse(res.begin(), res.end());
                int zr = 0;
                for (auto t : res)
                    zr += (t == '0');
                res = (zr == res.size() && zr != 0) ? "0" : res;
                return res;
                return res;
            }
            else
            {
                if (mp[2] < 2)
                    return "";
                else
                {
                    int cnt = 0;
                    string res = "";
                    int idx = digits.size() - 1;
                    for (; idx >= 0; idx--)
                    {
                        if (digits[idx] % 3 == 2)
                        {
                            cnt++;
                            if (cnt == 2)
                                break;
                        }
                        else
                            res += char(digits[idx] + '0');
                    }
                    for (int i = 0; i < idx; i++)
                        res += char(digits[i] + '0');
                    sort(res.begin(), res.end());
                    reverse(res.begin(), res.end());
                    int zr = 0;
                    for (auto t : res)
                        zr += (t == '0');
                    res = (zr == res.size() && zr != 0) ? "0" : res;
                    return res;
                    return res;
                }
            }
        }
        else
        {
            if (mp[2] >= 1)
            {
                string res = "";
                int cnt = 0;
                int idx = digits.size() - 1;
                for (; idx >= 0; idx--)
                {
                    if (digits[idx] % 3 == 2)
                        break;
                    res += char('0' + digits[idx]);
                }
                for (int i = 0; i < idx; i++)
                    res += char('0' + digits[i]);
                sort(res.begin(), res.end());
                reverse(res.begin(), res.end());
                int zr = 0;
                for (auto t : res)
                    zr += (t == '0');
                res = (zr == res.size() && zr != 0) ? "0" : res;
                return res;
                return res;
            }
            else
            {
                if (mp[1] >= 2)
                {
                    int cnt = 0;
                    string res = "";
                    int idx = digits.size() - 1;
                    for (; idx >= 0; idx--)
                    {
                        if (digits[idx] % 3 == 1)
                        {
                            cnt++;
                            if (cnt == 2)
                                break;
                        }
                        else
                            res += char(digits[idx] + '0');
                    }
                    for (int i = 0; i < idx; i++)
                        res += char(digits[i] + '0');
                    sort(res.begin(), res.end());
                    reverse(res.begin(), res.end());
                    int zr = 0;
                    for (auto t : res)
                        zr += (t == '0');
                    res = (zr == res.size() && zr != 0) ? "0" : res;
                    return res;
                    return res;
                }
                else
                    return "";
            }
        }
    }
};