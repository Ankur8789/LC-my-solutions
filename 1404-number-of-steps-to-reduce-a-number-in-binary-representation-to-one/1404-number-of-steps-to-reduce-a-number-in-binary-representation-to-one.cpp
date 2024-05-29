class Solution
{
public:
    int numSteps(string s)
    {
        int n;
        int last = s.size() - 1;
        int opr = 0;
        if (s == "1")
        {
            return 0;
        }
        while (true)
        {
            n = last;
            if (s[n] == '0')
            {
                last--;
            }
            else
            {
                while (n >= 0 && s[n] == '1')
                {
                    s[n] = '0';
                    n--;
                }
                if (n < 0)
                {
                    s = '1' + s;
                    last++;
                }
                else
                {
                    s[n] = '1';
                }
            }
            opr++;
            if (last == 0)
            {
                break;
            }
        }
        return opr;
    }
};