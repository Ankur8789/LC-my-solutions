class Solution
{
public:
    int max(int a, int b)
    {
        if (a > b)
            return a;
        else
            return b;
    }
    int f(int i, vector<string> &arr, int last, int st, int mask)
    {
        if (i == arr.size())
            return 0;
        int ans = 0;
        if (st)
        {
            bool ok = true;
            int tmask = mask;
            string curr = arr[i];
            for (auto t : curr)
            {
                if ((tmask >> (t - 'a')) & 1)
                {
                    ok = false;
                    break;
                }
                else
                    tmask |= (1 << (t - 'a'));
            }
            if (ok)
                ans = max(ans, arr[i].size() + f(i + 1, arr, curr.back() - 'a', st ^ 1, tmask));
            ans = max(ans, f(i + 1, arr, last, st, mask));
        }
        else
        {
            string curr = arr[i];
            string pre = arr[i - 1];
            bool ok = true;
            int tmask = mask;
            for (auto t : curr)
            {
                if ((tmask >> (t - 'a')) & 1)
                {
                    ok = false;
                    break;
                }
                else
                    tmask |= (1 << (t - 'a'));
            }
            if (ok)
                ans = max(ans, curr.size() + f(i + 1, arr, curr.back() - 'a', st, tmask));
            ans = max(ans, f(i + 1, arr, last, st, mask));
        }
        return ans;
    }
    int maxLength(vector<string> &arr)
    {
        int ans = f(0, arr, 0, 1, 0);
        return ans;
    }
};