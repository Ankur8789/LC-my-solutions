bool ispresent(unordered_map<char, int> &a, unordered_map<char, int> &b)
{
    for (auto t : a)
    {
        if (t.second > b[t.first])
        {
            return false;
        }
    }
    return true;
}

string res = "";

bool check(int v, string &s, string &t)
{
    unordered_map<char, int> a, b;
    for (int i = 0; i < t.length(); i++)
        a[t[i]]++;
    int i = 0, j = 0, n = s.length();
    while (j < n)
    {
        b[s[j]]++;
        if (j - i + 1 < v)
            j++;
        else if (j - i + 1 == v)
        {
            if (ispresent(a, b))
            {
                res = s.substr(i, v);
                return true;
            }
            b[s[i]]--;
            i++;
            j++;
        }
    }
    return false;
}

class Solution
{
public:
    string minWindow(string s, string t)
    {
        res = "";
        int i = 1, j = s.length();
        if (s.length() < t.length())
            return "";
        if (s.length() == t.length())
        {
            string str = s;
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            if (s == t)
                return str;
            else
                return "";
        }

        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (check(mid, s, t))
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        return res;
    }
};