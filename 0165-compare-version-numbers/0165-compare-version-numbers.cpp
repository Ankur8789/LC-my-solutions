class Solution
{
public:
    int compareVersion(string version1, string version2)
    {

        vector<int> ver1;
        vector<int> ver2;
        for (int i = 0; i < version1.length();)
        {
            long long sum1 = 0;
            while (version1[i] != '.' && i < version1.length())
            {
                int num = version1[i] - '0';
                sum1 = sum1 * 10 + num;
                i++;
            }
            ver1.push_back(sum1);
            i++;
        }
        for (int i = 0; i < version2.length();)
        {
            long long sum2 = 0;
            while (version2[i] != '.' && i < version2.length())
            {
                int num = version2[i] - '0';
                sum2 = sum2 * 10 + num;
                i++;
            }
            ver2.push_back(sum2);
            i++;
        }
        if (ver1.size() < ver2.size())
        {
            while (ver1.size() != ver2.size())
            {
                ver1.push_back(0);
            }
        }
        else
        {
            while (ver2.size() != ver1.size())
            {
                ver2.push_back(0);
            }
        }
        for (int i = 0; i < ver1.size(); i++)
        {
            if (ver1[i] < ver2[i])
                return -1;
            else if (ver1[i] > ver2[i])
                return 1;
            else
                continue;
        }
        return 0;
    }
};