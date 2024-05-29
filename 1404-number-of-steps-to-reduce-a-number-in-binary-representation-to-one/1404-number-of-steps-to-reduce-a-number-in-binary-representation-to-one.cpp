class Solution
{
public:
    int numSteps(string s)
    {
        int cnt = 0;
        while (s.length() > 1)
        {
            cnt++;
            int n = s.length();
            if (s[n - 1] == '0')
                s.pop_back();
            else
            {
                int carr = 1;
                s[n - 1] = '0';
                for (int i = n - 2; i >= 0; i--)
                {
                    if (carr)
                    {
                        if (s[i] == '1')
                        {
                            s[i] = '0';
                            carr = 1;
                        }
                        else
                        {
                            s[i] = '1';
                            carr = 0;
                        }
                    }
                }
                if (carr)
                    s = '1' + s;
            }
        }
        return cnt;
    }
};